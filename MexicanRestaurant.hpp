#ifndef MEXICAN_RESTAURANT_HPP
#define MEXICAN_RESTAURANT_HPP

#include "MainRestaurant.hpp"

// represents a specific kind of restaurant, Mexican; 
// inheriting Restaurant virtually to avoid the diamond problem with later inheritances
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