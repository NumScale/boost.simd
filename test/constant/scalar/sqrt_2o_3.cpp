//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/sqrt_2o_3.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check sqrt_2o_3 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::sqrt_2o_3;
  using boost::simd::Sqrt_2o_3;

  STF_TYPE_IS(decltype(Sqrt_2o_3<T>()), T);
  STF_EQUAL(Sqrt_2o_3<T>(), T(0));
  STF_EQUAL(sqrt_2o_3( as(T{}) ),T(0));
}

STF_CASE_TPL( "Check sqrt_2o_3 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::sqrt_2o_3;
  using boost::simd::Sqrt_2o_3;
  using boost::simd::Ratio;

  STF_TYPE_IS(decltype(Sqrt_2o_3<T>()), T);

  auto z1 = Sqrt_2o_3<T>();
  STF_ULP_EQUAL(z1*z1, (Ratio<T,2,3>()), 0.5);

  auto z2 = sqrt_2o_3( as(T{}) );
  STF_ULP_EQUAL(z2*z2, (Ratio<T,2,3>()), 0.5);

}
