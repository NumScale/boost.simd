//==================================================================================================
/*!

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/pow.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/eight.hpp>
#include <boost/simd/constant/third.hpp>
#include <boost/simd/constant/ratio.hpp>

STF_CASE_TPL("pow",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using r_t =  decltype(pow(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<T>(), bs::Minf<T>()), bs::Nan<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Inf<T>(), bs::Minf<T>()), bs::Zero<r_t>(), 0);
#endif
  STF_ULP_EQUAL(pow(T(-1),T(6)), T(1), 0);
  STF_ULP_EQUAL(pow(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::One<T>(), bs::One<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Zero<T>(), bs::Zero<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(pow(T(-1),T(5)), T(-1), 0);
  STF_ULP_EQUAL(pow(bs::Zero<T>(), bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(pow(T(8),bs::Third<T>()), r_t(2), 0.5);
}

STF_CASE_TPL("powreal_int",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using iT = bd::as_integer_t<T>;
  using r_t =  decltype(pow(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  #ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(pow(bs::Inf<T>(),3), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Minf<T>(),3), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(pow(bs::Nan<T>(),3), bs::Nan<r_t>(), 0);
  #endif

  STF_ULP_EQUAL(pow(bs::Two<T>(),-3), (bs::Ratio<r_t, 1, 8>()),  0);
 }

STF_CASE_TPL("powint",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::pow;
  using iT = bd::as_integer_t<T>;
  using r_t =  decltype(pow(T(), iT()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(pow(bs::Mone<T>(),3), bs::Mone<r_t>());
  STF_EQUAL(pow(bs::Mone<T>(),4), bs::One<r_t>());
  STF_EQUAL(pow(bs::One<T>(),3),  bs::One<r_t>());
  STF_EQUAL(pow(bs::Two<T>(),3),  bs::Eight<r_t>());
  STF_EQUAL(pow(bs::Zero<T>(),0), bs::One<r_t>());
  STF_EQUAL(pow(bs::Zero<T>(),3), bs::Zero<r_t>());
}

// TODO template version
// STF_CASE("pow static int ")
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::pow;
//   STF_ULP_EQUAL(pow(4.f, boost::mpl::integral_c<unsigned, 3u>()), 64.f, 0);
//   STF_ULP_EQUAL(pow<3>(4.f), 64.f, 0);
//   STF_ULP_EQUAL(pow<-3>(4.f), 0.015625f, 0);
//   STF_ULP_EQUAL(pow<3>(4), 64, 0);
//   STF_ULP_EQUAL(pow(7.f, boost::mpl::integral_c<unsigned, 4u>()), 2401.f, 0);
// }


