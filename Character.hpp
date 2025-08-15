#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

using namespace std;

class Character {
  public:
    Character(const string name, const int health, const int power);
    virtual void attack();
    virtual void displayInfo();

  private:
    string name;
    int health;
    int power;
}

#endif 