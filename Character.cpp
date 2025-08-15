#include "Character.hpp"

Character::Character(const string name = "Elden King", const int health = 100, const int power = 10)
  : name(name), health(health), power(power) {}

void Character::attack() {
  cout << "Basic Low Attack" << endl;
}

void Character::displayInfo() {
  cout << "Name: " << name << ", Health: " << health << ", Power: " << power << endl;
}