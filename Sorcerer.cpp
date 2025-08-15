#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const string name, const int health, const int power)
  : Character(name, health, power) {}

// Overriding the simple attack to a magical spell
void Sorcerer::attack() {
  cout << "Casts a wondrous spell!" << endl;
}