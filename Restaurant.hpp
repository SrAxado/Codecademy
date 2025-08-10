#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
using namespace std;

class Restaurant {
  public:
    Restaurant(string const n, string const addr);
    void displayInfo() const;
    void describeCuisine() const;

private:
    string name;
    string address;
};

#endif
