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
#ifndef BOOST_SIMD_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PLUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-operator

    Perform the sum of two parameters of the same type.

    @par Semantic

    For any value @c a and @c b of type @c T,

    @code
    T x = plus(a,b);
    @endcode

    returns the sum of @c a and @c b

    @param x First  parameter of the addition
    @param y Second parameter of the addition

    @return The sum of the two parameters.
  **/
  template<typename T> auto plus(T const& x, T const& y);

  namespace functional
  {
    /*!
      @ingroup group-callable-operator

      Perform the sum of two parameters of the same type.


      Function object tied to boost::simd::plus

      @see boost::simd::plus
    **/
    const boost::dispatch::functor<tag::plus_> plus = {};
  }
} }
#endif

#include <boost/simd/function/definition/plus.hpp>
#include <boost/simd/arch/common/scalar/function/plus.hpp>
//#include <boost/simd/arch/common/function/simd/plus.hpp>

#endif
