#include <iostream>
#include "functions.hpp"

std::string replacement_word(std::string word) {
  std::string replacement;

  for (int i = 0; i < word.size(); i++) {
    replacement += "*";
  }
  return replacement;
}

void asterisk_replacement(std::string const word, std::string &text, int position) {
  for (int i = 0; i < word.size(); i++) {
    text[i] = '*';
  }
}


void bleep(std::string const word, std::string &text) {
  size_t position = 0;

  while ((position = text.find(word, position)) != std::string::npos) {
    //text.replace(position, word.size(), replacement_word(word));
    asterisk_replacement(word, text, position);
  }
}