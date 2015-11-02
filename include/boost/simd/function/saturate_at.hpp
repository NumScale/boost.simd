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
#ifndef BOOST_SIMD_FUNCTION_SATURATE_AT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SATURATE_AT_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the saturated value of the first input relative to the symmetric
    interval defined by the template parameter which has to be the tag of
    a constant.

    @par Semantic:

    @code
    T r = saturate <Tag>(x)
    @endcode

    is similar to:

    @code
    if (a0 > Tag<T>()) r =  Tag<T>();
    else if  (a0 < -Tag<T>()) r = -Tag<T>() ;
    else r = a0;
    @endcode


    @return a value of same type as the inputs

**/
  template<typename T> auto saturate_at(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::saturate_at

      @see simd::saturate_at
    **/
    const boost::dispatch::functor<tag::saturate_at_> saturate_at = {};
  }
} }
#endif

#include <boost/simd/function/definition/saturate_at.hpp>
#include <boost/simd/arch/common/generic/function/saturate_at.hpp>
//#include <boost/simd/arch/common/function/simd/saturate_at.hpp>

#endif
