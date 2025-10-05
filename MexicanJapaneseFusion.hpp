#ifndef MEXICAN_JAPANESE_FUSION_HPP
#define MEXICAN_JAPANESE_FUSION_HPP

#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "MainRestaurant.hpp"

// represents a mixed fusion of restaurant several specific restaurants;
// by having made the "fusioned" restaurant types virtually inherited the base Restaurant one can access all of the inherited methods unambiguously
class MexicanJapaneseFusion : public MexicanRestaurant, public JapaneseRestaurant {
  public:
    using MexicanRestaurant::MexicanRestaurant, JapaneseRestaurant::JapaneseRestaurant;
    MexicanJapaneseFusion(string const name, string const addr, int const spcLevel, bool const tatamiAvailable);
    void describeCuisine() const;
    void displaySpecialty() const;
    void removeLastMenuItem();  // not useful -- just to prove menu's protected visibility use
};

#endif