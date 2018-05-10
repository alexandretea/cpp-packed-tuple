#ifndef __CPP_PACKED_TUPLE_METAPROG_ACCUMULATE_HPP__
#define __CPP_PACKED_TUPLE_METAPROG_ACCUMULATE_HPP__

#include <tuple>

namespace metaprog {

template <class... Args>
struct type_list
{
   template <std::size_t N>
   using type = typename std::tuple_element<N, std::tuple<Args...>>::type;
};

} // end of namespace metaprog

#endif // __CPP_PACKED_TUPLE_METAPROG_ACCUMULATE_HPP__


