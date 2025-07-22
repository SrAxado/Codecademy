#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <memory>
#include "Table.hpp"
#include "Customer.hpp"

using namespace std;

class Restaurant {
private:
  vector<unique_ptr<Table>> restaurantTables;
  vector<shared_ptr<Customer>> activeCostumers;
  vector<weak_ptr<Customer>> waitlist;

  int initialTableCount;

public:
  Restaurant(const int numTables);
  bool reserveTable(shared_ptr<Customer>& customer);
  void printWaitlist() const;
  void printActiveCustomersList() const;
  void releaseTable(int tableNumber);
  void notifyWaitlist();
};

#endif
