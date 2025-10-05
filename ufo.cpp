#include <iostream>
#include <vector>
#include "ufo_functions.hpp"

int main() {
  std::string codeword = "codecademy";
  std::string answer = "__________";
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  int misses = 0;

  while (answer != codeword && misses < 7) {
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "\nPlease enter your guess: ";
    std::cin >> letter;

    for (int i = 0; i < codeword.size(); i++) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }
    if (guess) {
      std::cout << "Correct!\n";
    } else {
      std::cout << "Incorrect! The tractor beam pulls the person in further.\n\n";
      incorrect.push_back(letter);
      misses++;
    }
    
    guess = false;
  }
  
  end_game(answer, codeword);
}
