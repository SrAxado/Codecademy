#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

class Warrior: public Character {
  public:
    Warrior(const string name, const int health, const int power);
    void attack() override;
    void specialAttack();

  private:

}

#endif 