#ifndef MEXICAN_RESTAURANT_HPP
#define MEXICAN_RESTAURANT_HPP

#include "Restaurant.hpp"

class MexicanRestaurant : public Restaurant {
  public:
    using Restaurant::Restaurant;
    MexicanRestaurant(string const nme, string const addr, int const spceLevel);
    void describeCuisine() const;

  private:
    int spiceLevel;
};

#endif