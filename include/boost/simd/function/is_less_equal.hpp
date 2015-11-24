//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LESS_EQUAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True  or @ref False depending on whether x is
    less than or equal to y or not.

    Infix notation can be used with operator '<='.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    as_logical_t<T0> r = is_less_equal(x,y);
    @endcode

    is similar to:

    @code
    as_logical_t<T0> r = x <= y;
    @endcode

    @par Alias:
    @c le, @c is_le

    @see  is_equal, is_eqz, is_nez


    @return a logical value

**/
  template<typename T> auto is_less_equal(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns @ref True or @ref False depending on whether x is
      less than or equal to y or not.


      Function object tied to simd::is_less_equal

      @see simd::is_less_equal
    **/
    const boost::dispatch::functor<tag::is_less_equal_> is_less_equal = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_less_equal.hpp>
#include <boost/simd/arch/common/scalar/function/is_less_equal.hpp>
#include <boost/simd/function/simd/is_less_equal.hpp>

#endif
