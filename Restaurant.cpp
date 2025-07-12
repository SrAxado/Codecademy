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
      cout << "Table " << table->getNumber() << " is available." << endl;
      return true;
    }
  }
  return false;
}