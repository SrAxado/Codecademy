#include <iostream>
#include <sstream>
#include "GameObject.hpp"
#include "ScriptEngine.hpp"
#include "Position.hpp"
using namespace std;

int main() {
  GameObject player1("Hero", 100, 0.0f, 0.0f, 1);
  GameObject player2("Hero", 100, 0.0f, 0.0f, 1);
  Position posCheck(0.0f, 0.0f);

  return 0;
}
