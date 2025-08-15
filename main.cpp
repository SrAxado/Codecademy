#include <vector>
#include "Warrior.hpp"
#include "Sorcerer.hpp"

using namespace std;

int main() {
  vector<Character*> characters;

  characters.push_back(Warrior("Iron Man", 80, 15));
  characters.push_back(Warrior("Thor", 100, 20));
  characters.push_back(Warrior("Spiderman", 95, 10));
  characters.push_back(Sorcerer("Doctor Strange", 120, 23));
  characters.push_back(Sorcerer("Loki", 90, 17));
  characters.push_back(Sorcerer("Scarlet Witch", 105, 20));
  
  for (Character* character : characters) {
    character->attack();
    character->displayInfo();
  }

  return 0;
}
