#pragma once
#include <iostream>
#include <vector>
#include "ColorUtility.hpp"

class Color {
public:
  Color();
  Color(int red, int green, int blue);

  static Color fromPackedRgb(unsigned int packedRgb);
  static Color fromHexLiteral(const char* hexString);

  int red() const { return redChannel; }
  int green() const { return greenChannel; }
  int blue() const { return blueChannel; }

  // non-const version of the [] operator overload
  int& operator[](int index);
  // const version of the [] operator overload -- it returns a copy of the desired channel value
  const int operator[](int index) const;

  // + operator overload that averages each channel of the two colors, returning such Color
  Color operator+(const Color& color2) const;
  // Adds adjustments to each channel, clamping to 0 - 255
  Color& operator+=(const Color& color2);
  // + operator overload that varies the RGB values by a vector of adjustments
  Color operator+(const std::vector<int>& adjustments) const;
  // Corresponding += operator overload
  Color& operator+=(const std::vector<int>& adjustments);
  Color& operator++();  // Prefix increment operator
  Color operator++(int);  // Postfix increment operator
  
  Color operator-(const Color& color2) const;
  Color& operator-=(const Color& color2);
  Color operator-(const std::vector<int>& adjustments) const;
  Color& operator-=(const std::vector<int>& adjustments);
  Color& operator--();  // Prefix decrement operator
  Color operator--(int);  // Postfix increment operator
  
  // * operator overload
  Color operator*(int scale) const;
  Color& operator*=(int scale);

  bool operator==(const Color& color2) const;
  bool operator!=(const Color& color2) const;
  std::string operator<(const Color& color2) const;
  std::string operator<=(const Color& color2) const;
  std::string operator>(const Color& color2) const;
  std::string operator>=(const Color& color2) const;

  Color operator()(int (*transform)(int)) const;



private:
  int redChannel;
  int greenChannel;
  int blueChannel;
};

std::ostream& operator<<(std::ostream& os, const Color& color);
std::istream& operator>>(std::istream& is, Color& color);

