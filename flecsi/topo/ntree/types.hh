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

#include "flecsi/topo/index.hh"
#include "flecsi/util/geometry/point.hh"

namespace flecsi {
namespace topo {

/*
 *
 */
template<Dimension DIM, typename T, class KEY>
class sort_entity
{
  using point_t = util::point<T, DIM>;
  using key_t = KEY;
  using type_t = T;

public:
  sort_entity() {}

  point_t coordinates() const {
    return coordinates_;
  }
  key_t key() const {
    return key_;
  }
  int64_t id() const {
    return id_;
  }
  type_t mass() const {
    return mass_;
  }
  type_t radius() const {
    return radius_;
  }

  void set_coordinates(const point_t & coordinates) {
    coordinates_ = coordinates;
  }
  void set_key(const key_t & key) {
    key_ = key;
  }
  void set_id(const int64_t & id) {
    id_ = id;
  }
  void set_mass(const type_t & mass) {
    mass_ = mass;
  }
  void set_radius(const type_t & radius) {
    radius_ = radius;
  }

  bool operator<(const sort_entity & s) const {
    return std::tie(key_, id_) < std::tie(s.key_, s.id_);
  }

  template<Dimension D, typename TY, class K>
  friend std::ostream & operator<<(std::ostream & os,
    const sort_entity<D, TY, K> & e);

private:
  point_t coordinates_;
  key_t key_;
  int64_t id_;
  type_t mass_;
  type_t radius_;
}; // class sort_entity

template<Dimension DIM, typename T, class KEY>
std::ostream &
operator<<(std::ostream & os, const sort_entity<DIM, T, KEY> & e) {
  os << "Coords: " << e.coordinates() << " Mass: " << e.mass()
     << " Radius: " << e.radius() << " Key: " << e.key() << " Id: " << e.id();
  return os;
}

template<Dimension DIM, typename T, class KEY>
class hcell_base_t
{

  const static Dimension dimension = DIM;
  static constexpr int nchildren_ = 1 << dimension;
  using type_t = T;
  using key_t = KEY;

  enum type_displ : int {
    CHILD_DISPL = 0,
    LOCALITY_DISPL = nchildren_,
    REQUESTED_DISPL = (nchildren_) + 2,
    NCHILD_RECV_DISPL = (nchildren_) + 3
  };
  enum type_mask : int {
    // 1: 0b11, 2: 0b1111, 3: 0b11111111
    CHILD_MASK = (1 << nchildren_) - 1,
    LOCALITY_MASK = 0b11 << LOCALITY_DISPL,
    REQUESTED_MASK = 0b1 << REQUESTED_DISPL,
    NCHILD_RECV_MASK = 0b1111 << NCHILD_RECV_DISPL
  };
  enum type_locality : int { LOCAL = 0, NONLOCAL = 1, SHARED = 2 };

public:
  hcell_base_t() = default;

  hcell_base_t(const key_t & key) : key_(key) {}

  key_t key() const {
    return key_;
  }

  size_t ent_idx() const {
    assert(is_ent_);
    assert(!is_node_);
    return idx_;
  }
  size_t node_idx() const {
    assert(!is_ent_);
    assert(is_node_);
    return idx_;
  }

  size_t idx() const {
    return idx_;
  }

  void set_key(const key_t & key) {
    key_ = key;
  }
  void set_ent_idx(const std::size_t & idx) {
    is_ent_ = true;
    is_node_ = false;
    idx_ = idx;
  }
  void set_node_idx(const std::size_t & idx) {
    is_ent_ = false;
    is_node_ = true;
    idx_ = idx;
  }
  void set_node() {
    is_ent_ = false;
    is_node_ = true;
    idx_ = 0;
  }
  void set_incomplete() {
    is_incomplete_ = true;
  }
  void set_complete() {
    is_incomplete_ = false;
  }
  bool is_incomplete() {
    return is_incomplete_;
  }
  bool is_complete() {
    return !is_incomplete_;
  }

  void add_child(const int & c) {
    type_ |= (1 << c);
  }
  bool is_ent() const {
    return is_ent_;
  }

  bool is_node() const {
    return is_node_;
  }

  unsigned int type() {
    return type_;
  }

  bool has_child(std::size_t c) const {
    return type_ & (1 << c);
  }

  bool has_child() const {
    return type_ & CHILD_MASK;
  }

  bool is_nonlocal() const {
    return ((type_ & LOCALITY_MASK) >> LOCALITY_DISPL) == NONLOCAL;
  }

  bool is_local() const {
    return ((type_ & LOCALITY_MASK) >> LOCALITY_DISPL) == LOCAL;
  }

  void set_type(unsigned int type) {
    type_ = type;
  }

  void set_nonlocal() {
    type_ &= ~LOCALITY_MASK;
    type_ |= NONLOCAL << LOCALITY_DISPL;
  }

  void set_requested() {
    type_ &= ~REQUESTED_MASK;
    type_ |= REQUESTED_MASK;
  }

  void unset_requested() {
    type_ &= ~REQUESTED_MASK;
  }

  std::size_t color() const {
    return color_;
  }
  void set_color(std::size_t color) {
    color_ = color;
  }

  std::size_t nchildren() const {
    std::size_t nchild = 0;
    for(std::size_t i = 0; i < nchildren_; ++i)
      nchild += has_child(i);
    return nchild;
  }

  template<Dimension DD, typename TT, class KK>
  friend std::ostream & operator<<(std::ostream & os,
    const hcell_base_t<DD, TT, KK> & hb);

  friend bool operator<(const hcell_base_t & l, const hcell_base_t & r) {
    return l.key_ < r.key_;
  }

private:
  key_t key_;
  std::size_t idx_ = 0;
  bool is_ent_ = false;
  bool is_node_ = true;
  bool is_incomplete_ = true;
  unsigned int type_ = 0;
  std::size_t color_;
};

template<Dimension D, typename T, class K>
std::ostream &
operator<<(std::ostream & os, const hcell_base_t<D, T, K> & hb) {
  hb.is_node() ? os << "hc node " : os << "hc ent ";
  os << hb.key_ << "-" << hb.idx_;
  return os;
}

template<Dimension, typename T, class KEY>
class node
{ node() = default; };

} // namespace topo
} // namespace flecsi
