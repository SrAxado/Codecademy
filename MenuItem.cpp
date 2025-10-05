#include "MenuItem.hpp"
#include <iostream>

MenuItem::MenuItem(string const itemName, double const itemPrice) : name(itemName), price(itemPrice) {}

void MenuItem::display() const {
  cout << name << " - $" << price << endl;
}