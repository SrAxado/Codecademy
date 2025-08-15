#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const string name, const int health, const int power)
  : Character(name, health, power) {}

void Sorcerer::attack() {
  cout << name << " casts a spell!" << endl;
}