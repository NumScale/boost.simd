//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/exp2.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/is_flint.hpp>

STF_CASE_TPL ( "exp2",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::exp2;
  using r_t = decltype(exp2(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(exp2(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(exp2(bs::Mone<T>()), bs::Half<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::One<T>()), bs::Two<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Zero<T>()), bs::One<r_t>(), 0);

 for(int i=0; i < 100 ; i++)
 {
   STF_EXPECT(bs::is_flint(exp2(T(i))));
 }
}

STF_CASE_TPL ( "exp2 std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  using bs::exp2;
  using r_t = decltype(exp2(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(exp2(bs::Inf<T>(), bs::std_), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Minf<T>(), bs::std_), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(exp2(bs::Mone<T>(), bs::std_), bs::Half<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::One<T>(), bs::std_), bs::Two<r_t>(), 0);
  STF_ULP_EQUAL(exp2(bs::Zero<T>(), bs::std_), bs::One<r_t>(), 0);

 for(int i=0; i < 100 ; i++)
 {
   STF_EXPECT(bs::is_flint(exp2(T(i), bs::std_)));
 }
}


