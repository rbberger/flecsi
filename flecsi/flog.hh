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

#if defined(FLECSI_ENABLE_FLOG)
#include "flecsi/log/message.hh"
#include "flecsi/log/severity.hh"
#include "flecsi/log/tag_scope.hh"
#endif

#include "flecsi/log/utils.hh"

#include <iostream>
#include <map>
#include <sstream>
#include <unordered_set>
#include <vector>

#include <unistd.h>

#if defined(FLECSI_ENABLE_FLOG)

namespace flecsi {
namespace flog {
/// \defgroup flog Logging
/// Configurable, parallel logging.
/// \{

namespace detail {
template<class, class = void>
struct stream;
template<class T>
std::ostream &
put(std::ostream & o, const T & t, std::string indt = "") {
  stream<T>::put(o, t, indt);
  return o;
}

template<class T>
struct stream<T,
  decltype(void(std::declval<std::ostream &>() << std::declval<const T &>()))> {
  static void put(std::ostream & o, const T & t, std::string indt = "") {
    o << indt << t;
  }
};
template<class T, std::size_t N>
struct stream<std::array<T, N>> {
  static void
  put(std::ostream & o, std::array<T, N> const & c, std::string indt = "") {
    std::size_t i{0};
    o << indt << "<";
    for(auto & t : c) {
      o << t;
      if(++i < c.size())
        o << ", ";
    }
    o << ">";
  }
};
template<template<typename, typename> typename C, typename T, typename A>
struct stream<C<T, A>> {
  static void put(std::ostream & o, C<T, A> const & c, std::string indt = "") {
    std::size_t i{0};
    for(auto & t : c)
      detail::put(o << indt << i++ << ":\n", t, indt + "  ") << '\n';
  }
};
template<typename K, typename V>
struct stream<std::map<K, V>> {
  static void
  put(std::ostream & o, const std::map<K, V> & m, std::string indt = "") {
    for(auto & [k, v] : m)
      detail::put(detail::put(o, k) << ":\n", v, indt + "  ") << '\n';
  }
};
template<typename K, typename V>
struct stream<std::unordered_map<K, V>> {
  static void put(std::ostream & o,
    const std::unordered_map<K, V> & m,
    std::string indt = "") {
    for(auto & [k, v] : m)
      detail::put(detail::put(o, k) << ":\n", v, indt + "  ") << '\n';
  }
};
template<typename T>
struct stream<std::unordered_set<T>> {
  static void put(std::ostream & o,
    const std::unordered_set<T> & s,
    std::string indt = "") {
    o << "{";
    for(auto & e : s)
      detail::put(o << "\n", e, indt + "  ");
    o << "\n}";
  }
};
} // namespace detail

struct guard;

/*!
  Create a tag group to enable/disable output using guards.

  @param label The name of the tag.
 */

struct tag {
  friend guard;

  tag(const char * label) : label_(label) {
    state::instance().register_tag(label);
  }

private:
  std::string label_;
}; // struct tag

/*!
  Create a guard to control output of flog output within the scope of the
  guard.

  @param t The tag group that should enable/disable output.
 */

struct guard {
  guard(tag const & t)
    : scope_(state::instance().lookup_tag(t.label_.c_str())) {}

private:
  tag_scope_t scope_;
}; // struct guard

#if defined(FLOG_ENABLE_DEVELOPER_MODE)
using devel_tag = tag;
using devel_guard = guard;
#else
struct devel_tag {
  devel_tag(const char *) {}
};
struct devel_guard {
  devel_guard(devel_tag const &) {}
};
#endif

/*!
  Add an output stream to FLOG.

  @param label    An identifier for the stream. This can be used to access or
                  update an output stream after it has been added.
  @param stream   The output stream to add.
  @param colorize Indicates whether the output to this stream should be
                  colorized. It is useful to turn colorization off for
                  non-interactive output (default).
 */

inline void
add_output_stream(std::string const & label,
  std::ostream & stream,
  bool colorize = false) {
  state::instance().config_stream().add_buffer(label, stream, colorize);
} // add_output_stream

/*
  Convenience functions for output of some standard container types.
  Use at your own risk.
 */

template<class T>
struct container {
  container(const T & t) : t(t) {}
  friend std::ostream & operator<<(std::ostream & o, const container & c) {
    return detail::put(o, c.t);
  }

private:
  const T & t;
};

/// \}
} // namespace flog
} // namespace flecsi

/// \addtogroup flog
/// \{

/*!
  This handles all of the different logging modes for the insertion
  style logging interface.

  @param severity The severity level of the log entry.

  @b Usage
  @code
  int value{20};

  // Print the value at info severity level
  flog(info) << "Value: " << value << std::endl;

  // Print the value at warn severity level
  flog(warn) << "Value: " << value << std::endl;
  @endcode
 */

#define flog(severity)                                                         \
  true && /* implicitly converts remainder to bool */                          \
    ::flecsi::flog::message<flecsi::flog::severity>(__FILE__, __LINE__).format()

#if defined(FLOG_ENABLE_DEVELOPER_MODE)

#define flog_devel(severity)                                                   \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  true &&                                                                      \
    ::flecsi::flog::message<flecsi::flog::severity>(__FILE__, __LINE__, true)  \
      .format()

#else

#define flog_devel(severity)                                                   \
  if(true) {                                                                   \
  }                                                                            \
  else                                                                         \
    std::cerr

#endif // FLOG_ENABLE_DEVELOPER_MODE

/*!
  Method style interface for trace level severity log entries.

  @param stream The stream to be printed.

  @b Usage
  @code
  int value{20};

  // Print the value at trace severity level
  flog_trace("Value: " << value);
  @endcode
 */

