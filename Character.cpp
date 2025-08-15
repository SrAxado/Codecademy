#include "Character.hpp"

Character::Character(const string name, const int health, const int power)
  : name(name), health(health), power(power) {}

string Character::getName() const { return name;  }

int Character::getHealth() const { return health; }

int Character::getPower() const { return power; }

// Define the default attack
void Character::attack() {
  cout << "Basic Low Attack" << endl;
}

// Display the character's information
void Character::displayInfo() {
  cout << "Name: " << name << ", Health: " << health << ", Power: " << power << endl;
}