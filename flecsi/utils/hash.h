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

#ifndef flecsi_utils_hash_h
#define flecsi_utils_hash_h

//!
//! \file
//! \date Initial file creation: Oct 15, 2015
//!

#include <cstddef>
#include <utility>

namespace flecsi {
namespace utils {

//----------------------------------------------------------------------------//
// Simple hash function interface.
//----------------------------------------------------------------------------//

namespace hash {

//----------------------------------------------------------------------------//
//! Hashing function for client registration.
//!
//! @tparam NAMESPACE The namespace key.
//! @tparam NAME      The name key.
//----------------------------------------------------------------------------//

template<
  size_t MASK,
  size_t SHIFT
>
inline
constexpr size_t
bit_range(
  size_t key
)
{
  return (key >> SHIFT) & MASK;
} // bit_range

////////////////////////////////////////////////////////////////////////////////
// Field data hash interface.
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
//! Create a hash key suitable for registering a field with the low-level
//! field registry.
//!
//! @tparam NAMESPACE A namespace identifier.
//! @tparam NAME      A name identifier.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

template<
  size_t NAMESPACE,
  size_t NAME
>
inline
constexpr size_t
field_hash()
{
  return NAMESPACE ^ NAME;
} // field_hash__

////////////////////////////////////////////////////////////////////////////////
// Client entities hash interface.
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
//! Create a hash key suitable for registering client entity types with
//! the low-level field registry.
//!
//! @tparam NAMESPACE A namespace identifier.
//! @tparam NAME      A name identifier.
//! @tparam INDEX     The associated index space.
//! @tparam DOMAIN    The domain.
//! @tparam DIMENSION The topological dimension.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

template<
  size_t NAMESPACE,
  size_t NAME,
  size_t INDEX,
  size_t DOMAIN_, // FIXME: Somewhere DOMAIN is being defined
  size_t DIMENSION
>
inline
constexpr size_t
client_entity_hash()
{
  return ((NAMESPACE ^ NAME) << 12) |
    (INDEX << 4) |
    (DOMAIN_ << 2) |
    DIMENSION;
} // client_entity_hash

//----------------------------------------------------------------------------//
//! Recover the index space from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_entity_index(
  size_t key
)
{
  return bit_range<0xff, 4>(key);
} // client_entity_index

//----------------------------------------------------------------------------//
//! Recover the domain from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_entity_domain(
  size_t key
)
{
  return bit_range<0x03, 2>(key);
} // client_entity_domain

//----------------------------------------------------------------------------//
//! Recover the dimension from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_entity_dimension(
  size_t key
)
{
  return bit_range<0x03, 0>(key);
} // client_entity_dimension

////////////////////////////////////////////////////////////////////////////////
// Client adjacency hash interface.
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
//! Create a hash key suitable for registering client adjacency types with
//! the low-level field registry.
//!
//! @tparam NAMESPACE      A namespace identifier.
//! @tparam NAME           A name identifier.
//! @tparam INDEX          The associated index space.
//! @tparam FROM_DOMAIN    The from domain.
//! @tparam TO_DOMAIN      The to domain.
//! @tparam FROM_DIMENSION The topological from dimension.
//! @tparam TO_DIMENSION   The topological to dimension.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

template<
  size_t NAMESPACE,
  size_t NAME,
  size_t INDEX,
  size_t FROM_DOMAIN,
  size_t TO_DOMAIN,
  size_t FROM_DIMENSION,
  size_t TO_DIMENSION
>
inline
constexpr size_t
client_adjacency_hash()
{
  return ((NAMESPACE ^ NAME) << 16) |
    (INDEX << 8) |
    (FROM_DOMAIN << 6) |
    (TO_DOMAIN << 4) |
    (FROM_DIMENSION << 2) |
    TO_DIMENSION;
} // client_adjacency_hash

//----------------------------------------------------------------------------//
//! Recover the index space from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_adjacency_index(
  size_t key
)
{
  return bit_range<0xff, 8>(key);
} // client_adjacency_index

//----------------------------------------------------------------------------//
//! Recover the domain from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_adjacency_from_domain(
  size_t key
)
{
  return bit_range<0x03, 6>(key);
} // client_adjacency_from_domain

//----------------------------------------------------------------------------//
//! Recover the to domain from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_adjacency_to_domain(
  size_t key
)
{
  return bit_range<0x03, 4>(key);
} // client_adjacency_to_domain

//----------------------------------------------------------------------------//
//! Recover the dimension from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_adjacency_from_dimension(
  size_t key
)
{
  return bit_range<0x03, 2>(key);
} // client_adjacency_from_dimension

//----------------------------------------------------------------------------//
//! Recover the dimension from a key to a client entity.
//!
//! @param key The client entity key.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

inline
constexpr size_t
client_adjacency_to_dimension(
  size_t key
)
{
  return bit_range<0x03, 0>(key);
} // client_adjacency_to_dimension

////////////////////////////////////////////////////////////////////////////////
// Client internal field hash interface.
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
//! Create a hash key suitable for registering internal client field data with
//! the low-level field registry.
//!
//! @tparam INDEX_SPACE The index space id of the associated field.
//!
//! @ingroup utils
//----------------------------------------------------------------------------//

template<
  size_t NAME,
  size_t INDEX_SPACE
>
inline
constexpr size_t
client_internal_field_hash()
{
  return (NAME << 8) | INDEX_SPACE;
} // field_hash__

inline
constexpr size_t
client_internal_field_index_space(
  size_t key
)
{
  return bit_range<0xff, 8>(key);
} // client_internal_field_index_space

} // namespace hash

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

template<
  typename T,
  typename U
>
constexpr
T
string_hash__(
  U && str,
  const T h,
  const std::size_t i,
  const std::size_t n
)
{
  // An unstated assumption appears to be that n is the length of str, which is
  // a string type, and that i <= n. Otherwise, we're going to have problems.
  return i == n ?  h :
    string_hash__(str, h ^ static_cast<T>(std::forward<U>(str)[i]) << 8*(i%8),
      i + 1, n);
} // string_hash__

template<
  typename T,
  typename U
>
constexpr
T
string_hash(
  U && str,
  const std::size_t n
)
{
  return string_hash__<T>(str, 0, 0, n);
} // string_hash

} // namespace utils
} // namespace flecsi

#endif // flecsi_utils_hash_h

/*~-------------------------------------------------------------------------~-*
 * Formatting options
 * vim: set tabstop=2 shiftwidth=2 expandtab :
 *~-------------------------------------------------------------------------~-*/
