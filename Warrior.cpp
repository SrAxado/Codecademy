#include "Warrior.hpp"

Warrior::Warrior(const string name, const int health, const int power)
  : Character(name, health, power) {}

// Overriding the simple attack to a brutal one
void Warrior::attack() {
  cout << "Swings a mighty sword!" << endl;
}

// Defining the special ability of the Warrior
void Warrior::specialAttack() {
  cout << getName() << " set a devastating double strike!" << endl;
}
