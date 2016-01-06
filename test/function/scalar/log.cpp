//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/log.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/options.hpp>

STF_CASE_TPL (" log",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log;

  using r_t = decltype(log(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log(bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log(bs::Mone<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Mzero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Zero<T>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Two<T>()), bs::Log_2<r_t>(), 0);
}


STF_CASE_TPL (" log std",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::log;
  using bs::std_;

  using r_t = decltype(log(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(log(bs::Inf<T>(), bs::std_), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Minf<T>(), bs::std_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Nan<T>(), bs::std_), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(log(bs::Mone<T>(), bs::std_), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Mzero<T>(), bs::std_), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Zero<T>(), bs::std_), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::One<T>(), bs::std_), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(log(bs::Two<T>(), bs::std_), bs::Log_2<r_t>(), 0);
}
