#pragma once
#include "GameObject.hpp"

class ScriptEngine {
public:
  static void teleport(GameObject& obj, float newX, float newY);
  static void heal(GameObject& obj, int amount);
  static void advanceAnimation(GameObject& obj);
};
