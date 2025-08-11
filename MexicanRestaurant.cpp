#include "MexicanRestaurant.hpp"
#include <iostream>

// MexicanRestaurant::MexicanRestaurant(string const name, string const addr, int const spceLevel) : Restaurant(name, addr), spiceLevel(spceLevel) {}

// initiates MexicanRestaurant object while controlling the levels of spice in a 1 - 5 range
MexicanRestaurant::MexicanRestaurant(string const name, string const addr, int const spceLevel) : Restaurant(name, addr) {
  if (spceLevel < 1) {
    spiceLevel = 1;
  } else if (spceLevel > 5) {
    spiceLevel = 5;
  } else {
    spiceLevel = spceLevel;
  }
}

// overrides inherited desbribeCuisine() to Mexican food
void MexicanRestaurant::describeCuisine() const {
  cout << "Authentic Mexican cuisine with spice level " << spiceLevel << " out of 5." << endl;
}

// not useful -- just to prove menu's protected visibility use
void MexicanRestaurant::removeLastMenuItem() {
  if (!menu.empty()) {
    cout << "Removing ";
    menu.back().display();
    menu.pop_back();
  }
}