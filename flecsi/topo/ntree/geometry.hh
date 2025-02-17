/*~--------------------------------------------------------------------------~*
 *  @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
 * /@@/////  /@@          @@////@@ @@////// /@@
 * /@@       /@@  @@@@@  @@    // /@@       /@@
 * /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
 * /@@////   /@@/@@@@@@@/@@       ////////@@/@@
 * /@@       /@@/@@//// //@@    @@       /@@/@@
 * /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
 * //       ///  //////   //////  ////////  //
 *
 * Copyright (c) 2016 Los Alamos National Laboratory, LLC
 * All rights reserved
 *~--------------------------------------------------------------------------~*/

#pragma once

#include "flecsi/util/geometry/point.hh"

#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <float.h>
#include <iostream>
#include <math.h>
#include <vector>

namespace flecsi {
namespace topo {

/*-----------------------------------------------------------------------------*
 * class ntree_geometry
 *-----------------------------------------------------------------------------*/
template<typename T, Dimension>
struct ntree_geometry {};

/*-----------------------------------------------------------------------------*
 * class ntree_geometry 1D specification
 *-----------------------------------------------------------------------------*/
template<typename T>
struct ntree_geometry<T, 1> {

  using point_t = util::point<T, 1>;
  using element_t = T;
  //! Tolerance for the computations
  static constexpr element_t tol =
    std::numeric_limits<element_t>::epsilon() * 10.;

  //! Return true if point origin lies within the spheroid centered at
  //! center with radius.
  static bool
  within(const point_t & origin, const point_t & center, element_t r1) {
    return util::distance(origin, center) - r1 <= tol;
  }

  //! Return true if dist^2 < radius^2
  static bool within_square(const point_t & origin,
    const point_t & center,
    element_t r1,
    element_t r2) {
    return util::distance(origin, center) <= std::max(r1, r2);
  }

  //! Return true if point origin lies within the box specified by
  //! min/max point.
  static bool
  within_box(const point_t & min, const point_t & max, const point_t & origin) {
    return origin[0] <= max[0] && origin[0] >= min[0];
  }

  //! Intersection between two boxes defined by there min and max bound
  static bool intersects_box_box(const point_t & min_b1,
    const point_t & max_b1,
    const point_t & min_b2,
    const point_t & max_b2) {
    return !((max_b1[0] < min_b2[0]) || (max_b2[0] < min_b1[0]));
  }

  //! Intersection of two spheres based on center and radius
  static bool intersects_sphere_sphere(const point_t & c1,
    const element_t r1,
    const point_t & c2,
    const element_t r2) {
    return util::distance(c1, c2) - (r1 + r2) <= tol;
  }

  //! Intersection of sphere and box; Compute the closest point from the
  //! rectangle to the sphere and this distance less than sphere radius
  static bool intersects_sphere_box(const point_t & min,
    const point_t & max,
    const point_t & c,
    const element_t r) {
    point_t x = point_t(std::max(min[0], std::min(c[0], max[0])));
    element_t dist = util::distance(x, c);
    return dist - r <= tol;
  }

  /**
   * Multipole method acceptance based on MAC.
   * The angle === l/r < MAC (l source box width, r distance sink -> source)
   * Barnes & Hut 1986
   */
  bool box_MAC(const point_t & position_source,
    const point_t & position_sink,
    const point_t & box_source_min,
    const point_t & box_source_max,
    double macangle) {
    double dmax = util::distance(box_source_min, box_source_max);
    double disttoc = util::distance(position_sink, position_source);
    return dmax / disttoc - macangle <= tol;
  }
}; // class ntree_geometry specification for 1D

/*-----------------------------------------------------------------------------*
 * class ntree_geometry 2D specification
 *-----------------------------------------------------------------------------*/
template<typename T>
struct ntree_geometry<T, 2> {
  using point_t = util::point<T, 2>;
  using element_t = T;

  //! Tolerance for the computations
  static constexpr element_t tol =
    std::numeric_limits<element_t>::epsilon() * 10.;

  //! Return true if point origin lies within the spheroid centered at
  //! center with radius.
  static bool
  within(const point_t & origin, const point_t & center, element_t r1) {
    return util::distance(origin, center) - r1 <= tol;
  }

  //! Return true if dist^2 < radius^2
  static bool within_square(const point_t & origin,
    const point_t & center,
    element_t r1,
    element_t r2) {
    return util::distance(origin, center) <= std::max(r1, r2);
  }

  //! Return true if point origin lies within the box specified by
  //! min/max point.
  static bool
  within_box(const point_t & min, const point_t & max, const point_t & origin) {
    return origin[0] <= max[0] && origin[0] > min[0] && origin[1] <= max[1] &&
           origin[1] > min[1];
  }

  //! Intersection between two boxes defined by there min and max bound
  static bool intersects_box_box(const point_t & min_b1,
    const point_t & max_b1,
    const point_t & min_b2,
    const point_t & max_b2) {
    return !((max_b1[0] < min_b2[0] || max_b1[1] < min_b2[1]) ||
             (max_b2[0] < min_b1[0] || max_b2[1] < min_b1[1]));
  }

