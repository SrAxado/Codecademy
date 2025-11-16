#include "RobotControlCenter.hpp"
#include "DeliveryRobot.hpp"
#include "MaintenanceRobot.hpp"
#include "CookingRobot.hpp"

int main() {
  try {
    RobotControlCenter controlCenter(5);
    controlCenter.addRobot(new DeliveryRobot("DeliveryBot 1", 50));
    controlCenter.addRobot(new DeliveryRobot("DeliveryBot 2", 10)); // This should trigger BatteryLowException
    controlCenter.addRobot(new MaintenanceRobot("MaintenanceBot 1", 80));
    controlCenter.addRobot(new MaintenanceRobot("MaintenanceBot 2", 20)); // This should trigger MechanicalFailureException
    controlCenter.addRobot(new CookingRobot("CookingBot 1", 70));
    // controlCenter.addRobot(new CookingRobot("CookingBot 2", 5)); // This should trigger Robot Control Center capacity exception

    std::cout << "Putting the factory to work!" << std::endl;

    try {
      std::cout << "----- First Round of Tasks -----" << std::endl;
      controlCenter.executeAllRobotTasks(); // First round of tasks

      std::cout << "----- Second Round of Tasks -----" << std::endl;
      controlCenter.executeAllRobotTasks(); // Second round of tasks

      std::cout << "----- Third Round of Tasks -----" << std::endl;
      controlCenter.executeAllRobotTasks(); // Third round of tasks

      controlCenter.logCompleteTasks();
    }
    catch(...) {
      std::cerr << "Unexpected error: shutting down factory" << std::endl;
      std::cout << "Program finished" << std::endl;
      return 0; // exiting cleanly
    }
  }
  catch (const RobotException& e) {
    std::cerr << "Robot Control Center Initialization Error: " << e.what() << std::endl;
    return -1;  // exiting with error code
  }

  std::cout << "Shutting down the factory for the day" << std::endl;

  return 0;
}


/*
  OUTPUT:

    The Robot Control Center was created
    Adding robot to the center
    [1 / 5] Robot added sucessfully
    Adding robot to the center
    [2 / 5] Robot added sucessfully
    Adding robot to the center
    [3 / 5] Robot added sucessfully
    Adding robot to the center
    [4 / 5] Robot added sucessfully
    Adding robot to the center
    [5 / 5] Robot added sucessfully
    Putting the factory to work!
    ----- First Round of Tasks -----
    -- DeliveryBot 1 --
    DeliveryRobot is delivering
    Delivery done
    -- DeliveryBot 2 --
    Robot Control Center Error: Battery -- Battery too low to perform the delivery task.
    DeliveryRobot is being recharged
    DeliveryRobot recharged: 40%
    -- MaintenanceBot 1 --
    MaintenanceRobot is performing maintenance
    Maintenance done
    -- MaintenanceBot 2 --
    Robot Control Center Error: Mechanical Failure -- Mechanical integrity too low to perform the maintenance task.
    MaintenanceRobot is being repaired
    MaintenanceRobot repaired: 30%
    -- CookingBot 1 --
    CookingRobot is cooking
    Cooking done
    ----- Second Round of Tasks -----
    -- DeliveryBot 1 --
    DeliveryRobot is delivering
    Delivery done
    -- DeliveryBot 2 --
    DeliveryRobot is delivering
    Delivery done
    -- MaintenanceBot 1 --
    MaintenanceRobot is performing maintenance
    Maintenance done
    -- MaintenanceBot 2 --
    MaintenanceRobot is performing maintenance
    Maintenance done
    -- CookingBot 1 --
    CookingRobot is cooking
    Cooking done
    ----- Third Round of Tasks -----
    -- DeliveryBot 1 --
    DeliveryRobot is delivering
    Delivery done
    -- DeliveryBot 2 --
    DeliveryRobot is delivering
    Delivery done
    -- MaintenanceBot 1 --
    MaintenanceRobot is performing maintenance
    Maintenance done
    -- MaintenanceBot 2 --
    Robot Control Center Error: Mechanical Failure -- Mechanical integrity too low to perform the maintenance task.
    MaintenanceRobot is being repaired
    MaintenanceRobot repaired: 25%
    -- CookingBot 1 --
    CookingRobot is cooking
    Cooking done
    ---- Robot Task Completion ----
    DeliveryBot 1 completed 3 tasks.
    DeliveryBot 2 completed 2 tasks.
    MaintenanceBot 1 completed 3 tasks.
    MaintenanceBot 2 completed 1 tasks.
    CookingBot 1 completed 3 tasks.
    Shutting down the factory for the day

*/