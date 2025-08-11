#ifndef JAPANESE_RESTAURANT_HPP
#define JAPANESE_RESTAURANT_HPP

#include "Restaurant.hpp"

class JapaneseRestaurant : virtual public Restaurant {
  public:
    using Restaurant::Restaurant;
    JapaneseRestaurant(string const name, string const addr, bool const tatamiAvailable);
    void describeCuisine() const;

  private:
    bool hasTatami;
};

#endif