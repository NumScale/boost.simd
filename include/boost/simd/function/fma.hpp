//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic
    Function object function implementing fma capabilities

    Computes the (fused) multiply add of the three parameters.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fma(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = x*y+z;
    @endcode

    @par Note
    Conformant fused multiply/add implies

    - only one rounding

    - no "intermediate" overflow

    fma provides this for all integral types and each time it is reasonable
    in terms of performance for floating ones (i.e. if the system has the hard
    wired capability).

    If you need conformant fma capabilities in all circumstances in your own
    code you can use correct_fma or the std_ decorator
    (although both can can be very expansive).

     @par Decorators

    std_ for floating entries to call directly std::fma. This implies conformant fma behaviour,
    but in no way improved performances.

    @par Alias

    @c madd

    @see  correct_fma, fms, fnma, fnms
  **/
    const boost::dispatch::functor<tag::fma_> fma = {};
  }
} }
#endif

#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/function/simd/fma.hpp>

#endif
