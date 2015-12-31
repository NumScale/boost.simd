//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic sine: \f$\frac{e^{x}-e^{-x}}2\f$.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = sinh(x);
    @endcode

    is similar to:

    @code
    T r = Half<T>()*(exp(x)-exp(-x));;
    @endcode

    @see exp, cosh, sinhcosh

    @return a value of the same type as the parameter

**/
  template<typename T> auto sinh(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic sine: \f$\frac{e^{x}-e^{-x}}2\f$.


      Function object tied to simd::sinh

      @see simd::sinh
    **/
    const boost::dispatch::functor<tag::sinh_> sinh = {};
  }
} }
#endif

#include <boost/simd/function/scalar/sinh.hpp>
#include <boost/simd/function/simd/sinh.hpp>

#endif
