#include "MexicanRestaurant.hpp"
#include <iostream>

MexicanRestaurant::MexicanRestaurant(string const nme, string const addr, int const spceLevel) : Restaurant(nme, addr), spiceLevel(spceLevel) {
// MexicanRestaurant::MexicanRestaurant(string const nme, string const addr, int const spceLevel) : spiceLevel(spceLevel) {
//   Restaurant(nme, addr);
}

void MexicanRestaurant::describeCuisine() const {
  cout << "Authentic Mexican cuisine with spice level " << spiceLevel << " out of 5" << endl;
}

