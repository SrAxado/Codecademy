#include <vector>
#include "Warrior.hpp"
#include "Sorcerer.hpp"

using namespace std;

int main() {
  vector<Character*> characters;

  // Creating the Warriors and Sorcerers
  characters.push_back(new Warrior("Iron Man", 80, 15));
  characters.push_back(new Warrior("Thor", 100, 20));
  characters.push_back(new Warrior("Spiderman", 95, 10));
  characters.push_back(new Sorcerer("Doctor Strange", 120, 23));
  characters.push_back(new Sorcerer("Loki", 90, 17));
  characters.push_back(new Sorcerer("Scarlet Witch", 105, 20));
  
  // Display the character abilities and information
  for (Character* character : characters) {
    character->attack();
    character->displayInfo();
  }

  // Create a Warrior and use dynamic_cast to access specialAttack()
  Character* characterPtr = new Warrior("Captain America", 110, 19);
  Warrior* warriorPtr = dynamic_cast<Warrior*>(characterPtr);
  if (warriorPtr != nullptr) {
    warriorPtr->specialAttack();
  } else {
    cout << "The character is not a Warrior!" << endl;
  }

  // Verify if a character from the character's vector is a Warrior or not
  Warrior* fighter = dynamic_cast<Warrior*>(characters[4]);
  if (fighter != nullptr) {
    fighter->specialAttack();
  } else {
    cout << "The fighter is not a Warrior!" << endl;
  }

  // Cleaning up all the allocated memory and all the dynamically allocated characters
  delete characterPtr;
  for (Character* character : characters) {
    delete character;
  }
  // Suggestion: Do not delete pointers that were not allocated with new 
  //(e.g., 'warriorPtr' and 'fighter' in main.cpp). 
  // Only delete what you explicitly new'd.
  
  // No need to delete warriorPtr or fighter, as they are not separately allocated.
  
  return 0;
}
