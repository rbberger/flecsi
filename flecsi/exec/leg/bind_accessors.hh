/*
    @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
   /@@/////  /@@          @@////@@ @@////// /@@
   /@@       /@@  @@@@@  @@    // /@@       /@@
   /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
   /@@////   /@@/@@@@@@@/@@       ////////@@/@@
   /@@       /@@/@@//// //@@    @@       /@@/@@
   /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
   //       ///  //////   //////  ////////  //

   Copyright (c) 2016, Triad National Security, LLC
   All rights reserved.
                                                                              */
#pragma once

#include <flecsi-config.h>

#include "flecsi/data/field.hh"
#include "flecsi/exec/leg/future.hh"
#include "flecsi/util/array_ref.hh"
#include "flecsi/util/demangle.hh"

#if !defined(FLECSI_ENABLE_LEGION)
#error FLECSI_ENABLE_LEGION not defined! This file depends on Legion!
#endif

#include <legion.h>

#include <memory>

namespace flecsi {
/// \addtogroup legion-execution
/// \{

inline flog::devel_tag bind_accessors_tag("bind_accessors");

namespace exec::leg {

/*!
  The bind_accessors type is called to walk the user task arguments inside of
  an executing legion task to properly complete the users accessors, i.e., by
  pointing the accessor \em view instances to the appropriate legion-mapped
  buffers.

  This is the other half of the wire protocol implemented by \c task_prologue.
 */
template<task_processor_type_t ProcessorType>
struct bind_accessors {

  bind_accessors(Legion::Runtime * legion_runtime,
    Legion::Context & legion_context,
    std::vector<Legion::PhysicalRegion> const & regions,
    std::vector<Legion::Future> const & futures)
    : legion_runtime_(legion_runtime), legion_context_(legion_context),
      regions_(regions), futures_(futures) {}

  template<class A>
  void operator()(A & a) {
    std::apply([&](auto &... aa) { (visit(aa), ...); }, a);
  }

private:
  auto visitor() {
    return
      [&](auto & p, auto &&) { visit(p); }; // Clang 8.0.1 deems 'this' unused
  }

  // All accessors are handled in terms of their underlying raw accessors.

  template<typename DATA_TYPE, Privileges PRIVILEGES>
  void visit(data::accessor<data::raw, DATA_TYPE, PRIVILEGES> & accessor) {
    auto & reg = regions_[region++];

    const Legion::UnsafeFieldAccessor<DATA_TYPE,
      2,
      Legion::coord_t,
      Realm::AffineAccessor<DATA_TYPE, 2, Legion::coord_t>>
      ac(reg, accessor.field(), sizeof(DATA_TYPE));
    const auto dom = legion_runtime_->get_index_space_domain(
      legion_context_, reg.get_logical_region().get_index_space());
    const auto r = dom.get_rect<2>();

    if(!dom.empty())
      accessor.bind(
        util::span(ac.ptr(Legion::Domain::DomainPointIterator(dom).p),
          r.hi[1] - r.lo[1] + 1));
  }

  template<class P>
  std::enable_if_t<std::is_base_of_v<data::send_tag, P>> visit(P & p) {
    p.send(visitor());
  }

  /*--------------------------------------------------------------------------*
   Futures
   *--------------------------------------------------------------------------*/
  template<typename DATA_TYPE>
  void visit(future<DATA_TYPE> & f) {
    f = {futures_[future_id++]};
  }

  // Note: due to how visitor() is implemented above the first
  // parameter can not be 'const &' here, otherwise template/overload
  // resolution fails (silently).
  template<typename T>
  static void visit(data::detail::scalar_value<T> & s) {
    if constexpr(ProcessorType == exec::task_processor_type_t::toc) {
#if defined(__NVCC__) || defined(__CUDACC__)
      cudaMemcpy(s.host, s.device, sizeof(T), cudaMemcpyDeviceToHost);
      return;
#elif defined(__HIPCC__)
      HIP_ASSERT(hipMemcpy(s.host, s.device, sizeof(T), hipMemcpyDeviceToHost));
      return;
#else
      flog_assert(false, "Cuda should be enabled when using toc task");
#endif
    }
    *s.host = *s.device;
  }

  /*--------------------------------------------------------------------------*
    Non-FleCSI Data Types
   *--------------------------------------------------------------------------*/

  template<typename DATA_TYPE>
  static
    typename std::enable_if_t<!std::is_base_of_v<data::bind_tag, DATA_TYPE>>
    visit(DATA_TYPE &) {
    {
      flog::devel_guard guard(bind_accessors_tag);
      flog_devel(info) << "No setup for parameter of type "
                       << util::type<DATA_TYPE>() << std::endl;
    }
  } // visit

  Legion::Runtime * legion_runtime_;
  Legion::Context & legion_context_;
  size_t region = 0;
  const std::vector<Legion::PhysicalRegion> & regions_;
  size_t future_id = 0;
  const std::vector<Legion::Future> & futures_;

}; // struct bind_accessors

/// \}
} // namespace exec::leg
} // namespace flecsi
