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
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_XOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_XOR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes logical_xor value of its parameter.

  **/
  template<typename T> auto logical_xor(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::logical_xor

      @see simd::logical_xor
    **/
    const boost::dispatch::functor<tag::logical_xor_> logical_xor = {};
  }
} }
#endif

#include <boost/simd/function/definition/logical_xor.hpp>
#include <boost/simd/arch/common/scalar/function/logical_xor.hpp>
//#include <boost/simd/arch/common/function/simd/logical_xor.hpp>

#endif
