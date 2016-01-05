//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ERFC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ERFC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-euler

  Computes the complementary error function

  @par Semantic:

  For every parameter of floating type T

  @code
  T r = erfc(x);
  @endcode

  is similar to:

  @code
  T0 r = oneminus(erf(x));
  @endcode


  erfc(x, std_) use the call to std::erfc from stdlibc++

  @see erf, erfcx, oneminus

  @return a value of the same type as the parameter

  **/
  template<typename T> auto erfc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-euler

      Computes the complementary error function: \f$e^{x}\f$

      Function object tied to simd::erfc

      @see simd::erfc
    **/
    const boost::dispatch::functor<tag::erfc_> erfc = {};
  }
} }
#endif

#include <boost/simd/function/scalar/erfc.hpp>
#include <boost/simd/function/simd/erfc.hpp>

#endif
