/*
An uninsteresting and far from poetic adventure!!

-- should contain three branch points:
   * each branch point should give the user at least two choices;
   * every story branch needs its won ending; it can also add something and reconnect with another storyline.
-- should incorporate at least one kind of loop:
   * to validate user input;
   * give multiple choices to choose a specific outcome (e.g. three chances to pick an option that won't get them killed);
   * to continue the adventure until th user makes a particular choice
   --> while loops that include user input in Codecademy's platform will trigger an infinit loop --> use for loops
-- when the user reachs an ending, return 0 to exit

A -- B1 - C1 - D1 - END1
                  - C2
             - D3
        - C2 - D2 - E1 - F1 - G1 - END3
                                 - C2
                            - G2 - C3
                                 - C1
                       - C3
                  - E2 - F2 - G3  - END5
                                  - END4
                            - D2
                       - C4
             - D1
   - B2 - C3 - D4 - E3 - END_HAPPY
                       - A
                  - E4 - C1
                       - C2
             - D2
        - C4 - D3 - E2
                  - E5 - B2
                       - END2
             - B1
*/

#include <iostream>

int main() {
  int lifes = 3;
  std::string branch = "A";
  std::string path = "A";
  int previousChoice = 0;
  // std::string previousChoice;
  int choice = 0;

  std::cout << "\n- - - - - - - - - - - - - - - - - -  - - - - - - - - - - - -\n";
  std::cout << "An uninteresting and far from poetic adventure!!\n";
  std::cout << "- - - - - - - - - - - - - - - - - -  - - - - - - - - - - - -\n\n";

  std::cout << "Once upon a time, there was a world that was only made of events. Nothing else mattered besides events and its outcome! The whole point of living would be to walk the events path and reach the best of ends.. while only one would the absolute best be..!\n";
  std::cout << "Let's start our journey! It all began with the EVENT A.\n";

  while (choice != 1000 && choice != -1) {
    std::cout << "\n[ " << path << " ]\n";
    std::cout << "LIFES: " << lifes << "\n\n";
    if (branch == "A") {
      std::cout << "1) EVENT B1\n";
      std::cout << "2) EVENT B2\n";
    } else if (branch == "B1") {
      std::cout << "1) EVENT C1\n";
      std::cout << "2) EVENT C2\n";
    } else if (branch == "B2") {
      std::cout << "1) EVENT C3\n";
      std::cout << "2) EVENT C4\n";
    } else if (branch == "C1") {
      std::cout << "1) EVENT D1\n";
      std::cout << "2) EVENT D3\n";
    } else if (branch == "C2") {
      std::cout << "1) EVENT D2\n";
      std::cout << "2) EVENT D1\n";
    } else if (branch == "C3") {
      std::cout << "1) EVENT D4\n";
      std::cout << "2) EVENT D2\n";
    } else if (branch == "C4") {
      std::cout << "1) EVENT D3\n";
      std::cout << "2) EVENT B1\n";
    }  else if (branch == "D1") {
      std::cout << "1) LIFE OR DEATH EVENT\n";  // END1
      std::cout << "2) LIFE OR DEATH EVENT\n";  // 
    } else if (branch == "D2") {
      std::cout << "1) EVENT E1\n";
      std::cout << "2) EVENT E2\n";
    } else if (branch == "D3") {
      std::cout << "1) EVENT E2\n";
      std::cout << "2) EVENT E5\n";
    } else if (branch == "D4") {
      std::cout << "1) EVENT E3\n";
      std::cout << "2) EVENT E4\n";
    } else if (branch == "E1") {
      std::cout << "1) EVENT F1\n";
      std::cout << "2) EVENT C3\n";
    } else if (branch == "E2") {
      std::cout << "1) EVENT F2\n";
      std::cout << "2) EVENT C4\n";
    } else if (branch == "E3") {
      std::cout << "1) LIFE OR DEATH EVENT\n";  // END_HAPPY
      std::cout << "2) LIFE OR DEATH EVENT\n";  // A - BEGINNING
    } else if (branch == "E4") {
      std::cout << "1) EVENT C1\n";
      std::cout << "2) EVENT C2\n";
    } else if (branch == "E5") {
      std::cout << "1) LIFE OF DEATH EVENT\n";
      std::cout << "2) LIFE OF DEATH EVENT\n";
    } else if (branch == "F1") {
      std::cout << "1) EVENT G1\n";
      std::cout << "2) EVENT G2\n";
    } else if (branch == "F2") {
      std::cout << "1) EVENT G3\n";
      std::cout << "2) EVENT D2\n";
    } else if (branch == "G1") {
      std::cout << "1) LIFE OR DEATH EVENT\n";  // END3
      std::cout << "2) LIFE OR DEATH EVENT\n";  // C2
    } else if (branch == "G2") {
      std::cout << "1) EVENT C3\n";
      std::cout << "2) EVENT C1\n";
    } else if (branch == "G3") {
      std::cout << "1) LIFE OR DEATH EVENT\n";  //END5
      std::cout << "2) LIFE OR DEATH EVENT\n";  //END4
    } else {
      std::cout << "ERROR: you're walking in an unexistent path!!!\n";
      return -1;
    }





    do {
      previousChoice = choice;
      
      std::cout << "Enter your EVENT of choice: ";
      std::cin >> choice;

      if (choice == 1 || choice == 2) {
        if (branch == "A") {
          if (choice == 1)
            branch = "B1";
          else 
            branch = "B2";
        } else if (branch == "B1") {
          if (choice == 1)
            branch = "C1";
          else
            branch = "C2";
        } else if (branch == "B2") {
          if (choice == 1)
            branch = "C3";
          else
            branch = "C4";
        } else if (branch == "C1") {
          if (choice == 1)
            branch = "D1";
          else
            branch = "D3";
        } else if (branch == "C2") {
          if (choice == 1)
            branch = "D2";
          else
            branch = "D1";
        } else if (branch == "C3") {
          if (choice == 1)
            branch = "D4";
          else
            branch = "D2";
        } else if (branch == "C4") {
          if (choice == 1)
            branch = "D3";
          else
            branch = "B1";
        } else if (branch == "D1") {
          if (choice == 1) {
            std::cout << "\nYOU DIED THE FIRST OF MANY HORRIBLE DEATHS!!!\n\n";
            lifes--;
            path += " - END1";

            if (lifes > 0) {
              std::cout << "Would you like to go back to the beginning of the journey or try again where you stand?\n";
              std::cout << "1) go back to the beginning\n";
              std::cout << "2) try again\n";

              do {
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                if (choice == 1 || choice == 2) {
                  if (choice == 1)
                    branch = "A";
                } else {
                  std::cout << "Invalid choice! Please enter a valid choice [1 - 2].\n";
                  choice = 0;
                }
              } while (choice == 0);
            } else
            choice = -1;

          } else 
            branch = "C2";
        } else if (branch == "D2") {
          if (choice == 1)
            branch = "E1";
          else
            branch = "E2";
        } else if (branch == "D3") {
          if (choice == 1)
            branch = "E2";
          else
            branch = "E5";
        } else if (branch == "D4") {
          if (choice == 1)
            branch = "E3";
          else
            branch = "E4";        
        } else if (branch == "E1") {
          if (choice == 1)
            branch = "F1";
          else
            branch = "C3";
        } else if (branch == "E2") {
          if (choice == 1)
            branch = "F2";
          else
            branch = "C4";
        } else if (branch == "E3") {
          if (choice == 1) {
            choice = 1000;  // END_HAPPY
            branch = "END_HAPPY";

          } else
            branch = "A";
        } else if (branch == "E4") {
          if (choice == 1)
            branch = "C1";
          else
            branch = "C2";
        } else if (branch == "E5") {
          if (choice == 1)
            branch = "B2";
          else {
            std::cout << "\nYOU DIED THE SECOND OF MANY HORRIBLE DEATHS!!!\n\n";
            lifes--;
            path += " - END2";

            if (lifes > 0) {
              std::cout << "Would you like to go back to the beginning of the journey or try again where you stand?\n";
              std::cout << "1) go back to the beginning\n";
              std::cout << "2) try again\n";

              do {
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                if (choice == 1 || choice == 2) {
                  if (choice == 1)
                    branch = "A";
                } else {
                  std::cout << "Invalid choice! Please enter a valid choice [1 - 2].\n";
                  choice = 0;
                }
              } while (choice == 0);
            } else
              choice = -1;

          }

        } else if (branch == "F1") {
          if (choice == 1)
            branch = "G1";
          else
            branch = "G2";
        } else if (branch == "F2") {
          if (choice == 1)
            branch = "G3";
          else
            branch = "D2";
        } else if (branch == "G1") {
          if (choice == 1) {
            std::cout << "\nYOU DIED THE THIRD OF MANY HORRIBLE DEATHS!!!\n\n";
            lifes--;
            path += " - END3";

            if (lifes > 0) {
              std::cout << "Would you like to go back to the beginning of the journey or try again where you stand?\n";
              std::cout << "1) go back to the beginning\n";
              std::cout << "2) try again\n";

              do {
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                if (choice == 1 || choice == 2) {
                  if (choice == 1)
                    branch = "A";
                } else {
                  std::cout << "Invalid choice! Please enter a valid choice [1 - 2].\n";
                  choice = 0;
                }
              } while (choice == 0);
            } else
              choice = -1;

          } else
            branch = "C2";
            
        } else if (branch == "G2") {
          if (choice == 1)
            branch = "C3";
          else
            branch = "C1";
        } else if (branch == "G3") {
          if (choice == 1) {
            std::cout << "\nYOU DIED THE FIFTH OF MANY HORRIBLE DEATHS!!!\n\n";
            lifes--;
            path += " - END5";

            if (lifes > 0) {
              std::cout << "Would you like to go back to the beginning of the journey or try again where you stand?\n";
              std::cout << "1) go back to the beginning\n";
              std::cout << "2) try again\n";

              do {
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                if (choice == 1 || choice == 2) {
                  if (choice == 1)
                    branch = "A";
                } else {
                  std::cout << "Invalid choice! Please enter a valid choice [1 - 2].\n";
                  choice = 0;
                }
              } while (choice == 0);
            } else
              choice = -1;
            
          } else {
            std::cout << "\nYOU DIED THE FOURTH OF MANY HORRIBLE DEATHS!!!\n\n";
            lifes--;
            path += " - END4";

            if (lifes > 0) {
              std::cout << "Would you like to go back to the beginning of the journey or try again where you stand?\n";
              std::cout << "1) go back to the beginning\n";
              std::cout << "2) try again\n";

              do {
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                if (choice == 1 || choice == 2) {
                  if (choice == 1)
                    branch = "A";
                } else {
                  std::cout << "Invalid choice! Please enter a valid choice [1 - 2].\n";
                  choice = 0;
                }
              } while (choice == 0);
            } else
              choice = -1;
            
          }
        } else {
          std::cout << "ERROR: you've entered an unexistent path!!!\n";
          return -1;
        }
      } else {
        std::cout << "Invalid choice! Please enter a valid EVENT choice [1 - 2].\n";
        choice = 0;
      }

      if (choice != 0)
        path += " - " + branch;

    } while (choice == 0);





/*

      switch (branch) {
        case 0:                          // A
        case 1:                          // B
        case 2:                          // C
        case 3:                          // D
          if (choice == 1 || choice == 2) {
            branch++;
          } else {
            std::cout << "Invalid choice! Please enter a valid EVENT choice [1 - 2].\n";
            choice = 0;
          }
          break;
        case 4:                         // 
          // if (previousChoice == 1) { // não há necessidade de tal distinção; é um avanço directo (a distinção é feita acima)
          if (choice == 1 || choice == 2) {
            branch++;
          } else {
            std::cout << "Invalid choice! Please enter a valid EVENT choice [1 - 2].\n";
            choice = 0;    
          }
          break;
        case 5:
            choice = 8;
            break;
        default:
          std::cout << "ERROR: Nothing to do!\n";
          return -1;
          break;
      }
    } while (choice == 0);

    
    switch (branch) {
      case 0:               // A
        std::cout << "[A]\n\n";

        std::cout << "1) EVENT B1\n";
        std::cout << "2) EVENT B2\n";
        break;
      case 1:               // B
        if (choice == 1) {                  // B1
        std::cout << "[A - B1]\n\n";

          std::cout << "1) EVENT C1\n";
          std::cout << "2) EVENT C2\n";
        } else if (choice == 2) {           // B2
          std::cout << "[A - B2]\n\n";

          std::cout << "1) EVENT C3\n";
          std::cout << "2) EVENT C4\n";
        } else {
          std::cout << "ERROR [B]: no such possibility!\n";
          return -1;
        }
        break;
      case 2:               // C
        if (previousChoice == 1) {
          if (choice == 1) {               // C1
            std::cout << "[A - B1 - C1]\n\n";

            std::cout << "1) EVENT D1\n";
            std::cout << "2) EVENT D3\n";
          } else if (choice == 2) {        // C2
            std::cout << "[A - B1 - C2]\n\n";

            std::cout << "1) EVENT D2\n";
            std::cout << "2) EVENT D1\n";
          } else {
            std::cout << "ERROR [Ca]: no such possibility!\n";
            return -1;
          }
        } else if (previousChoice == 2) {
          if (choice == 1) {               // C3
            std::cout << "[A - B2 - C3]\n\n";

            std::cout << "1) EVENT D1\n";
            std::cout << "2) EVENT D2\n";
          } else if (choice == 2) {        // C4
            std::cout << "[A - B2 - C4]\n\n";

            std::cout << "1) EVENT D3\n";
            std::cout << "2) EVENT B1\n";
          } else {
            std::cout << "ERROR [Cb]: no such possibility!\n";
            return -1;
          }
        } else {
          std::cout << "ERROR: this shouldn't have happened!\n";
          return -1;
          break;
        }
        break;
      case 3:             // D
        if (previousChoice == 1) {
          if (choice == 1) {

          }
        } else if (previousChoice == 2) {
          if (choice == 1) {

          }
        }
      default:
        std::cout << "ERROR: this shouldn't have happened!\n";
        return -1;
        break;
    }
    do {
      previousChoice = choice;
      
      std::cout << "Enter your EVENT of choice: ";
      std::cin >> choice;

      switch (branch) {
        case 0:                          // A
        case 1:                          // B
        case 2:                          // C
        case 3:                          // D
          if (choice == 1 || choice == 2) {
            branch++;
          } else {
            std::cout << "Invalid choice! Please enter a valid EVENT choice [1 - 2].\n";
            choice = 0;
          }
          break;
        case 4:                         // 
          // if (previousChoice == 1) { // não há necessidade de tal distinção; é um avanço directo (a distinção é feita acima)
          if (choice == 1 || choice == 2) {
            branch++;
          } else {
            std::cout << "Invalid choice! Please enter a valid EVENT choice [1 - 2].\n";
            choice = 0;    
          }
          break;
        case 5:
            choice = 8;
            break;
        default:
          std::cout << "ERROR: Nothing to do!\n";
          return -1;
          break;
      }
    } while (choice == 0);
*/

  }

  if (choice == -1) {
    std::cout << "THE END!!!\n";
    return -1;
  }

  std::cout << "\nYOU HAVE REACHED THE END ALIVE!!!\n";
  std::cout << "CONGRATULATIONS!!\n";

  return 0;
}