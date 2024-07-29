/**
 * "Value Metaprogramming", section 23.1.1 of "C++ Templates" (2nd ed.)
 */

constexpr bool is_prime(unsigned int val) {
  for (unsigned int d=2; d<=val/2; ++d) {
    if ( val % d == 0 ) {
      return false;
    }
  }
  return val > 1;
}

int main() {
  // compile time evaluations
  constexpr unsigned int cval = 11;
  constexpr auto b11 = is_prime(cval);
  static_assert(is_prime(cval)==true, "11 is prime?");
  static_assert(is_prime(8)==true, "8 is prime?");

  unsigned int val = 8;
  bool b9 = is_prime(++val);
  // "b9" is not known at compile time
  static_assert(b9==true, "9 is prime?");

}