  //! Intersection of two spheres based on center and radius
  static bool intersects_sphere_sphere(const point_t & c1,
    const element_t r1,
    const point_t & c2,
    const element_t r2) {
    return util::distance(c1, c2) - (r1 + r2) <= tol;
  }

  //! Intersection of sphere and box; Compute the closest point from the
  //! rectangle to the sphere and this distance less than sphere radius
  static bool intersects_sphere_box(const point_t & min,
    const point_t & max,
    const point_t & c,
    const element_t r) {
    point_t x = point_t(std::max(min[0], std::min(c[0], max[0])),
      std::max(min[1], std::min(c[1], max[1])));
    element_t dist = util::distance(x, c);
    return dist - r <= tol;
  }

  /**
   * Multipole method acceptance based on MAC.
   * The angle === l/r < MAC (l source box width, r distance sink -> source)
   * Barnes & Hut 1986
   */
  static bool box_MAC(const point_t & position_source,
    const point_t & position_sink,
    const point_t & box_source_min,
    const point_t & box_source_max,
    double macangle) {
    double dmax = util::distance(box_source_min, box_source_max);
    double disttoc = util::distance(position_sink, position_source);
    return dmax / disttoc < macangle;
  }
}; // class tree_geometry specification for 2D

/*-----------------------------------------------------------------------------*
 * class tree_geometry 3D specification
 *-----------------------------------------------------------------------------*/
template<typename T>
struct ntree_geometry<T, 3> {
  using point_t = util::point<T, 3>;
  using element_t = T;
  //! Tolerance for the computations
  static constexpr element_t tol =
    std::numeric_limits<element_t>::epsilon() * 10.;

  //! Return true if point origin lies within the spheroid centered at
  //! center with radius.
  static bool
  within(const point_t & origin, const point_t & center, element_t r1) {
    return util::distance(origin, center) - r1 <= tol;
  }

  //! Return true if dist^2 < radius^2
  inline static bool within_square(const point_t & origin,
    const point_t & center,
    const element_t & r1,
    const element_t & r2) {
    return util::distance(origin, center) <= std::max(r1, r2);
  }

  //! Return true if point origin lies within the box specified by
  //! min/max point.
  static bool
  within_box(const point_t & min, const point_t & max, const point_t & origin) {
    return origin[0] <= max[0] && origin[0] > min[0] && origin[1] <= max[1] &&
           origin[1] > min[1] && origin[2] <= max[2] && origin[2] > min[2];
  }

  //! Intersection between two boxes defined by there min and max bound
  inline static bool intersects_box_box(const point_t & min_b1,
    const point_t & max_b1,
    const point_t & min_b2,
    const point_t & max_b2) {
    return !((max_b1[0] < min_b2[0] || max_b1[1] < min_b2[1] ||
               max_b1[2] < min_b2[2]) ||
             (max_b2[0] < min_b1[0] || max_b2[1] < min_b1[1] ||
               max_b2[2] < min_b1[2]));
  }

  //! Intersection of two spheres based on center and radius
  static bool intersects_sphere_sphere(const point_t & c1,
    const element_t r1,
    const point_t & c2,
    const element_t r2) {
    return (c2[0] - c1[0]) * (c2[0] - c1[0]) +
             (c2[1] - c1[1]) * (c2[1] - c1[1]) +
             (c2[2] - c1[2]) * (c2[2] - c1[2]) <=
           (r1 + r2) * (r1 + r2);
  }

  //! Intersection of sphere and box; Compute the closest point from the
  //! rectangle to the sphere and this distance less than sphere radius
  static bool intersects_sphere_box(const point_t & min,
    const point_t & max,
    const point_t & c,
    const element_t & r) {
    point_t x = point_t(c[0] < max[0] ? c[0] : max[0],
      c[1] < max[1] ? c[1] : max[1],
      c[2] < max[2] ? c[2] : max[2]);
    x = {x[0] < min[0] ? min[0] : x[0],
      x[1] < min[1] ? min[1] : x[1],
      x[2] < min[2] ? min[2] : x[2]};
    element_t dist = (x[0] - c[0]) * (x[0] - c[0]) +
                     (x[1] - c[1]) * (x[1] - c[1]) +
                     (x[2] - c[2]) * (x[2] - c[2]);
    return dist <= r * r;
  }

  /**
   * Multipole method acceptance based on MAC.
   * The angle === l/r < MAC (l source box width, r distance sink -> source)
   * Barnes & Hut 1986
   */
  static bool box_MAC(const point_t & position_source,
    const point_t & position_sink,
    const point_t & box_source_min,
    const point_t & box_source_max,
    double macangle) {
    double dmax = util::distance(box_source_min, box_source_max);
    double disttoc = util::distance(position_sink, position_source);
    return dmax / disttoc < macangle;
  }
}; // class ntree_geometry specification for 3D

} // namespace topo
} // namespace flecsi

/*~-------------------------------------------------------------------------~-*
 * Formatting options for vim.
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
