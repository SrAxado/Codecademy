#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Table.hpp"

class Customer {
private:
  std::string name_;
  int tableNum_;

public:
  Customer(const std::string& n = "", const int table = 0);
  std::string getName() const;
  int getTable() const;
  void setTable(const int num);
};

#endif
