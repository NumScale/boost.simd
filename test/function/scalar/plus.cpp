//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/plus.hpp>
#include <simd_test.hpp>
#include <nontrivial.hpp>

STF_CASE_TPL( "Check plus behavior with floating", (double)(float) )
{
  namespace bs = boost::simd;
  using bs::plus;
  using r_t = decltype(plus(T(), T()));
  STF_TYPE_IS(r_t, T);
#ifndef BOOST_SIMD_NO_INVALIDS
//   STF_IEEE_EQUAL(plus(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<r_t>());
//   STF_IEEE_EQUAL(plus(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<r_t>());
//   STF_IEEE_EQUAL(plus(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
//   STF_IEEE_EQUAL(plus(bs::One<T>(),bs::Zero<T>()), bs::One<r_t>());
//   STF_IEEE_EQUAL(plus(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
}

namespace foo
{
  template <class T>
  nontrivial<T> operator +(const nontrivial<T> & z1, const nontrivial<T> z2)
  {
    return perform(z1, z2);
  }
}

STF_CASE_TPL( "Check plus behavior with exotic type", (double)(float) )
{
  namespace bs = boost::simd;
  using bs::plus;
  using foo::nontrivial;
  using r_t = decltype(plus(nontrivial<T>(), nontrivial<T>()));
  STF_TYPE_IS(r_t, nontrivial<T>);

  STF_EQUAL(plus(nontrivial<T>(1, 2), nontrivial<T>(3, 4)), nontrivial<T>(4, 8));
}
