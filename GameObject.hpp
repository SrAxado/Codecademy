#pragma once
#include <string>
#include "ScriptEngine.hpp"
#include "Position.hpp"
using namespace std;

class GameObject{
private:

public:
  friend ostream& operator<<(ostream& out, const GameObject& obj);
};