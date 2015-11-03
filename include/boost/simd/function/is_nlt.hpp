//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NLT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NLT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns @ref True or @ref False according x is not less or equal to y or is.

    This is a convenient alias of @ref is_not_less
**/
  template<typename T> auto is_nlt(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      TODO Put description here

      Returns @ref True or @ref False according x is not less or equal to y or is.

      Function object tied to simd::is_nlt

      @see simd::is_nlt
    **/
    const boost::dispatch::functor<tag::is_nlt_> is_nlt = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_nlt.hpp>
#include <boost/simd/arch/common/scalar/function/is_not_less.hpp>
#include <boost/simd/function/simd/is_nlt.hpp>

#endif
