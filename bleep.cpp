#include <iostream>
#include "functions.hpp"

int main() {
  std::string word = "broccoli";
  std::string text = "broccoli broccoli broccoli";

  bleep(word, text);

  std::cout << text << "\n";

  return 0;
}