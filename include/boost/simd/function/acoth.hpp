//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOTH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOTH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-hyperbolic

    Returns the hyperbolic cotangent argument \f$\frac12\log\frac{x^2+1}{x^2-1}\f$

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = acoth(x);
    @endcode

    is similar to:

    @code
    T r = Half<T>()*log(oneplus(sqr(x))/minusone(sqr(x)));
    @endcode

    @see log, Half

    @return a value of the same type as the parameter

**/
  template<typename T> auto acoth(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-hyperbolic


      Returns the hyperbolic cotangent argument \f$\frac12\log\frac{x^2+1}{x^2-1}\f$


      Function object tied to simd::acoth

      @see simd::acoth
    **/
    const boost::dispatch::functor<tag::acoth_> acoth = {};
  }
} }
#endif

#include <boost/simd/function/scalar/acoth.hpp>
#include <boost/simd/function/simd/acoth.hpp>

#endif
