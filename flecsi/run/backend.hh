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

//----------------------------------------------------------------------------//
// This section works with the build system to select the correct backend
// implementation for the task model.
//----------------------------------------------------------------------------//

#if FLECSI_BACKEND == FLECSI_BACKEND_legion

#include "flecsi/run/leg/context.hh"

#elif FLECSI_BACKEND == FLECSI_BACKEND_mpi

#include "flecsi/run/mpi/context.hh"

#elif FLECSI_BACKEND == FLECSI_BACKEND_hpx

#include "hpx/context.hh"

#endif // FLECSI_BACKEND

namespace flecsi::run {
// Now that the backend's context_t is complete:
context_t &
context::instance() {
  static context_t context;
  return context;
} // instance
} // namespace flecsi::run
