#include "GameObject.hpp"
#include <iostream>
using namespace std;

void GameObject::move(float dx, float dy) {
  x += dx;
  y += dy;
}

void GameObject::takeDamage(int amount) {
  health -= amount;
}

bool operator==(const GameObject& a, const GameObject& b) {
  return ((a.x == b.x) && (a.y == b.y));
}

bool operator==(const Position& pos, const GameObject& obj) {
  return ((pos.x == obj.x) && (pos.y == obj.y));
}

ostream& operator<<(ostream& out, const GameObject& obj) {
  out << "GameObject[name=" << obj.name
      << ", health=" << obj.health
      << ", pos=(" << obj.x << "," << obj.y << ")"
      << ", animationFrame=" << obj.animationFrame << "]";
  return out;
}