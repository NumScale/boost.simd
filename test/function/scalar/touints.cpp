//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/touints.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/function/ldexp.hpp>

STF_CASE_TPL (" touints signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::touints;
  using r_t = decltype( touints(T()));

  STF_TYPE_IS( r_t, (bd::as_integer_t<T, unsigned>));

//  STF_EQUAL(touints(bs::Mone<T>()), bs::Valmax<r_t>());
  STF_EQUAL(touints(bs::Mone<T>()), bs::Zero<r_t>());
  STF_EQUAL(touints(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(touints(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for signed_int_
