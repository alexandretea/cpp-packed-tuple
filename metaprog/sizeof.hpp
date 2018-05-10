#ifndef __CPP_PACKED_TUPLE_METAPROG_SIZEOF_HPP__
#define __CPP_PACKED_TUPLE_METAPROG_SIZEOF_HPP__

#include <array>
#include <tuple>
#include "accumulate.hpp"

namespace metaprog {

// Just an alias for an std::array built from packed parameters
template <typename ...T>
using SizeArray = std::array<size_t, sizeof...(T)>;

template <typename ...T>
constexpr SizeArray<T...> SizeOfEach()
{
  return SizeArray<T...> { sizeof(T)... };
}

template <typename ...T>
constexpr size_t  SizeOf()
{
  return Accumulate<size_t, sizeof...(T)>(SizeOfEach<T...>());
}

} // end of namespace metaprog

#endif // __CPP_PACKED_TUPLE_METAPROG_SIZEOF_HPP__

