#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

// Defining the Warrior and its special abilities
class Warrior: public Character {
  public:
    Warrior(const string name, const int health, const int power);
    void attack() override;
    void specialAttack();
};

#endif 