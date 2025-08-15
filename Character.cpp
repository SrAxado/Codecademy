#include "Character.hpp"

Character::Character(const string name, const int health, const int power)
  : name(name), health(health), power(power) {}

void Character::attack() {
  cout << "Basic Low Attack" << endl;
}

void Character::displayInfo() {
  cout << "Name: " << name << ", Health: " << health << ", Power: " << power << endl;
}