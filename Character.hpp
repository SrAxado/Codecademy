#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

using namespace std;

class Character {
  public:
    Character(const string name = "Elder King", const int health = 100, const int power = 50);
    string getName() const;
    int getHealth() const;
    int getPower() const;
    virtual void attack();
    virtual void displayInfo();

  private:
    string name;
    int health;
    int power;
};

#endif 