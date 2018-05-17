#ifndef __CPP_PACKED_TUPLE_METAPROG_TYPELIST_HPP__
#define __CPP_PACKED_TUPLE_METAPROG_TYPELIST_HPP__

#include <tuple>

namespace metaprog {

template <class... Args>
struct type_list
{
   template <std::size_t N>
   using type = typename std::tuple_element<N, std::tuple<Args...>>::type;

   template <std::size_t N>
   static constexpr size_t mem_offset()
   {
     if constexpr (N == 0) {
       return 0;

     } else {
       return mem_offset<N - 1>() + sizeof(type<N - 1>);
     }
   }
};

} // end of namespace metaprog

#endif // __CPP_PACKED_TUPLE_METAPROG_TYPELIST_HPP__


