#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Character.hpp"

// Define the Sorcerer
class Sorcerer: public Character {
  public:
    Sorcerer(const string name, const int health, const int power);
    void attack() override;
};

#endif 
