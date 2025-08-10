#include "MexicanJapaneseFusion.hpp"
#include <iostream>

MexicanJapaneseFusion::MexicanJapaneseFusion(string const name, string const addr, int const spcLevel, bool const tatamiAvailable) 
  : MexicanRestaurant(name, addr, spcLevel), JapaneseRestaurant(name, addr, tatamiAvailable) {}

void MexicanJapaneseFusion::describeCuisine() const {
  cout << "A unique fusion of Mexican and Japanese cuisines" << endl;
}

void MexicanJapaneseFusion::displaySpecialty() const {
  cout << "Our specialties combine both cuisines - try our Sushi Tacos and Wasabi Guacamole!" << endl;
}