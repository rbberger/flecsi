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

#ifndef flecsi_default_dense_h
#define flecsi_default_dense_h

#include "flecsi/utils/const_string.h"
#include "flecsi/data/default/default_storage_type.h"

/*!
 * \file default_dense.h
 * \authors bergen
 * \date Initial file creation: Oct 27, 2015
 */

namespace flecsi
{
namespace data_model
{
namespace default_storage_policy
{

  /*!
    FIXME: Dense storage type.
   */
  template<typename data_store_t>
  struct storage_type_t<dense, data_store_t> {

    struct dense_accessor_t {
    }; // struct dense_accessor_t

    struct dense_handle_t {
    }; // struct dense_handle_t

    /*!
      \tparam T Data type to register.
      \tparam NS Namespace
      \tparam Args Variadic arguments that are passed to
        metadata initialization.
      
      \param stg A data_store_t reference for accessing the low-level data.
      \param key A const string instance containing the variable name.
      \param indeces The number of indeces in the index space.
      \param runtime_namespace The runtime namespace to be used.
     */
    template<typename T, size_t NS, typename ... Args>
    static dense_handle_t register_data(data_store_t & data_store,
      uintptr_t runtime_namespace, const const_string_t & key,
      size_t indeces, Args && ... args) {
      std::cout << "Indeces: " << indeces << std::endl;
    } // register_data

    /*!
     */
    template<typename T, size_t NS>
    static dense_accessor_t get_accessor(data_store_t & data_store,
      uintptr_t runtime_namespace, const const_string_t & key) {
      return {};
    } // get_accessor

    /*!
     */
    template<typename T, size_t NS>
    static dense_handle_t get_handle(data_store_t & data_store,
      uintptr_t runtime_namespace, const const_string_t & key) {
      return {};
    } // get_handle

  }; // struct storage_type_t

} // namespace default_storage_policy
} // namespace data_model
} // namespace flecsi

#endif // flecsi_default_dense_h

/*~-------------------------------------------------------------------------~-*
 * Formatting options
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
