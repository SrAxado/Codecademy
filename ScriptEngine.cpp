#include "ScriptEngine.hpp"
#include <iostream>
using namespace std;

// Teleports the obj to a (newX, newY) position and prints the action
void ScriptEngine::teleport(GameObject& obj, float newX, float newY) {
  obj.x = newX;
  obj.y = newY;
  obj.move(newX, newY); // The move method in GameObject is private and only adds deltas
  std::cout << "[ScriptEngine] Teleported " << obj.name << " to (" << newX << ", " << newY << ") " << std::endl;
}

// Heals the object by increasing its health
void ScriptEngine::heal(GameObject& obj, int amount) {
  obj.health += amount;
  std::cout << "[ScriptEngine] Healed by " << amount << ". Health now: " << obj.health << " " << std::endl;
}

// Increases the animation frame of the game object by 1, simulating a new animation frame
void ScriptEngine::advanceAnimation(GameObject& obj) {
  ++obj.animationFrame;
  std::cout << "[ScriptEngine] Animation frame advanced to: " << obj.animationFrame << " " << std::endl;
}

// Handles the attack of the attacker to the object
void ScriptEngine::performAttack(Enemy& attacker, GameObject& obj) {
  std::cout << "[ScriptEngine] ===> " << attacker.name << " attacks with all its might " << obj.name << std::endl;
  if (checkAttackReach(attacker, obj)) {
    std::cout << obj.name << " is within " << attacker.name << "'s reach!" << std::endl;
    obj.takeDamage(attacker.attackPower);
    std::cout << "[ScriptEngine] " << obj.name << " took " << attacker.attackPower << " damage. Health now: " << obj.health << std::endl;
    advanceAnimation(obj);

  } else {
    std::cout << "Ffffeewwwww! That was close!!" << std::endl;
  }
}

// Helper function to determine if the object if within reach of the attacker range
bool ScriptEngine::checkAttackReach(const Enemy& attacker, const GameObject& obj) {
  // checks if obj is within range of the attacker, considering their position and radius of attack of the attacker
  return (obj.x - attacker.x)*(obj.x - attacker.x) + (obj.y - attacker.y)*(obj.y - attacker.y) <= attacker.aggroRadius * attacker.aggroRadius;
}