#ifndef MAINRESTAURANT_HPP
#define MAINRESTAURANT_HPP

#include "MenuItem.hpp"
#include <string>
#include <vector>
using namespace std;

class Restaurant {
  public:
    Restaurant(string const n, string const addr);
    void displayInfo() const;
    void describeCuisine() const;
    void addMenuItem(MenuItem item);
    void displayMenu() const;
    void removeLastMenuItem();
  
  protected:
    vector<MenuItem> menu;

  private:
    // vector<MenuItem> menu; // if changed the visibility to private, derived classes won't be able to access it
    string name;
    string address;
};

#endif
