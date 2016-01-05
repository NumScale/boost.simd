//==================================================================================================
/*
  Copyright 2009 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using pack_t = boost::simd::pack<T, N>;
  pack_t p;

  STF_EXPECT_NOT(p.empty());

  STF_EQUAL(p.size(), N);
  STF_EQUAL(p.max_size(), N);
  STF_EQUAL(typename pack_t::size_type{pack_t::static_size}, N);

  STF_TYPE_IS(typename pack_t::value_type, T);
}

STF_CASE_TPL( "Check pack's concepts" , STF_NUMERIC_TYPES)
{
  test<T,  2>($);
  test<T,  4>($);
  test<T,  8>($);
  test<T, 16>($);
  test<T, 32>($);
}
