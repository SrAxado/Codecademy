#include "Exceptions.hpp"

const char* RobotException::what() const noexcept {
  return errorMessage.c_str();
}

BatteryLowException::BatteryLowException(const std::string& message) 
  : RobotException(message) {}

MechanicalFailureException::MechanicalFailureException(const std::string& message) 
  : RobotException(message) {}

RobotControlCenterException::RobotControlCenterException(const std::string& message)
  : RobotException(message) {}