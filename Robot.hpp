#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>

class Robot {
private:
  int completedTasks = 0; // Number of sucessfully completed tasks

protected:
  std::string name;

  void taskSuccessful() { ++completedTasks; }

public:
  explicit Robot(const std::string &robotName) : name(robotName) {}
  virtual ~Robot() = default;

  virtual void performTask() = 0;  // Pure virtual task interface

  virtual void repair() = 0; // Pure virtual repair interface

  std::string getName() const { return name; }
  int getCompletedTasks() const { return completedTasks; }
};

#endif // ROBOT_HPP
