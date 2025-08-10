#include "JapaneseRestaurant.hpp"
#include <iostream>

JapaneseRestaurant::JapaneseRestaurant(string const name, string const addr, bool const tatamiAvailable) 
  : Restaurant(name, addr), hasTatami(tatamiAvailable) {}

void JapaneseRestaurant::describeCuisine() const {
  if (hasTatami) {
    cout << "Traditional Japanese cuisine with tatami seating available." << endl;
  } else {
    cout << "Traditional Japanese cuisine" << endl;
  }
}