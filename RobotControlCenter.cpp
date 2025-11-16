#include "RobotControlCenter.hpp"


// Robot Control Center constructor
RobotControlCenter::RobotControlCenter(int centerCapacity) {
  if (capacity < 0) {
    throw RobotException("The capacity of the center cannot be negative.");
  } else {
    capacity = centerCapacity;
    std::cout << "The Robot Control Center was created" << std::endl;
  }
}

RobotControlCenter::~RobotControlCenter() {
  for (Robot* robot : robotCollection) {
    delete robot; // Delete robot to free memory
  }
}

void RobotControlCenter::logError(const std::string& errorMessage) noexcept {
  std::cerr << "Robot Control Center Error: " << errorMessage << std::endl;
}

// Adds a robot to the Robot Control Center
void RobotControlCenter::addRobot(Robot* robot) {
  if (int(robotCollection.size()) >= capacity) {
    throw RobotControlCenterException("Capacity exceeded. Cannot add more robots.");
  } else {
    std::cout << "Adding robot to the center" << std::endl;
    robotCollection.push_back(robot);
    std::cout << "[" << robotCollection.size() << " / " << capacity << "] Robot added sucessfully" << std::endl;
  }
}

// Executes tasks for all robots in the Robot Control Center
void RobotControlCenter::executeAllRobotTasks() {
  for (Robot* robot : robotCollection) {
    try {
      robot->performTask();
    }
    catch (const MechanicalFailureException& e) {
      logError(e.what());
      robot->repair();  // Attempt to repair the robot
      // throw;  // Rethrow to indicate failure
    }
    catch (const RobotException& e) {
      logError(e.what());
      robot->repair();  // Attempt to repair the robot
      // throw;  // Rethrow to indicate failure
    }
    catch (...) {
      logError("Unknown robot error");
      throw;  // Rethrow to indicate failure
    }
  }
}

// Logs all robots' completed tasks
void RobotControlCenter::logCompleteTasks() noexcept {
    // Logs all robots' completed tasks
  std::cout << "---- Robot Task Completion ----" << std::endl;
  for (Robot* robot : robotCollection) {
    std::cout << robot->getName() << " completed " << robot->getCompletedTasks() << " tasks." << std::endl;
  }
}