//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/slide.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, int N, typename Env> void test(Env& $)
{
  std::array<bs::logical<T>,3*N> data;
  for(std::size_t i = 0;i < data.size(); ++i) data[i] = false;
  for(int i = N;i < 2*N; ++i) data[i] = (i%2 != 0);

  using p_t = bs::pack<bs::logical<T>,N>;
  p_t ref, p = bs::load<p_t>(&data[N], 0);

  STF_ULP_EQUAL( bs::slide<-N>(p), bs::Zero<p_t>() , 0.5);

  ref = bs::load<p_t>(&data[N], -1);
  STF_ULP_EQUAL( bs::slide<-1>(p), ref , 0.5);

  ref = bs::load<p_t>(&data[N]);
  STF_ULP_EQUAL( bs::slide<0>(p), ref , 0.5);

  ref = bs::load<p_t>(&data[N], +1);
  STF_ULP_EQUAL( bs::slide<+1>(p), ref , 0.5);

  STF_ULP_EQUAL( bs::slide<N>(p), bs::Zero<p_t>() , 0.5);
}

STF_CASE_TPL( "Check unary slide behavior", STF_NUMERIC_TYPES )
{
  static const int N = bs::pack<bs::logical<T>>::static_size;

  test<T, N  >($);
  test<T, N/2>($);
  test<T, N*2>($);
}
