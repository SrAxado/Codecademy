#pragma once

#include "GameObject.hpp"

class Enemy : public GameObject {
private:
  int attackPower;
  int aggroRadius;
  
public:
  Enemy(const std::string& nme, const int hlth, int attckPwr, int aggRad)
    : GameObject(nme, hlth, 0, 0, 0), attackPower(attckPwr), aggroRadius(aggRad) {}

  // void attack(GameObject& obj);

  friend class ScriptEngine;
};
