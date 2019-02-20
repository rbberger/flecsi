/*
    @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
   /@@/////  /@@          @@////@@ @@////// /@@
   /@@       /@@  @@@@@  @@    // /@@       /@@
   /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
   /@@////   /@@/@@@@@@@/@@       ////////@@/@@
   /@@       /@@/@@//// //@@    @@       /@@/@@
   /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
   //       ///  //////   //////  ////////  //

   Copyright (c) 2016, Los Alamos National Security, LLC
   All rights reserved.
                                                                              */
#pragma once

/*! @file */

#if !defined(__FLECSI_PRIVATE__)
  #error Do not inlcude this file directly!
#endif

namespace flecsi {
namespace execution {

struct mpi_context_policy_t {

  /*!
    Documnetation for this interface is in the top-level context type.
   */

  int start(int argc, char ** argv);

  /*
    Documnetation for this interface is in the top-level context type.
   */

  static size_t task_depth() {
    return 0;
  } // task_depth

  /*
    Documnetation for this interface is in the top-level context type.
   */

  size_t color() const {
    return color_;
  }

  /*
    Documnetation for this interface is in the top-level context type.
   */

  void set_color(size_t color) {
    color_ = color;
  }

  /*
    Documnetation for this interface is in the top-level context type.
   */

  size_t colors() const {
    return colors_;
  }

  /*
    Documnetation for this interface is in the top-level context type.
   */

  void set_colors(size_t colors) {
    colors_ = colors;
  }

  //--------------------------------------------------------------------------//
  // Reduction interface.
  //--------------------------------------------------------------------------//

  /*!
    Return the map of registered reduction types.
   */

  std::map<size_t, MPI_Datatype> & reduction_types() {
    return reduction_types_;
  } // reduction_types

  /*!
    Return the map of registered reduction operations.
   */

  std::map<size_t, MPI_Op> & reduction_operations() {
    return reduction_ops_;
  } // reduction_types

private:
  /*--------------------------------------------------------------------------*
    Runtime data members.
   *--------------------------------------------------------------------------*/

  size_t color_ = std::numeric_limits<size_t>::max();
  size_t colors_ = std::numeric_limits<size_t>::max();

  /*--------------------------------------------------------------------------*
    Reduction data members.
   *--------------------------------------------------------------------------*/

  std::map<size_t, MPI_Datatype> reduction_types_;
  std::map<size_t, MPI_Op> reduction_ops_;

}; // struct mpi_context_policy_t

} // namespace execution
} // namespace flecsi
