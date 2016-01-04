//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/is_nlt.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_nlt integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_nlt;
  using r_t = decltype(is_nlt(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_nlt(bs::One<T>(), bs::One<T>()), r_t(true));
  STF_EQUAL(is_nlt(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(is_nlt(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
} // end of test for integer_

STF_CASE_TPL (" is_nlt real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_nlt;
  using r_t = decltype(is_nlt(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_nlt(bs::Inf<T>(), bs::Inf<T>()), r_t(true));
  STF_EQUAL(is_nlt(bs::Minf<T>(), bs::Minf<T>()), r_t(true));
  STF_EQUAL(is_nlt(bs::Nan<T>(), bs::Nan<T>()), r_t(true));
  STF_EQUAL(is_nlt(bs::One<T>(),bs::Zero<T>()), r_t(true));
  STF_EQUAL(is_nlt(bs::Zero<T>(), bs::Zero<T>()), r_t(true));
} // end of test for floating_

STF_CASE ( "is_nlt bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_nlt;
  using r_t = decltype(is_nlt(bool(), bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_nlt(true, false), true);
  STF_EQUAL(is_nlt(false, true), false);
  STF_EQUAL(is_nlt(true, true), true);
  STF_EQUAL(is_nlt(false, false), true);
}
