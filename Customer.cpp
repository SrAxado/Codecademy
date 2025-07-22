#include "Customer.hpp"

// using namespace std;

Customer::Customer(const std::string& n, const int table) : name_(n), tableNum_(table) {}

std::string Customer::getName() const { return name_; }

int Customer::getTable() const { return tableNum_; }

void Customer::setTable(const int num) { tableNum_ = num; }
