#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include <string>
using namespace std;

class MenuItem {
  public:
    MenuItem(string const itemName, double const itemPrice);
    void display() const;

  private:
    string name;
    double price;
};

#endif