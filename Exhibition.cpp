#include "Exhibition.hpp"
#include <iostream>

// parameterized constructor
Exhibition::Exhibition(const std::string& exhibitionName, Artwork* art)
    : name(exhibitionName) {
      if (art != nullptr) {
        featuredArtworks.push_back(art);
      }
    }

// parameterized artwork constructor, delegating to main constructor
Exhibition::Exhibition(Artwork* art) : Exhibition("Untitled", art) {}

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
