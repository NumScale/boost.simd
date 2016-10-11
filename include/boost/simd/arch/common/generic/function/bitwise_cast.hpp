//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_BITWISE_CAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_BITWISE_CAST_HPP_INCLUDED

#include <boost/simd/detail/dispatch/as.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
#include <boost/simd/logical.hpp>
#include <cstring>
#include <type_traits>


namespace boost { namespace simd { namespace ext
{
 namespace bd = boost::dispatch;

  template<typename T> inline std::string type_id()
  {
    typedef std::is_const<typename std::remove_reference<T>::type>  const_t;
    typedef std::is_lvalue_reference<T>                             lref_t;
    typedef std::is_rvalue_reference<T>                             rref_t;
    std::string s = boost::core::demangle(typeid(T).name());
    s += const_t::value ? " const"  : "";
    s += lref_t::value   ? "&"      : "";
    s += rref_t::value   ? "&&"     : "";
    return s;
  }
  template<typename T> inline std::string type_id( const T& )
  {
    return type_id<T>();
  }

  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::unspecified_<A0> >
                          , bd::target_< bd::generic_< bd::unspecified_<A1> > >
                          )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return do_(a0, typename std::is_same<A0, result_t>::type());
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type const& ) const BOOST_NOEXCEPT
    {
      result_t that;
      std::cout << "MEMCPY " << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
      std::memcpy(&that, &a0, sizeof(a0));
      return that;
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
    {
      return a0;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::target_< bd::generic_< bd::unspecified_<A1> > >
                          )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return do_(a0, typename std::is_same<A0, result_t>::type());
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type ) const BOOST_NOEXCEPT
    {
      //    std::cout << "ARITHMETIC --> UNSPECIFIED" << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
      return a0.storage();
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
    {
      return a0;
    }

  };

//   BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
//                           , (typename A0, typename A1)
//                           , bd::cpu_
//                           , bd::generic_< bd::int_<A0> >
//                           , bd::target_< bd::generic_< bd::uint_<A1> > >
//                           )
//   {
//     using result_t =  typename A1::type;

//     static_assert
//     ( (sizeof(A0) == sizeof(typename A1::type))
//     , "boost.simd target is not same size as source in bitwise_cast"
//     );

//     BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
//     {
//       return do_(a0, typename std::is_same<A0, result_t>::type());
//     }

//     BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type ) const BOOST_NOEXCEPT
//     {
//       std::cout << "SIGNED --> UNSIGNED " << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
//       return a0.storage();
//     }

//     BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
//     {
//       return a0;
//     }

//   };

  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bs::logical_<A0> >
                          , bd::target_< bd::generic_< bd::unspecified_<A1> > >
                          )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return do_(a0, typename std::is_same<A0, result_t>::type());
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type ) const BOOST_NOEXCEPT
    {
//      std::cout << "LOGICAL --> UNSPECIFIED" << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
      return a0.storage();
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
    {
      return a0;
    }

  };

//   BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
//                           , (typename A0, typename A1)
//                           , bd::cpu_
//                           , bd::generic_< bd::unspecified_<A0> >
//                           , bd::target_< bd::generic_< bs::logical_<A1> > >
//                           )
//   {
//     using result_t =  typename A1::type;

//     static_assert
//     ( (sizeof(A0) == sizeof(typename A1::type))
//     , "boost.simd target is not same size as source in bitwise_cast"
//     );

//     BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
//     {
//       return do_(a0, typename std::is_same<A0, result_t>::type());
//     }

//     BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type ) const BOOST_NOEXCEPT
//     {
//       std::cout << "TO_LOGICAL " << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
//       return a0.storage();
//     }

//     BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
//     {
//       return a0;
//     }

//   };


} } }

#endif
