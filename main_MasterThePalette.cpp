#include <iostream>
#include <vector>
#include "Color.hpp"

int main() {
  std::cout << std::boolalpha;  // print bools as true/false

  // You can give this color in two equivalent ways:
  //
  // 1. Hex (base-16): 0x50C878
  // 2. Decimal RGB (base-10): 80, 200, 120
  //
  // Each pair of hex digits converts to its decimal RGB value:
  // 0x50 → 80, 0xC8 → 200, 0x78 → 120
  Color emerald = Color::fromHexLiteral("#50c878");
  Color sunset = Color::fromHexLiteral("#ff4500");
  Color ocean  = Color::fromHexLiteral("#1e90ff");
  
  

}