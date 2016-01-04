//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/idivfix.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>

STF_CASE_TPL (" idivfix real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivfix;
  using r_t = decltype(idivfix(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(idivfix(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivfix(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(idivfix(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
 STF_EQUAL(idivfix(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(idivfix(bs::Mone<T>(),bs::Zero<T>()), bs::Minf<r_t>());
  STF_EQUAL(idivfix(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivfix(bs::One<T>(),bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(idivfix(bs::One<T>(),bs::Mzero<T>()), bs::Valmin<r_t>());
  STF_EQUAL(idivfix(bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivfix(T(4),T(3)), r_t(1));
  STF_EQUAL(idivfix(T(-4),T(-3)), r_t(1));
  STF_EQUAL(idivfix(T(-4),T(3)), r_t(-1));
  STF_EQUAL(idivfix(T(4),T(-3)), r_t(-1));
} // end of test for floating_

STF_CASE_TPL (" idivfix unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivfix;
  using r_t = decltype(idivfix(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(idivfix(T(4),T(3)), T(1));
  STF_EQUAL(idivfix(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivfix(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" idivfix signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivfix;
  using r_t = decltype(idivfix(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(idivfix(T(4),T(3)), r_t(1));
  STF_EQUAL(idivfix(T(-4),T(-3)), r_t(1));
  STF_EQUAL(idivfix(T(-4),T(3)), r_t(-1));
  STF_EQUAL(idivfix(T(4),T(-3)), r_t(-1));
  STF_EQUAL(idivfix(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(idivfix(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivfix(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(idivfix(bs::Mone<T>(), bs::Zero<T>()), bs::Valmin<r_t>());
} // end of test for signed_int_


