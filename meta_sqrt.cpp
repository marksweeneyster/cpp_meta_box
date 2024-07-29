/**
* Taken from section 23.1.1 of "C++ Templates" (2nd ed.)
*
* An example of "Value Metaprogramming"
*/


/**
 * return floor of sqrt
 */
template<typename T>
constexpr T sqrt(T x) {
  if (x <= 1) {
    return x;
  }
  static constexpr T zero = static_cast<T>(0);
  static constexpr T one  = static_cast<T>(1);
  static constexpr T two  = static_cast<T>(2);

  T lo = zero;
  T hi = x;

  for (;;) {
    auto mid     = (hi + lo) / two;
    auto squared = mid * mid;
    if (lo + one >= hi || squared == x) {
      return mid;
    }
    if (squared < x) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
}

int main() {
  static_assert(sqrt(2) == 1, "huh?");
  static_assert(sqrt(25L) == 5L, "huh?");
  static_assert(sqrt(30L) == 5L, "huh?");
  static_assert(sqrt(36L) == 5L, "huh?");
  static_assert(sqrt(36UL) == 6UL, "huh?");
}