#include "Warrior.hpp"

Warrior::Warrior(const string name, const int health, const int power)
  : Character(name, health, power) {}

void Warrior::attack() {
  cout << "Swings a mighty sword!" << endl;
}

void Warrior::specialAttack() {
  cout << name << " a devastating double strike!" << endl;
}
