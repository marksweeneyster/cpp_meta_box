//
// Created by mark_ on 12/20/2024.
//

#include "ConstExprBox.hpp"

std::ostream& operator<<(std::ostream& os, const en val)
{
  os << ConstExprBox::to_str(val);
  return os;
}
