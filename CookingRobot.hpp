#ifndef COOKING_ROBOT_HPP
#define COOKING_ROBOT_HPP

#include "Robot.hpp"
#include "Exceptions.hpp"
#include <iostream>

// Base class for robots specialised in deliveries
class CookingRobot : public Robot {
  private:
    int batteryLevel;

  public:
    CookingRobot(const std::string& name, int initialBatteryLevel);
    // Performs the cooking task
    void performTask() override;
    // Recharges partially the robot's battery
    void repair() override;
};


#endif // COOKING_ROBOT_HPP