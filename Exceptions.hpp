#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

// Base class for robot-related issues
class RobotException : public std::exception {
  private:
    std::string errorMessage;

  public:
    RobotException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override;
};

// Base class for battery-related issues
class BatteryLowException : public RobotException {
  public:
    BatteryLowException(const std::string& message);
};

// Base class for mechanical-related issues
class MechanicalFailureException : public RobotException {
  public:
    MechanicalFailureException(const std::string& message);
};

// Base class for Robot Control Center issues
class RobotControlCenterException : public RobotException {
  public:
    RobotControlCenterException(const std::string& message);
};



#endif // EXCEPTIONS_HPP