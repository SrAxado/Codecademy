#pragma once

#include "Artwork.hpp"
#include <vector>

class Exhibition {
public:
  std::vector<Artwork*> featuredArtworks;

  void addToExhibition(Artwork* art);
  void showExhibition() const;
};
