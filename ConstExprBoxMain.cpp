#include "ConstExprBox.hpp"
#include <iostream>

int main() {

  for (const auto sv: ConstExprBox::en_arr) {
    std::cout << sv << '\n';
  }

  static_assert(en::one < en::two);

  for (int ii=-2; ii<9; ++ii) {
    auto val = static_cast<en>(ii);
    std::cout << ConstExprBox::to_str(val) << " ";
  }
  std::cout << '\n';
}