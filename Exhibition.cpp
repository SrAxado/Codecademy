#include "Exhibition.hpp"
#include <iostream>

void Exhibition::addToExhibition(Artwork* art) {
  featuredArtworks.push_back(art);
}

void Exhibition::showExhibition() const {
  for (const auto& art : featuredArtworks) {
    std::cout << "ID: " << art->id
              << ", Title: " << (art->title.empty() ? "N/A" : art->title)
              << ", Artist: " << (art->artistName.empty() ? "N/A" : art->artistName)
              << ", Medium: " << art->medium
              << ", Price: $" << art->price
              << ", Status: " << (art->sold ? "Sold" : "Available")
              << "\n";
  }
}
