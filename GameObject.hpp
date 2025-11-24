#pragma once
#include <string>
//#include "ScriptEngine.hpp" // Was causing circular 'GameObject' not declared errors in both GameObject and ScriptEngine
#include "Position.hpp"
using namespace std;

class GameObject{
private:
  std::string name; // name or identity of the game object
  int health; // health or hit points
  float x;  // game object's horizontal position in the game world
  float y;  // game object's verical position in the game world
  int animationFrame; // current animation frame for the object


  void move(float dx, float dy);

  void takeDamage(int amount);


public:
  GameObject(const std::string& nme, const int hlth, const float xpos, const float ypos, const int frame)
    : name(nme), health(hlth), x(xpos), y(ypos), animationFrame(frame) {}

  friend ostream& operator<<(ostream& out, const GameObject& obj);
  friend bool operator==(const GameObject& a, const GameObject& b);
  friend bool operator==(const Position& pos, const GameObject& obj);

  // ScriptEngine will control the private state of a game to simulate actions like teleporting, healing, or advancing animations
  friend class ScriptEngine;

  // save or send a game object's state as text
  friend std::string stringify(const GameObject& obj);
};