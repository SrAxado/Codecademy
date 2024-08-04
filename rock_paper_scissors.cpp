/* Rock, Paper, Scissors, Lizard, Spock is a simple battle game
between of forces of nature!!

-- Scissors cuts Paper;
-- Paper covers Rock;
-- Rock crushes Lizard;
-- Lizard poisons Spock;
-- Spock smashes Scissors;
-- Scissors decapitates Lizard;
-- Lizard eats Paper;
-- Paper disproofs Spock;
-- Spock vaporizes Rock;
-- Rock crushes Scissors.

Rock --> 0
Paper --> 1
Scissors --> 2
Lizard --> 3
Spock --> 4

*/

#include <iostream>
#include <cstdlib>
use namespace std;

int main() {
  // Live long and prosper
  enum possibilities {Rock, Paper, Scissors, Lizard, Spock};
  srand(time(NULL));
  int computer = std::rand() % 5;

  std::string answer;
  int numAnswer;

  std::cout << "    +-------------------------------------------------+\n";
  std::cout << "    |        Rock, Paper, Scissors, Lizard, Spock     |\n";
  std::cout << "    +-------------------------------------------------+\n\n";

  std::cout << "Shoot: ";
  std::cin >> answer;

  std::cout << "Computer shoot ";
  switch (computer) {
    case 0:
      std::cout << "Rock\n";
      break;
    case 1:
      std::cout << "Paper\n";
      break;
    case 2:
      std::cout << "Scissors\n";
      break;
    case 3:
      std::cout << "Lizard\n";
      break;
    case 4:
      std::cout << "Spock\n";
      break;
    default:
      std::cout << "This shouldn't have happened!";
      break;
  }
  
  if (answer == "Rock") {
    numAnswer = Rock;
  } else if (answer == "Paper") {
    numAnswer = Paper;
  } else if (answer == "Scissors") {
    numAnswer = Scissors;
  } else if (answer == "Lizard") {
    numAnswer = Lizard;
  } else if (answer == "Spock") {
    numAnswer = Spock;
  } else {
    numAnswer = 6;
  }


  switch (numAnswer) {
    case 0: // "Rock"
      if (computer == 3 || computer == 2) {
        std::cout << "YOU WIN!!!\n";
      } else if (computer == 1 || computer == 4) {
        std::cout << "You lose!\n";
      } else {
        std::cout << "Tie! Play again.\n";
      }
      break;
    case 1: // "Paper"
      if (computer == 0 || computer == 4) {
        std::cout << "YOU WIN!!!\n";
      } else if (computer == 2 || computer == 3) {
        std::cout << "You lose!\n";
      } else {
        std::cout << "Tie! Play again.\n";
      }
      break;
    case 2: // "Scissors"
      if (computer == 1 || computer == 3) {
        std::cout << "YOU WIN!!!\n";
      } else if (computer == 0 || computer == 4) {
        std::cout << "You lose!\n";
      } else {
        std::cout << "Tie! Play again.\n";
      }
      break;
    case 3: // "Lizard"
      if (computer == 1 || computer == 4) {
        std::cout << "YOU WIN!!!\n";
      } else if (computer == 0 || computer == 2) {
        std::cout << "You lose!\n";
      } else {
        std::cout << "Tie! Play again.\n";
      }
      break;
    case 4: // "Spock"
      if (computer == 0 || computer == 2) {
        std::cout << "YOU WIN!!!\n";
      } else if (computer == 1 || computer == 3) {
        std::cout << "You lose!\n";
      } else {
        std::cout << "Tie! Play again.\n";
      }
      break;
    default:
      std::cout << "Invalid input.\n";
      break;
  }

  return 0;
}