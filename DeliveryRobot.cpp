#include "DeliveryRobot.hpp"


DeliveryRobot::DeliveryRobot(const std::string& name, int initialBatteryLevel) 
  : Robot(name), batteryLevel(initialBatteryLevel) {}

// Performs the delivery task
void DeliveryRobot::performTask() {
  std::cout << " -- " << getName() << " -- " << std::endl;
  if (batteryLevel < 20) {
    throw BatteryLowException("Battery too low to perform the delivery task.");
  } else {
    std::cout << "DeliveryRobot is delivering" << std::endl;
    batteryLevel -= 10;  // Simulate battery usage
    std::cout << "Delivery done" << std::endl;
    taskSuccessful(); // Logging successful task
  }
}

// Recharges partially the robot's battery
void DeliveryRobot::repair() {
  std::cout << "DeliveryRobot is being recharged" << std::endl;
  if (batteryLevel <= 70) {
    batteryLevel += 30;  // Simulate recharging
    std::cout << "DeliveryRobot recharged: " << batteryLevel << "%" << std::endl;
  } else {
    std::cout << "Battery is fully charged" << std::endl;
    batteryLevel = 100; // Cap battery level at 100%
  }
}