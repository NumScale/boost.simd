//==================================================================================================
/*!
  @file

  Defines the SSE4A specifications

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4A_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4A_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_AMD_SSE4A_VERSION

#ifndef BOOST_SIMD_DEFAULT_FAMILY
  #define BOOST_SIMD_DEFAULT_FAMILY  ::boost::simd::sse_
#endif

#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::sse4a_

#include <ammintrin.h>
#include <boost/simd/arch/x86/sse2/as_simd.hpp>

#endif
#endif
