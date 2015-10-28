//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_VALMAX_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_VALMAX_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the maximum representable value of a given type as a constant.

    @par Semantic

    For any type @c T,

    @code
    T x = Valmax<T>();
    @endcode

    return the maximum representable value for this type.

    @return The maximum representable value of the input type
  **/
  template<typename T> T Valmax();

  namespace functional
  {
    /*!
      @ingroup group-constant

      Generate the maximum finite representable value of a given type as a constant.

      @par Semantic

      For any type @c T,

      @code
      T x = valmax(as(T{}));
      @endcode

      return the maximum finite representable value for this type.

      @return The maximum finite representable value of the input type
    **/
    const boost::dispatch::functor<tag::valmax_> valmax = {};
  }
} }
#endif

#include <boost/simd/constant/definition/valmax.hpp>
#include <boost/simd/arch/common/constant/scalar/constant_value.hpp>

#endif
