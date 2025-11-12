#include "Gallery.hpp"
#include <iostream>

void Gallery::addArtwork(Artwork&& art) {
  artworks.push_back(std::move(art));
}

void Gallery::sellArtwork(int id) {
  for (auto& art : artworks) {
    if (art.id == id) {
      art.markAsSold();
      break;
    }
  }
}

void Gallery::displayGallery() const {
  for (const auto& art : artworks) {
    std::cout << "ID: " << art.id
              << ", Title: " << (art.title.empty() ? "N/A" : art.title)
              << ", Artist: " << (art.artistName.empty() ? "N/A" : art.artistName)
              << ", Medium: " << art.medium
              << ", Price: $" << art.price
              << ", Status: " << (art.sold ? "Sold" : "Available")
              << "\n";
  }
}
