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
#ifndef BOOST_SIMD_FUNCTION_DIVFLOOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVFLOOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the floor of the division.

    @par semantic:
    For any given value @c x,  @c y of type @c T:

    @code
    T r = divfloor(x, y);
    @endcode

    The code is similar to:

    @code
    T r = floor(x/y);
    @endcode

    for integral types, if y is null, it returns Valmax or Valmin
    if x is positive (resp. negative) and 0 if x is null.
    Take also care that dividing Valmin by -1 for signed integral types has
    undefined behaviour.

    @see  divides, rec, divs, divfix,
    divround, divround2even

    @return      a value of the same type as the input.


**/
  template<typename T> auto divfloor(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the floor of the division.


      Function object tied to simd::divfloor

      @see simd::divfloor
    **/
    const boost::dispatch::functor<tag::divfloor_> divfloor = {};
  }
} }
#endif

#include <boost/simd/function/definition/divfloor.hpp>
#include <boost/simd/arch/common/scalar/function/divfloor.hpp>
//#include <boost/simd/arch/common/function/simd/divfloor.hpp>

#endif
