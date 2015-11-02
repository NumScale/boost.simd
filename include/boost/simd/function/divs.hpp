//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes  the truncated saturated division of its parameters.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divs(x, y);
    @endcode

    The code is similar to:

    @code
    T r = trunc(x/y);
    @endcode

    for integral types, if y is null, it returns Valmax or Valmin
    if x is positive (resp. negative) and 0 if x is null.
    Saturated means that for signed integer types,
    @c divs(Valmin,-1) returns Valmax.

    @par Alias

    @c saturated_div, rdivide

    @see  divides, rec, divfloor,
    divceil, divround, divround2even, divfix

    @return      a value of the same type as the input.


**/
  template<typename T> auto divs(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::divs

      @see simd::divs
    **/
    const boost::dispatch::functor<tag::divs_> divs = {};
  }
} }
#endif

#include <boost/simd/function/definition/divs.hpp>
#include <boost/simd/arch/common/scalar/function/divs.hpp>
//#include <boost/simd/arch/common/function/simd/divs.hpp>

#endif
