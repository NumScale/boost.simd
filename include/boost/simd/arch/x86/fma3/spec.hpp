//==================================================================================================
/*!
  @file

  Defines the FMA3 specifications

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_FMA3_SPEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_FMA3_SPEC_HPP_INCLUDED

#include <boost/simd/sdk/predef.hpp>

#if !defined(BOOST_SIMD_DEFAULT_FAMILY)
  #if BOOST_HW_SIMD_X86 == BOOST_HW_SIMD_X86_FMA3_VERSION
    #define BOOST_SIMD_DEFAULT_FAMILY ::boost::simd::avx_
    #define BOOST_SIMD_DEFAULT_SITE   ::boost::simd::fma3_
  #endif
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_FMA3_VERSION
  #include <immintrin.h>
  #include <boost/simd/arch/x86/fma3/as_simd.hpp>
  #include <boost/simd/arch/x86/fma3/pack_traits.hpp>
#endif

#endif
