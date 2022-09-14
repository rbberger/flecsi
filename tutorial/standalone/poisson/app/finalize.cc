/*----------------------------------------------------------------------------*
  Copyright (c) 2020 Triad National Security, LLC
  All rights reserved
 *----------------------------------------------------------------------------*/

#include "finalize.hh"
#include "state.hh"
#include "tasks/io.hh"

using namespace flecsi;

void
poisson::action::finalize(control_policy &) {
  execute<task::io, mpi>(m, ud(m), "solution");
} // finalize
