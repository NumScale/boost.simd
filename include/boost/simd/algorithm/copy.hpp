//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_COPY_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_COPY_HPP_INCLUDED

#include <boost/simd/algorithm/transform.hpp>
#include <boost/simd/pack.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Copies the elements in the range, defined by [first, last)
    to another range beginning at out.

    @param first  Beginning of the range of elements
    @param last   End of the range of elements
    @param out    Beginning of the destination range

    @par Requirement

      - @c first , @c last and @c out must be pointer to Vectorizable type.

      - return a pointer to the element past the last element copied.

    @par Example:

      @snippet copy.cpp copy

    @par Possible output:

      @snippet copy.txt copy

  **/
  template<typename T, typename U>
  U* copy(T const* first, T const* last, U* out)
  {
    namespace bs =  boost::simd;
    struct local
    {
      using p_t = pack<T>;
      T operator()(T const& x) { return x; }
      p_t operator()(p_t const& x) { return  x; }
    };
    return bs::transform(first, last, out, local{});
  }

} }

#endif
