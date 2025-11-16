#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

// Exception for robot-related issues
class RobotException : public std::exception {
  private:
    std::string errorMessage;

  public:
    RobotException(const std::string& message) : errorMessage(message) {}

    const char* what() const noexcept override;
};

// Exception for battery-related issues
class BatteryLowException : public RobotException {
  public:
    BatteryLowException(const std::string& message);
};

// Exception for mechanical-related issues
class MechanicalFailureException : public RobotException {
  public:
    MechanicalFailureException(const std::string& message);
};

// Exception for Robot Control Center issues
class RobotControlCenterException : public RobotException {
  public:
    RobotControlCenterException(const std::string& message);
};



#endif // EXCEPTIONS_HPP