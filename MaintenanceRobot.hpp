#ifndef MAINTENANCE_ROBOT_HPP
#define MAINTENANCE_ROBOT_HPP

#include "Robot.hpp"
#include "Exceptions.hpp"
#include <iostream>

// Base class for robots specialised in maintenance
class MaintenanceRobot : public Robot {
  private:
    int mechanicalIntegrity;

  public:
    MaintenanceRobot(const std::string& name, int initialIntegrity);
    // Performs the maintenance task
    void performTask() override;
    // Repairs partially the robot's mechanical integrity
    void repair() override;
};


#endif // MAINTENANCE_ROBOT_HPP
