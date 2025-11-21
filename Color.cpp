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

// Non-const version of the [] operator overload
int& Color::operator[](int index) {
  switch (index) {
    case 0:
      return redChannel;
    case 1:
      return greenChannel;
    case 2:
      return blueChannel;
    default:
      throw std::out_of_range("Color index");
  }
}

// Const version of the [] operator overload -- it returns a copy of the desired channel value
const int Color::operator[](int index) const {
  switch (index) {
    case 0:
      return redChannel;
    case 1:
      return greenChannel;
    case 2:
      return blueChannel;
    default:
      throw std::out_of_range("Color index");
  }
}

// + operator overload that averages each channel of the two colors, returning such Color
  Color Color::operator+(const Color& color2) const {
    return Color((redChannel + color2.red())/2, (greenChannel + color2.green())/2, (blueChannel + color2.blue())/2);
  }
  // Adds adjustments to each channel, clamping to 0 - 255
  Color& Color::operator+=(const Color& color2) {
    redChannel = CLIP((redChannel + color2.red()) / 2);
    greenChannel = CLIP((greenChannel + color2.green()) / 2);
    blueChannel = CLIP((blueChannel + color2.blue()) / 2);
    return *this;
  }

  // + operator overload that varies the RGB values by a vector of adjustments
  Color Color::operator+(const std::vector<int>& adjustments) const {
    int newRed = redChannel + (adjustments.size() > 0 ? adjustments[0] : 0); 
    int newGreen = greenChannel + (adjustments.size() > 1 ? adjustments[1] : 0);
    int newBlue = blueChannel + (adjustments.size() > 2 ? adjustments[2] : 0);
    return Color(CLIP(newRed), CLIP(newGreen), CLIP(newBlue));
  }
  // Corresponding += operator overload
  Color& Color::operator+=(const std::vector<int>& adjustments) {
    redChannel = CLIP(redChannel + (adjustments.size() > 0 ? adjustments[0] : 0));
    greenChannel = CLIP(greenChannel + (adjustments.size() > 1 ? adjustments[1] : 0));
    blueChannel = CLIP(blueChannel + (adjustments.size() > 2 ? adjustments[2] : 0));
    return *this;
  }

  Color& Color::operator++() {
   redChannel =  CLIP(redChannel + 1);
    greenChannel = CLIP(greenChannel + 1);
    blueChannel = CLIP(blueChannel + 1);
    return *this;
  }

  Color Color::operator++(int) {
    Color currentColor = *this;
    redChannel = CLIP(redChannel + 1);
    greenChannel = CLIP(greenChannel + 1);
    blueChannel = CLIP(blueChannel + 1);
    return currentColor;
  }

  Color Color::operator-(const Color& color2) const {
    int newRed = CLIP((redChannel - color2.red()) / 2);
    int newGreen = CLIP((greenChannel - color2.green()) / 2);
    int newBlue = CLIP((blueChannel - color2.blue()) / 2);
    return Color(newRed, newGreen, newBlue);
  }

  Color& Color::operator-=(const Color& color2) {
    redChannel = CLIP((redChannel - color2.red()) / 2);
    greenChannel = CLIP((greenChannel - color2.green()) / 2);
    blueChannel = CLIP((blueChannel - color2.blue()) / 2);
    return *this;
  }

  Color Color::operator-(const std::vector<int>& adjustments) const {
    int newRed = redChannel - (adjustments.size() > 0 ? adjustments[0] : 0); 
    int newGreen = greenChannel - (adjustments.size() > 1 ? adjustments[1] : 0);
    int newBlue = blueChannel - (adjustments.size() > 2 ? adjustments[2] : 0);
    return Color(CLIP(newRed), CLIP(newGreen), CLIP(newBlue));
  }

  Color& Color::operator-=(const std::vector<int>& adjustments) {
    redChannel = CLIP(redChannel - (adjustments.size() > 0 ? adjustments[0] : 0));
    greenChannel = CLIP(greenChannel - (adjustments.size() > 1 ? adjustments[1] : 0));
    blueChannel = CLIP(blueChannel - (adjustments.size() > 2 ? adjustments[2] : 0));
    return *this;
  }

  Color& Color::operator--() {
    redChannel = CLIP(redChannel - 1);
    greenChannel = CLIP(greenChannel - 1);
    blueChannel = CLIP(blueChannel - 1);
    return *this;
  }


  Color Color::operator--(int) {
    Color currentColor = *this;
    redChannel = CLIP(redChannel - 1);
    greenChannel = CLIP(greenChannel - 1);
    blueChannel = CLIP(blueChannel - 1);
    return currentColor;
  }

  Color Color::operator*(int scale) const {
    int newRed = CLIP(redChannel * scale);
    int newGreen = CLIP(greenChannel * scale);
    int newBlue = CLIP(blueChannel * scale);
    return Color(newRed, newGreen, newBlue);
  }

  Color& Color::operator*=(int scale) {
    redChannel = CLIP(redChannel * scale);
    greenChannel = CLIP(greenChannel * scale);
    blueChannel = CLIP(blueChannel * scale);
    return *this;
  }

  bool Color::operator==(const Color& color2) const {
    return ((redChannel == color2.red()) and (greenChannel == color2.green()) and (blueChannel == color2.blue()));
  }

  bool Color::operator!=(const Color& color2) const {
    return ((redChannel != color2.red()) or (greenChannel != color2.green()) or (blueChannel != color2.blue()));
  }

  std::string Color::operator<(const Color& color2) const {
    return ((redChannel < color2.red()) and (greenChannel < color2.green()) and (blueChannel < color2.blue()) ?
      "ligther than" : "darker or equal than");
  }

  std::string Color::operator<=(const Color& color2) const {
    return ((redChannel <= color2.red()) and (greenChannel <= color2.green()) and (blueChannel <= color2.blue()) ?
       "lighter or equal than" : "darker than");
  }

  std::string Color::operator>(const Color& color2) const {
    return ((redChannel > color2.red()) and (greenChannel > color2.green()) and (blueChannel > color2.blue()) ?
      "darker than" : "lighter or equal than");
  }

  std::string Color::operator>=(const Color& color2) const {
    return ((redChannel >= color2.red()) and (greenChannel >= color2.green()) and (blueChannel >= color2.blue()) ?
      "darker or equal than" : "lighter than");
  }


  // Functor operator
  Color Color::operator()(int (*transform)(int)) const {
    int newRed = CLIP(transform(redChannel));
    int newGreen = CLIP(transform(greenChannel));
    int newBlue = CLIP(transform(blueChannel));
    return Color(newRed, newGreen, newBlue);
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

