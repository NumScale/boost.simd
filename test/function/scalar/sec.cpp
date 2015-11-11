//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/sec.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>


STF_CASE_TPL (" sec",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sec;

  using r_t = decltype(sec(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sec(bs::Inf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Minf<T>()), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Nan<T>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sec(-bs::Pi<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(-bs::Pio_4<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pi<T>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pio_4<T>()), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Zero<T>()), bs::One<r_t>(), 0.5);
}
STF_CASE_TPL (" sec fast_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sec;

  using r_t = decltype(sec(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sec(bs::Inf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Minf<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Nan<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sec(-bs::Pi<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(-bs::Pio_4<T>(), bs::fast_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pi<T>(), bs::fast_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pio_4<T>(), bs::fast_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Zero<T>(), bs::fast_), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" sec clipped_small_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sec;

  using r_t = decltype(sec(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sec(bs::Inf<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Minf<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Nan<T>(), bs::clipped_small_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sec(-bs::Pi<T>(), bs::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(-bs::Pio_4<T>(), bs::clipped_small_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pi<T>(), bs::clipped_small_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pio_4<T>(), bs::clipped_small_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Zero<T>(), bs::clipped_small_), bs::One<r_t>(), 0.5);
}

STF_CASE_TPL (" sec clipped_medium_",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sec;

  using r_t = decltype(sec(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sec(bs::Inf<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Minf<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Nan<T>(), bs::clipped_medium_), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(sec(-bs::Pi<T>(), bs::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(-bs::Pio_4<T>(), bs::clipped_medium_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pi<T>(), bs::clipped_medium_), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Pio_4<T>(), bs::clipped_medium_), bs::Sqrt_2<r_t>(), 0.5);
  STF_ULP_EQUAL(sec(bs::Zero<T>(), bs::clipped_medium_), bs::One<r_t>(), 0.5);
}
