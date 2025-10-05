#include "MainRestaurant.hpp"
#include <iostream>

Restaurant::Restaurant(string const n, string const addr) : name(n), address(addr) {}

void Restaurant::displayInfo() const {
  cout << " == " << name << " ==" << endl << address << endl;
}

void Restaurant::describeCuisine() const {
  cout << "This restaurant serves various types of cuisines." << endl;
}

void Restaurant::addMenuItem(MenuItem item) {
  menu.emplace_back(item);
}

void Restaurant::displayMenu() const {
  cout << "  --- " << name << "'s Menu ---" << endl;
  for (const MenuItem& item : menu) {  // to avoid unnecessary copying of the MenuItem object
    cout << "    ";
    item.display();
  }
  cout << endl;
}

// not useful -- just to prove menu's protected visibility use
void Restaurant::removeLastMenuItem() {
  if (!menu.empty()) {
    cout << "Easily removing ";
    menu.back().display();
    menu.pop_back();
  }
}