//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSCD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSCD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-trigonometric

    cosecante in degree.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = cscd(x);
    @endcode

    is similar to:

    @code
    T r = rec(sind(x));
    @endcode

    As most other trigonometric function cscd can be called with a second optional parameter
    which is a tag on speed and accuracy (see @ref cos for further details)

    @see csc, cscpi,

    @return a value of the same type as the parameter

**/
  template<typename T> auto cscd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometric


      cosecante in degree.


      Function object tied to simd::cscd

      @see simd::cscd
    **/
    const boost::dispatch::functor<tag::cscd_> cscd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/cscd.hpp>
#include <boost/simd/function/simd/cscd.hpp>

#endif
