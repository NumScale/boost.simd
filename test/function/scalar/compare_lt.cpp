//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/compare_lt.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" compare_lt",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using bs::compare_lt;
  using r_t = decltype(compare_lt(T(), T()));

  // specific values tests
  STF_EQUAL(compare_lt(bs::One<T>(), bs::One<T>()),  r_t(false));
  STF_EQUAL(compare_lt(bs::One<T>(), bs::Zero<T>()), r_t(false));
  STF_EQUAL(compare_lt(bs::Zero<T>(), bs::One<T>()), r_t(true));

} // end of test for floating_


