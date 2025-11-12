#pragma once

#include <string>

class Artwork {
public:
  std::string title;
  std::string artistName;
  int id;
  std::string medium;
  double price;
  bool sold;



  void markAsSold();
};