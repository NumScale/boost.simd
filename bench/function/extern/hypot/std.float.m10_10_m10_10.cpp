// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor hypot in extern mode for float type with std_.
#include <simd_bench.hpp>
#include <boost/simd/function/hypot.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_EXTERN_BENCH(extern_hypot, bs::std_(bs::hypot));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<extern_hypot, float>(-10, 10,-10, 10);
}
