#ifndef JAPANESE_RESTAURANT_HPP
#define JAPANESE_RESTAURANT_HPP

#include "MainRestaurant.hpp"

// represents a specific kind of restaurant, Japanese; 
// inheriting Restaurant virtually to avoid the diamond problem with later inheritances
class JapaneseRestaurant : virtual public Restaurant {
  public:
    using Restaurant::Restaurant;
    JapaneseRestaurant(string const name, string const addr, bool const tatamiAvailable);
    void describeCuisine() const;

  private:
    bool hasTatami;
};

#endif