#define flog_trace(stream)                                                     \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  ::flecsi::flog::message<flecsi::flog::trace>(__FILE__, __LINE__).format()    \
    << stream

/*!
  Method style interface for info level severity log entries.

  @param stream The stream to be printed.

  @b Usage
  @code
  int value{20};

  // Print the value at info severity level
  flog_info("Value: " << value);
  @endcode
 */

#define flog_info(stream)                                                      \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  ::flecsi::flog::message<flecsi::flog::info>(__FILE__, __LINE__).format()     \
    << stream

/*!
  Method style interface for warn level severity log entries.

  @param stream The stream to be printed.

  @b Usage
  @code
  int value{20};

  // Print the value at warn severity level
  flog_warn("Value: " << value);
  @endcode
 */

#define flog_warn(stream)                                                      \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  ::flecsi::flog::message<flecsi::flog::warn>(__FILE__, __LINE__).format()     \
    << stream

/*!
  Method style interface for error level severity log entries.

  @param stream The stream to be printed.

  @b Usage
  @code
  int value{20};

  // Print the value at error severity level
  flog_error("Value: " << value);
  @endcode
 */

#define flog_error(stream)                                                     \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  ::flecsi::flog::message<flecsi::flog::error>(__FILE__, __LINE__).format()    \
    << stream

#define __flog_internal_wait_on_flusher() usleep(FLOG_PACKET_FLUSH_INTERVAL)

#else // FLECSI_ENABLE_FLOG

namespace flecsi {
namespace flog {

struct tag {
  tag(const char *) {}
};
struct guard {
  guard(tag const &) {}
};
struct devel_tag {
  devel_tag(const char *) {}
};
struct devel_guard {
  devel_guard(devel_tag const &) {}
};

inline void
add_output_stream(std::string const &, std::ostream &, bool = false) {}

template<class T>
struct container {
  container(T &) {}
  friend std::ostream & operator<<(std::ostream & o, const container &) {
    return o;
  }
};

} // namespace flog
} // namespace flecsi

#define flog_initialize(active)
#define flog_finalize()

#define flog(severity)                                                         \
  if(true) {                                                                   \
  }                                                                            \
  else                                                                         \
    std::cerr

#define flog_devel(severity)                                                   \
  if(true) {                                                                   \
  }                                                                            \
  else                                                                         \
    std::cerr

#define flog_trace(message)
#define flog_info(message)
#define flog_warn(message)
#define flog_error(message)

#define __flog_internal_wait_on_flusher()

#endif // FLECSI_ENABLE_FLOG

namespace flecsi::log {
template<typename T>
auto
to_string(T const & t) {
  return std::move(std::stringstream() << container(t)).str();
}
} // namespace flecsi::log

/*!
  Alias for severity level warn.
 */

#define fixme() flog(warn)

#include <boost/stacktrace.hpp>

namespace flecsi {
namespace flog {

inline void
dumpstack() {
#if !defined(NDEBUG)
  std::cerr << FLOG_OUTPUT_RED("FleCSI Runtime: std::abort called.")
            << std::endl
            << FLOG_OUTPUT_GREEN("Dumping stacktrace...") << std::endl;
  std::cerr << boost::stacktrace::stacktrace() << std::endl;
#else
  std::cerr << FLOG_OUTPUT_RED("FleCSI Runtime: std::abort called.")
            << std::endl
            << FLOG_OUTPUT_BROWN("Build with '-DCMAKE_BUILD_TYPE=Debug'"
                                 << " to enable FleCSI runtime stacktrace.")
            << std::endl;
#endif
} // dumpstack

} // namespace flog
} // namespace flecsi

/*!
  Throw a runtime exception with the provided message.

  @param message The stream message to be printed.

  @note Fatal level severity log entires are not disabled by tags or
        by the ENABLE_FLOG or FLOG_STRIP_LEVEL build options, i.e.,
        they are always active.

  @b Usage
  @code
  int value{20};

  // Print the value and exit
  flog_fatal("Value: " << value);
  @endcode
 */

#define flog_fatal(message)                                                    \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  {                                                                            \
    std::stringstream _sstream;                                                \
    _sstream << FLOG_OUTPUT_LTRED("FATAL ERROR ")                              \
             << FLOG_OUTPUT_YELLOW(::flecsi::flog::rstrip<'/'>(__FILE__)       \
                                   << ":" << __LINE__ << " ")                  \
             << FLOG_OUTPUT_LTRED(message) << std::endl;                       \
    __flog_internal_wait_on_flusher();                                         \
    std::cerr << _sstream.str() << std::endl;                                  \
    ::flecsi::flog::dumpstack();                                               \
    std::abort();                                                              \
  } /* scope */

/*!
  Clog assertion interface. Assertions allow the developer to catch
  invalid program state. This call will invoke flog_fatal if the test
  condition is false.

  @param test    The test condition.
  @param message The stream message to be printed.

  @note Failed assertions are not disabled by tags or
        by the ENABLE_FLOG or FLOG_STRIP_LEVEL build options, i.e.,
        they are always active.

  @b Usage
  @code
  int value{20};

  // Print the value and exit
  flog_assert(value == 20, "invalid value");
  @endcode
 */

/*
  This implementation avoids unused variables error
  Attribution: https://stackoverflow.com/questions/777261/
  avoiding-unused-variables-warnings-when-using-assert-in-a-release-build
 */
#ifdef NDEBUG
#define flog_assert(test, message)                                             \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  do {                                                                         \
    (void)sizeof(test);                                                        \
  } while(0)
#else
#define flog_assert(test, message)                                             \
  /* MACRO IMPLEMENTATION */                                                   \
                                                                               \
  do                                                                           \
    if(!(test)) {                                                              \
      flog_fatal(message);                                                     \
    }                                                                          \
  while(0)
#endif // NDEBUG

/// \}
