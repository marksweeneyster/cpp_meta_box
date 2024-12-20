#include "ConstExprBox.hpp"
#include <iostream>


int main() {
  static_assert(en::one < en::two);

  for (const auto sv: ConstExprBox::en_strs) {
    std::cout << sv << '\n';
  }

  for (int ii=-2; ii<9; ++ii) {
    auto val = static_cast<en>(ii);
    std::cout << ConstExprBox::to_str(val) << " ";
  }
  std::cout << '\n';

  for (int ii=0; ii<5; ++ii) {
    std::cout << ConstExprBox::en_arr[ii] << "-";
  }
  std::cout << '\n';

  for (const auto& val: ConstExprBox::en_arr) {
    std::cout << val << ':';
  }
  std::cout << '\n';

}