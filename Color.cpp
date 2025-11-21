#include "Color.hpp"
#include <iomanip>

Color::Color() : redChannel(0), greenChannel(0), blueChannel(0) {}

Color::Color(int red, int green, int blue) {
  redChannel   = CLIP(red);
  greenChannel = CLIP(green);
  blueChannel  = CLIP(blue);
}

Color Color::fromPackedRgb(unsigned int packedRgb) {
  return Color(int((packedRgb >> 16) & 0xffu),
         int((packedRgb >> 8)  & 0xffu),
         int( packedRgb      & 0xffu));
}

Color Color::fromHexLiteral(const char* hexString) {
  if (!hexString || hexString[0] != '#') {
    throw std::invalid_argument("hex literal must start with #");
  }
  int digits[6];
  for (int i = 0; i < 6; ++i) {
    int val = ColorUtility::fromHexDigit(hexString[i + 1]);
    if (val < 0) {
      throw std::invalid_argument("invalid hex digit");
    }
    digits[i] = val;
  }
  return Color(digits[0]*16 + digits[1],
         digits[2]*16 + digits[3],
         digits[4]*16 + digits[5]);
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
  os << '#' << std::hex << std::setfill('0') << std::setw(2) << color.red()
         << std::setw(2) << color.green()
         << std::setw(2) << color.blue() << std::dec;
  return os;
}

std::istream& operator>>(std::istream& is, Color& color) {
  std::string token;
  is >> token;
  color = Color::fromHexLiteral(token.c_str());
  return is;
}

