#ifndef ROBOT_CONTROL_CENTER_HPP
#define ROBOT_CONTROL_CENTER_HPP

#include <vector>
#include <iostream>
#include "Robot.hpp"
#include "Exceptions.hpp"

// Robot Control Center to manage all robots
class RobotControlCenter {
  private:
    std::vector<Robot*> robotCollection;
    int capacity; // Maximum number of robots the Robot Control Center can hold

    void logError(const std::string& errorMessage) noexcept;

  public:
    RobotControlCenter(int capacity);

    ~RobotControlCenter();
    // Adds a robot to the Robot Control Center
    void addRobot(Robot* robot);
    // Executes tasks for all robots in the Robot Control Center
    void executeAllRobotTasks();
    // Logs all robots' completed tasks
    void logCompleteTasks() noexcept;

};


#endif // ROBOT_CONTROL_CENTER_HPP
