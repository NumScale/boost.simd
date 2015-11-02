//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOGB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ILOGB_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/scalar/is_gtz.hpp>
#include <boost/simd/function/scalar/exponent.hpp>
#include <boost/simd/math.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/make_dependent.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::integer_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0 ) const BOOST_NOEXCEPT
    {
      return impl(a0, typename brigand::bool_<sizeof(A0) >= 4>::type());
    }

    static BOOST_FORCEINLINE A0 impl( A0  a0,  brigand::true_ const &) BOOST_NOEXCEPT
    {
      using f_t = bd::as_floating_t<A0> ;
      return bs::ilogb(f_t(a0));
    }
     static BOOST_FORCEINLINE A0 impl( A0  a0,  brigand::false_ const &) BOOST_NOEXCEPT
    {
      using f_t = typename detail::make_dependent<float, A0>::type;
      return bs::ilogb(f_t(a0));
    }
  };

#ifdef BOOST_SIMD_HAS_ILOGB
  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::double_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0 ) const BOOST_NOEXCEPT
    {
      return is_gtz(a0) ? ::ilogb(a0) : Zero<result_t>();
    }
  };
#endif

#ifdef BOOST_SIMD_HAS_ILOGBF
  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::single_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0 ) const BOOST_NOEXCEPT
    {
      return is_gtz(a0) ? ::ilogbf(a0) : Zero<result_t>();
    }
  };
#endif

  BOOST_DISPATCH_OVERLOAD ( ilogb_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0, signed>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0 ) const BOOST_NOEXCEPT
    {
      return is_gtz(a0) ? bs::exponent(a0) : Zero<result_t>();
    }
  };
} } }


#endif
