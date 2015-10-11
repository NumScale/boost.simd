//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/twoto31.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check twoto31 behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::twoto31;
  using boost::simd::Twoto31;

  STF_TYPE_IS(decltype(Twoto31<T>()), T);
  STF_EQUAL(Twoto31<T>(), T(1ULL << 31));
  STF_EQUAL(twoto31( as(T{}) ),T(1ULL << 31));
}

STF_CASE_TPL( "Check twoto31 behavior for floating types"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::twoto31;
  using boost::simd::Twoto31;

  STF_TYPE_IS(decltype(Twoto31<T>()), T);
  STF_IEEE_EQUAL(Twoto31<T>(), T(2147483648));
  STF_IEEE_EQUAL(twoto31( as(T{}) ), T(2147483648));
}
