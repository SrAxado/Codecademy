#ifndef MEXICAN_RESTAURANT_HPP
#define MEXICAN_RESTAURANT_HPP

#include "Restaurant.hpp"

class MexicanRestaurant : virtual public Restaurant {
  public:
    using Restaurant::Restaurant;
    MexicanRestaurant(string const name, string const addr, int const spceLevel);
    void describeCuisine() const;
    void removeLastMenuItem(); // not useful -- just to prove menu's protected visibility use

  private:
    int spiceLevel;
};

#endif