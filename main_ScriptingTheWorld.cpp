#include <iostream>
#include <sstream>
#include "GameObject.hpp"
#include "ScriptEngine.hpp"
#include "Position.hpp"
using namespace std;

std::string stringify(const GameObject& obj) {
  return obj.name + "#" + to_string(obj.health) + "#" + to_string(int(obj.x)) + "#" + to_string(int(obj.y)) + "#" + to_string(obj.animationFrame);
}

int main() {
  GameObject player1("Hero", 100, 0.0f, 0.0f, 1);
  GameObject player2("Hero", 100, 0.0f, 0.0f, 1);
  Position posCheck(0.0f, 0.0f);

  if (posCheck == player1) {
    std::cout << "Position matches player1's position." << std::endl;
  } else {
    std::cout << "Position does NOT match player1's position." << std::endl;
  }

  ScriptEngine::teleport(player2, 5, 7.5);
  ScriptEngine::heal(player2, 20);
  ScriptEngine::advanceAnimation(player1);

  std::cout << "Stringified player1: " << stringify(player1) << std::endl;
  std::cout << player1 << std::endl;

  Enemy playerA("Enemy", 88, 14, 7);

  ScriptEngine::performAttack(playerA, player1);

  return 0;
}
