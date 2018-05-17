#ifndef __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__
#define __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__

#include <utility>
#include <memory>
#include <array>
#include <numeric>
#include "metaprog_utils.hpp"

// TODO only primitive types
template <typename ...ContentTypes>
class PackedTuple
{
  public:
    static constexpr size_t kSize = sizeof...(ContentTypes);
    static constexpr size_t kByteSize = metaprog::SizeOf<ContentTypes...>();

    using TypeList = metaprog::type_list<ContentTypes...>;

    template <size_t I>
    using Type = typename TypeList::template type<I>;

  public:
    PackedTuple()
      : raw_data_()
    {
    }

    PackedTuple(ContentTypes... args)
      : raw_data_()
    {
      Init<0>(std::forward<ContentTypes>(args)...);
    }

    // TODO copy/move ops

  public:
    template <size_t I>
    Type<I>& Get()
    {
      uint8_t* ptr = raw_data_.data() + TypeList::template mem_offset<I>();

      return *reinterpret_cast<Type<I>*>(ptr);
    }

    template <size_t I>
    Type<I> const& Get() const
    {
      uint8_t const* ptr = raw_data_.data()
                           + TypeList::template mem_offset<I>();

      return *reinterpret_cast<Type<I> const*>(ptr);
    }

  private:
    template <size_t I, typename T, typename ...Args>
    void Init(T&& current, Args&&... args)
    {
      Get<I>() = current;

      if constexpr (I < kSize - 1) {
        Init<I + 1>(std::forward<Args>(args)...);
      }
    }

  private:
    std::array<uint8_t, kByteSize> raw_data_;
};

#endif // __CPP_PACKED_TUPLE_PACKED_TUPLE_HPP__
