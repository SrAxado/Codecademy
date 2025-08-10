#ifndef MEXICAN_JAPANESE_FUSION_HPP
#define MEXICAN_JAPANESE_FUSION_HPP

#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "Restaurant.hpp"

class MexicanJapaneseFusion : virtual public MexicanRestaurant, virtual public JapaneseRestaurant {
  public:
    MexicanJapaneseFusion(string const name, string const addr, int const spcLevel, bool const tatamiAvailable);
    void describeCuisine() const;
    void displaySpecialty() const;
};

#endif