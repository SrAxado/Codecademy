#include "MexicanJapaneseFusion.hpp"
#include <iostream>

// being MexicanRestaurant and JapaneseRestaurant virtual inheritances, one has to use the base class construtor (Restaurant())
MexicanJapaneseFusion::MexicanJapaneseFusion(string const name, string const addr, int const spcLevel, bool const tatamiAvailable) 
  : MexicanRestaurant(name, addr, spcLevel), JapaneseRestaurant(name, addr, tatamiAvailable), Restaurant(name, addr) {}

// overrides inherited desbribeCuisine() to Mexican Japanese fusion
  void MexicanJapaneseFusion::describeCuisine() const {
  cout << "A unique fusion of Mexican and Japanese cuisines." << endl;
}

void MexicanJapaneseFusion::displaySpecialty() const {
  cout << "Our specialties combine both cuisines - try our Sushi Tacos and Wasabi Guacamole!" << endl;
}

// not useful -- just to prove menu's protected visibility use
void MexicanJapaneseFusion::removeLastMenuItem() {
  if (!menu.empty()) {
    cout << "Removing item two layers below: ";
    menu.back().display();
    menu.pop_back();
  }
}