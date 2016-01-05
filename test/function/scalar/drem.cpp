//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/drem.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/three.hpp>

STF_CASE_TPL (" drem real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::drem;
  using r_t = decltype(drem(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(drem(bs::Inf<T>(), bs::Inf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(drem(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(drem(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(drem(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(drem(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(drem(bs::One<T>(),bs::Zero<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(drem(bs::Zero<T>(),bs::Zero<T>()), bs::Nan<T>());
} // end of test for floating_

STF_CASE_TPL (" drem signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::drem;
  using r_t = decltype(drem(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(drem(bs::Mone<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(drem(bs::One<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(drem(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(drem(bs::Two<T>(), bs::Three<T>()), bs::Mone<T>());
} // end of test for signed_int_
