#include "Restaurant.hpp"
#include "Customer.hpp"
#include "removeElement.hpp"

#include <iostream>

using namespace std;

Restaurant::Restaurant(const int numTables) {
  for (int tableNum = 1; tableNum <= numTables; tableNum++) {
    //unique_ptr<Table> table = make_unique<Table>(tableNum);
    restaurantTables.push_back(make_unique<Table>(tableNum));
  }
}

bool Restaurant::reserveTable(shared_ptr<Customer>& customer) {
  for (unique_ptr<Table>& table : restaurantTables) {
    if (table->getIsAvailable()) {
      cout << "Table #" << table->getNumber() << " is available." << endl;
      customer->setTable(table->getNumber());
      activeCustomers.push_back(customer);
      table->reserve();
      cout << "Table #" << table->getNumber() << " reserved for customer: " << customer->getName() << endl << endl;
      return true;
    }
  }
  cout << "There aren't any tables free." << endl;
  waitlist.push_back(customer);
  cout << customer->getName() << " has been added to the waitlist." << endl << endl;
  return false;
}

void Restaurant::printWaitlist() const {
  cout << "--> The following people are waiting for a table:" << endl;
  for (weak_ptr<Customer> customer : waitlist) {
    shared_ptr<Customer> customerPtr = customer.lock();
    if (customerPtr) {
      cout << customerPtr->getName() << endl;
    }
  }
  cout << endl;
}

void Restaurant::printActiveCustomersList() const{
  cout << "==> The following customers are currently seated:" << endl;
  for (shared_ptr<Customer> customer : activeCustomers) {
    cout << customer->getName() << " at Table #" << customer->getTable() << endl;
  }
  cout << endl;
}

// Releases the specified table and notifies the waitlist if needed
void Restaurant::releaseTable(int tableNumber) {
  for (unique_ptr<Table>& table : restaurantTables) {
    if (table->getNumber() == tableNumber && !table->getIsAvailable()) {
      cout << "----- Releasing Table #" << tableNumber << " -----" << endl;
      // iterates through active customers to find the current customer's table to remove it from the active customers' list
      for (auto it = activeCustomers.begin(); it != activeCustomers.end(); ++it) {
        shared_ptr<Customer> customerPtr = *it;
        cout << "---> " << customerPtr->getName() << " at Table #" << customerPtr->getTable() << endl;
        if (customerPtr && customerPtr->getTable() == tableNumber) {
          cout << "Releasing Table #" << tableNumber << " for customer: " << customerPtr->getName() << endl;
          activeCustomers.erase(it);
          // activeCostumers.erase((std::remove(activeCostumers.begin(), activeCostumers.end(), customerPtr), activeCostumers.end()));
          // customer->setTable(0); // Reset the customer's table number
          // removeElement(activeCostumers, customer); // Remove the customer from active customers
          cout << customerPtr->getName() << " has been removed from the active customers list." << endl << endl;
          // cout << "Number of active customers: " << activeCostumers.size() << endl;
          break;
        }
      }
      table->release();
      cout << "The Table #" << tableNumber << " was released." << endl << endl;
      notifyWaitlist();
      return;
    }
  }
}

// Notifies the first customer on the waitlist if a table becomes available
// and reserves a table for them, removing them from the waitlist
void Restaurant::notifyWaitlist() {
  if (waitlist.empty()) {
    return;
  } else {
    shared_ptr<Customer> customer = waitlist.front().lock();
    if (customer) {
      cout << "The first one on the waitlist: " << customer->getName() << endl << endl;
      reserveTable(customer);
      removeElement(waitlist, customer);
    }
  }
}