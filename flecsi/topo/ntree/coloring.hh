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

#include <map>
#include <vector>

namespace flecsi {
namespace topo {

//----------------------------------------------------------------------------//
// NTree topology coloring.
//----------------------------------------------------------------------------//

struct ntree_base {
  enum index_space { entities, nodes, hashmap, tree_data, meta, comms };
  // static constexpr std::size_t index_spaces = 1;
  using index_spaces =
    util::constants<entities, nodes, hashmap, tree_data, meta, comms>;
  // Parallel types for nodes and entities
  enum ptype_t { exclusive, ghost, all };
  // traversal types for DFS
  enum ttype_t { preorder, postorder, reverse_preorder, reverse_postorder };

  using ent_id = topo::id<entities>;
  using node_id = topo::id<nodes>;

  struct ent_node {
    std::size_t ents;
    std::size_t nodes;
  };

  struct meta_type {
    std::size_t max_depth;
    ent_node local, ghosts, top_tree;
    std::size_t nents_recv;
  };

  struct en_size {
    std::vector<std::size_t> ent, node;
  };

  struct color_id {
    std::size_t color;
    ent_id id;
    std::size_t from_color;
  };

  struct coloring {

    coloring(Color nparts)
      : nparts_(nparts), global_hmap_(nparts * local_hmap_),
        hmap_offset_(nparts, local_hmap_), tdata_offset_(nparts, 3),
        cdata_offset_(nparts, 100), meta_offset_(nparts, 1),
        comms_offset_(nparts, nparts) {}

    // Global
    Color nparts_;

    // Entities
    std::size_t local_entities_;
    std::size_t global_entities_;
    std::vector<std::size_t> entities_distribution_;
    std::vector<std::size_t> entities_offset_;

    // nodes
    std::size_t local_nodes_;
    std::size_t global_nodes_;
    std::vector<std::size_t> nodes_offset_;

    // hmap
    static constexpr size_t local_hmap_ = 1 << 15;
    std::size_t global_hmap_;
    std::vector<std::size_t> hmap_offset_;

    // tdata
    std::vector<std::size_t> tdata_offset_;

    // cdata
    std::vector<std::size_t> cdata_offset_;

    // All global sizes array for make_partition
    std::vector<std::size_t> global_sizes_;

    std::vector<std::size_t> meta_offset_;

    std::vector<std::size_t> comms_offset_;
  }; // struct coloring

  static std::size_t allocate(const std::vector<std::size_t> & arr,
    const std::size_t & i) {
    return arr[i];
  }

  static void set_dests(field<data::intervals::Value>::accessor<wo> a) {
    assert(a.span().size() == 1);
    a[0] = data::intervals::make({1, 3});
  }
  static void set_ptrs(field<data::points::Value>::accessor<wo, na> a) {
    const auto & c = run::context::instance();
    const auto i = c.color(), n = c.colors();
    assert(a.span().size() == 3);
    a[1] = data::points::make(i == 0 ? i : i - 1, 0);
    a[2] = data::points::make(i == n - 1 ? i : i + 1, 0);
  }
  template<auto * F> // work around Clang 10.0.1 bug with auto&
  static constexpr auto task = [](auto f) { execute<*F>(f); };
}; // struct ntree_base

} // namespace topo
} // namespace flecsi
