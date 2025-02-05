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

#include "flecsi/util/unit.hh"
#include <flecsi/execution.hh>

flecsi::program_option<int> po("Custom Options",
  "value,v",
  "Set the value [1-5].",
  {{flecsi::option_default, 1}, {flecsi::option_implicit, 2}},
  [](flecsi::any const & v, std::stringstream & ss) {
    auto val = flecsi::option_value<int>(v);
    return val <= 5 || ((ss << "value(" << val << ") out-of-range"), false);
  });

flecsi::program_option<std::string> spo("Custom Options",
  "str,s",
  "Set the value.",
  {{flecsi::option_implicit, "help me!"}, {flecsi::option_zero}},
  [](flecsi::any const & v, std::stringstream &) {
    return flecsi::option_value<std::string>(v) == "help me!";
  });

flecsi::program_option<bool> bpo("Custom Options",
  "bop,b",
  "Set the value.",
  {{flecsi::option_implicit, true}, {flecsi::option_zero}});

int
program_options() {
  UNIT() {
    ASSERT_EQ(po.value(), 1);
    ASSERT_FALSE(spo.has_value());
    ASSERT_FALSE(bpo.has_value());
  };
} // program_options

flecsi::unit::driver<program_options> driver;
