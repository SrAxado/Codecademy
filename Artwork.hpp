#pragma once

#include <string>

// Represents a piece of artwork in the digital art gallery
class Artwork {
public:
  std::string title;
  std::string artistName;
  int id;
  std::string medium;
  double price;
  bool sold;

  // // delete default constructor
  // Artwork() = delete;

  // default constructor delegating to the main, parameterized, constructor
  Artwork() : Artwork("Untitled", "Unknown", -1, "N/A", 0.0) {}

  // Parameterized constructor
  Artwork(const std::string& artTitle, const std::string& artistFullName, const int artworkId, 
    const std::string& artworkMedium, const double artworkPrice, const bool soldStatus = false);
  
  // Copy constructor
  Artwork(const Artwork& other);

  // Move constructor
  Artwork(Artwork&& other);

  void markAsSold();
};