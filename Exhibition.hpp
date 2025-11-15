#pragma once

#include "Artwork.hpp"
#include <vector>
#include <string>

class Exhibition {
public:
  std::string name;
  std::vector<Artwork*> featuredArtworks;

  // Exhibition() = default;

  // since exhibitions must have a name or featured artworks, let's require initialization with data
  Exhibition() = delete;

  // parameterized constructor
  Exhibition(const std::string& exhibitionName, Artwork* art);

  // exhibition name delegating constructor
  Exhibition(const std::string& exhibitionName) : Exhibition(exhibitionName, {}) {}

  // exhibition featured artworks delegating constructor
  Exhibition(Artwork* art);
  
  // delete the copy constructor
  Exhibition(const Exhibition&) = delete;

  void addToExhibition(Artwork* art);
  void showExhibition() const;
};
