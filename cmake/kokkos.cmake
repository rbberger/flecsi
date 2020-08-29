#------------------------------------------------------------------------------#
#  @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
# /@@/////  /@@          @@////@@ @@////// /@@
# /@@       /@@  @@@@@  @@    // /@@       /@@
# /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
# /@@////   /@@/@@@@@@@/@@       ////////@@/@@
# /@@       /@@/@@//// //@@    @@       /@@/@@
# /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
# //       ///  //////   //////  ////////  //
#
# Copyright (c) 2016 Los Alamos National Laboratory, LLC
# All rights reserved
#------------------------------------------------------------------------------#

option(ENABLE_KOKKOS "Enable Kokkos" OFF)

if(ENABLE_KOKKOS)

  find_package(Kokkos REQUIRED)
  
  if(Kokkos_ENABLE_CUDA AND NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND
    NOT ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 8)
    message(FATAL_ERROR "Clang version 8 or greater required for Kokkos")
  endif()

  set(Kokkos_LIBRARIES Kokkos::kokkos)

  list(APPEND FLECSI_LIBRARY_DEPENDENCIES ${Kokkos_LIBRARIES})
  
  add_definitions("-DFLECSI_ENABLE_KOKKOS")

endif()
