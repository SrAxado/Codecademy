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
  
  std::cout << "Emerald channel colors: R(" << emerald[0] << "), G(" << emerald[1] << "), B(" << emerald[2] << ")" << std::endl;

  Color dusk = sunset + ocean;
  // The dusk value is #8e6a7f and not #8e6a80 --> (00 + ff) / 02 = 7f
  std::cout << "Dusk: " << dusk << std::endl;

  std::vector<int> warmUp = {30, -10, -10};
  // dusk = dusk + warmUp;
  dusk += warmUp;
  std::cout << "Dusk: " << dusk << std::endl;

  ++dusk;
  std::cout << "Dusk: " << dusk << std::endl;

  sunset--;
  std::cout << "Sunset: " << sunset << std::endl;

  Color duskBoost = dusk * 2;
  std::cout << "Dusk boost: " << duskBoost << std::endl;

  std::cout << "Dusk: " << dusk(ColorUtility::invert) << std::endl;

  std::cout << "Is Dusk equal to Dusk boost?  " << (dusk == duskBoost) << std::endl;

  std::cout << "Dusk is " << (dusk < sunset) << " Sunset" << std::endl;

}


/*
OUTPUT:

    Emerald channel colors: R(80), G(200), B(120)
    Dusk: #8e6a7f
    Dusk: #ac6075
    Dusk: #ad6176
    [Color] Value -1 was out of range and has been clamped to 0 (0-255).
    Sunset: #fe4400
    [Color] Value 346 was out of range and has been clamped to 255 (0-255).
    Dusk boost: #ffc2ec
    Dusk: #529e89
    Is Dusk equal to Dusk boost?  false
    Dusk is darker or equal than Sunset


*/