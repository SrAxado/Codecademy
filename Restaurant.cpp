#include "Restaurant.hpp"
#include <iostream>

Restaurant::Restaurant(string const n, string const addr) : name(n), address(addr) {}

void Restaurant::displayInfo() const {
  cout << name << endl << address << endl;
}

void Restaurant::describeCuisine() const {
  cout << "This restaurant serves various types of cuisines." << endl;
}