#include "CookingRobot.hpp"

CookingRobot::CookingRobot(const std::string& name, int initialBatteryLevel)
  : Robot(name), batteryLevel(initialBatteryLevel) {}

// Performs the cooking task
void CookingRobot::performTask() {
  std::cout << " -- " << getName() << " -- " << std::endl;
  if (batteryLevel < 15) {
    throw BatteryLowException("Battery too low to perform the cooking task.");
  } else {
    std::cout << "CookingRobot is cooking" << std::endl;
    batteryLevel -= 10;  // Simulate battery usage
    std::cout << "Cooking done" << std::endl;
    taskSuccessful(); // Logging in successful task
  }
}

// Recharges partially the robot's battery
void CookingRobot::repair() {
  std::cout << "CookingRobot is being recharged" << std::endl;
  if (batteryLevel <= 70) {
    batteryLevel += 20;  // Simulate recharging
    std::cout << "CookingRobot recharged: " << batteryLevel << "%" << std::endl;
  } else {
    std::cout << "Battery is fully charged" << std::endl;
    batteryLevel = 100; // Cap battery level at 100%
  }
}