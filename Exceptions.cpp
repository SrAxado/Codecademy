#include "Exceptions.hpp"

const char* RobotException::what() const noexcept {
  return errorMessage.c_str();
}

BatteryLowException::BatteryLowException(const std::string& message) 
  : RobotException("Battery -- " + message) {}

MechanicalFailureException::MechanicalFailureException(const std::string& message) 
  : RobotException("Mechanical Failure -- " + message) {}

RobotControlCenterException::RobotControlCenterException(const std::string& message)
  : RobotException("Robot Control Center -- " + message) {}