#include "MaintenanceRobot.hpp"


MaintenanceRobot::MaintenanceRobot(const std::string& name, int initialIntegrity)
  : Robot(name), mechanicalIntegrity(initialIntegrity) {}

// Performs the maintenance task
void MaintenanceRobot::performTask() {
  std::cout << " -- " << getName() << " -- " << std::endl;
  if (mechanicalIntegrity < 30) {
    throw MechanicalFailureException("Mechanical integrity too low to perform the maintenance task.");
  } else {
    std::cout << "MaintenanceRobot is performing maintenance" << std::endl;
    mechanicalIntegrity -= 15;  // Simulate wear and tear
    std::cout << "Maintenance done" << std::endl;
    taskSuccessful(); // Logging successful task
  }
}

// Repairs partially the robot's mechanical integrity
void MaintenanceRobot::repair() {
  std::cout << "MaintenanceRobot is being repaired" << std::endl;
  if (mechanicalIntegrity <= 70) {
    mechanicalIntegrity += 10;  // Simulate repairing
    std::cout << "MaintenanceRobot repaired: " << mechanicalIntegrity << "%" << std::endl;
  } else {
    std::cout << "MaintenanceRobot is fully repaired" << std::endl;
    mechanicalIntegrity = 100;  // Cap mechanical integrity at 100%
  }
}