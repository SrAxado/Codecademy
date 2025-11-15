#include "Artwork.hpp"
#include <iostream>

// Parameterized constructor
Artwork::Artwork(const std::string& artTitle, const std::string& artistFullName, const int artworkId, 
    const std::string& artworkMedium, const double artworkPrice, const bool soldStatus) :
      title(artTitle), artistName(artistFullName), id(artworkId), medium(artworkMedium), price(artworkPrice), sold(soldStatus) {}

// Copy constructor
Artwork::Artwork(const Artwork& other) :
  title(other.title), artistName(other.artistName), id(other.id), medium(other.medium), price(other.price), sold(other.sold) {}

// Move constructor
Artwork::Artwork(Artwork&& other) :
  title(std::move(other.title)), artistName(std::move(other.artistName)), medium(std::move(other.medium)),
  id(other.id), price(other.price), sold(other.sold) {}


void Artwork::markAsSold() {
  sold = true;
}

