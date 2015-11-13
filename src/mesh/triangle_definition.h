/*~--------------------------------------------------------------------------~*
 * Copyright (c) 2015 Los Alamos National Security, LLC
 * All rights reserved.
 *~--------------------------------------------------------------------------~*/

#ifndef flexi_triangle_definition_h
#define flexi_triangle_definition_h

/*!
 * \file triangle_definition.h
 * \authors bergen
 * \date Initial file creation: Nov 12, 2015
 */

#include "entity_definition.h"

namespace flexi {

/*!
  \class triangle_definition triangle_definition.h
  \brief triangle_definition provides...
 */
class triangle_definition_t : public entity_definition_t
{
public:

  //! Default constructor
  triangle_definition_t() {}

  //! Copy constructor (disabled)
  triangle_definition_t(const triangle_definition_t &) = delete;

  //! Assignment operator (disabled)
  triangle_definition_t &
  operator = (const triangle_definition_t &) = delete;

  //! Destructor
   ~triangle_definition_t() {}

  size_t dimension() override { return 2; }

  size_t sub_entities(size_t dimension) override {
    switch(dimension) {
      case 0:
        return 3;
      case 1:
        return 3;
      default:
        assert(false && "Invalid dimension");
    } // switch
  } // sub_entities

  size_t sub_entity_map(size_t dimension, size_t i, size_t p) override {
    switch(dimension) {
      case 0:
        return vertex_map_[i][p];
      case 1:
        return edge_map_[i][p];
      default:
        assert(false && "Invalid dimension");
    } // switch
  } // sub_entity_map

private:

  static constexpr size_t vertex_map_[3][2] = {
    {0, 0},
    {1, 0},
    {0, 1}
  }; // vertex_map_

  static constexpr size_t edge_map_[3][2] = {
    {0, 1},
    {1, 2},
    {3, 0}
  }; // edge_map_

}; // class triangle_definition_t

constexpr size_t triangle_definition_t::vertex_map_[3][2];
constexpr size_t triangle_definition_t::edge_map_[3][2];

} // namespace flexi

#endif // flexi_triangle_definition_h

/*~-------------------------------------------------------------------------~-*
 * Formatting options for vim.
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
