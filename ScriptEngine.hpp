#pragma once
#include "GameObject.hpp"
#include "Enemy.hpp"

class ScriptEngine {
public:
  static void teleport(GameObject& obj, float newX, float newY);
  static void heal(GameObject& obj, int amount);
  static void advanceAnimation(GameObject& obj);
  static void performAttack(Enemy& attacker, GameObject& obj);

private:
  static bool checkAttackReach(const Enemy& attacker, const GameObject& obj);
};
