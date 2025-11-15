#pragma once

#include "Artwork.hpp"
#include <vector>

// Stores and manages a collection of artworks
class Gallery {
public:
  std::vector<Artwork> artworks;

  // Adds an artwork to the gallery by moving it into the collection
  void addArtwork(Artwork&& art);
  // Marks an artwork as sold by ID
  void sellArtwork(int id);
  // Displays all artworks in the gallery
  void displayGallery() const;

  Gallery() = default;

  // delete the copy constructor
  Gallery(const Gallery&) = delete;
};
