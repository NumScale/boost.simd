//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/is_nge.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_nge integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_nge;
  using r_t = decltype(is_nge(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_nge(bs::One<T>(), bs::One<T>()), r_t(false));
  STF_EQUAL(is_nge(bs::One<T>(),bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_nge(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for integer_

STF_CASE_TPL (" is_nge real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_nge;
  using r_t = decltype(is_nge(T(), T()));

  // return type conformity test
 STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_nge(bs::Inf<T>(), bs::Inf<T>()), r_t(false));
  STF_EQUAL(is_nge(bs::Minf<T>(), bs::Minf<T>()), r_t(false));
  STF_EQUAL(is_nge(bs::Nan<T>(), bs::Nan<T>()), r_t(true));
  STF_EQUAL(is_nge(bs::One<T>(),bs::Zero<T>()), r_t(false));
  STF_EQUAL(is_nge(bs::Zero<T>(), bs::Zero<T>()), r_t(false));
} // end of test for floating_

STF_CASE ( "is_nge bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_nge;

  using r_t = decltype(is_nge(bool(), bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);


  // specific values tests
  STF_EQUAL(is_nge(true, false), false);
  STF_EQUAL(is_nge(false, true), true);
  STF_EQUAL(is_nge(true, true), false);
  STF_EQUAL(is_nge(false, false), false);
}
