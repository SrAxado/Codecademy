#include "ColorUtility.hpp"

char ColorUtility::toHexDigit(int value) {
  if (value < 0 || value > 15) {
    throw std::out_of_range("value must be 0-15");
  }
  if (value < 10) {
    return char('0' + value);
  } else {
    return char('a' + (value - 10));
  }
}

int ColorUtility::fromHexDigit(char hexCharacter) {
  if ('0' <= hexCharacter && hexCharacter <= '9') {
    return hexCharacter - '0';
  }
  if ('a' <= hexCharacter && hexCharacter <= 'f') {
    return 10 + (hexCharacter - 'a');
  }
  if ('A' <= hexCharacter && hexCharacter <= 'F') {
    return 10 + (hexCharacter - 'A');
  }
  return -1;
}

int ColorUtility::clipToChannelRange(int value)
{
  // Clamp to [0, 255]
  int clamped = std::max(0, std::min(255, value));

  // Warn if we had to change the input
  if (clamped != value)
    std::cerr << "[Color] Value " << value
              << " was out of range and has been clamped to "
              << clamped << " (0-255)." << std::endl;

  return clamped;
}

int ColorUtility::invert(int channelValue)
{
  return 255 - channelValue;
}
