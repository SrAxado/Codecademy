#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>

class Robot {
protected:
  std::string name;
public:
  explicit Robot(const std::string &robotName) : name(robotName) {}
  virtual ~Robot() = default;

  virtual void performTask() = 0;  // Pure virtual task interface
};

#endif // ROBOT_HPP
