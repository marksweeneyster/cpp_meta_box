//
// Created by mark_ on 12/20/2024.
//

#ifndef CPP_META_BOX__CONSTEXPRBOX_HPP
#define CPP_META_BOX__CONSTEXPRBOX_HPP

#include <array>
#include <string_view>
#include <iostream>

enum class en { zero = 0, one, two, three, count };

class ConstExprBox{

  inline static constexpr int num_nums = static_cast<int>(en::count);

public:
  inline static constexpr std::array<en, num_nums + 1> en_arr = {
          en::zero, en::one, en::two, en::three, en::count};

  inline static constexpr std::array<std::string_view, num_nums + 1> en_strs = {
          "zero", "one", "two", "three", "count"};

  static constexpr std::string_view to_str(en val) {
    if (val < en::zero || val > en::count) return {};
    return en_strs[static_cast<int>(val)];
  }
};
std::ostream& operator<<(std::ostream& os, const en val);


#endif//CPP_META_BOX__CONSTEXPRBOX_HPP
