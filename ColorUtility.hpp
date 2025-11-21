#pragma once
#include <algorithm>
#include <stdexcept>
#include <iostream>

#define CLIP(v) ColorUtility::clipToChannelRange(v)

class ColorUtility {
public:
  // Convert a 0‑15 value to its hexadecimal digit
  static char toHexDigit(int value);

  // Convert a hexadecimal character (0‑9, a‑f, A‑F) to its numeric value
  static int fromHexDigit(char hexCharacter);

  // Clamp an integer to the valid 0‑255 range
  static int clipToChannelRange(int value);

  // Invert an 8-bit colour channel (0 → 255, 255 → 0, &c.)
  static int invert(int channelValue);
};
