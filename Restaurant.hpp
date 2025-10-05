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
  vector<shared_ptr<Customer>> activeCostumer;
  vector<unique_ptr<Customer>> waitlist;

  int initialTableCount;

public:
  Restaurant(const int numTables);
  bool reserveTable(shared_ptr<Customer>& customer);
};

#endif
