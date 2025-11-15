#include "Gallery.hpp"
#include "Exhibition.hpp"
#include <iostream>
#include <iomanip>

int main() {
  std::cout << std::fixed << std::setprecision(0);

  Artwork sunflowers("Sunflowers", "Vincent van Gogh", 1, "oil painting", 1200000);

  std::cout << "ID: " << sunflowers.id << ", Title: " << sunflowers.title << ", Artist: " << sunflowers.artistName 
    << ", Medium: " << sunflowers.medium << ", Price: " << sunflowers.price << std::endl;

  Artwork starryNight("Starry Night", "Vincent van Gogh", 2, "oil painting", 1000000);

  Artwork galleryCopy(starryNight); // Using copy constructor

  Artwork artworkForTransfer = std::move(starryNight); // Using move constructor

  Artwork auctionTransfer = std::move(artworkForTransfer);

  std::cout << "ID: " << galleryCopy.id << ", Title: " << galleryCopy.title << ", Artist: " << galleryCopy.artistName 
    << ", Medium: " << galleryCopy.medium << ", Price: " << galleryCopy.price << std::endl;

  std::cout << "ID: " << auctionTransfer.id << ", Title: " << auctionTransfer.title << ", Artist: " << auctionTransfer.artistName 
    << ", Medium: " << auctionTransfer.medium << ", Price: " << auctionTransfer.price << std::endl;

    
  std::cout << "ID: " << starryNight.id << ", Title: " << starryNight.title << ", Artist: " << starryNight.artistName 
  << ", Medium: " << starryNight.medium << ", Price: " << starryNight.price << std::endl;
  
  std::cout << "ID: " << artworkForTransfer.id << ", Title: " << artworkForTransfer.title << ", Artist: " << artworkForTransfer.artistName 
    << ", Medium: " << artworkForTransfer.medium << ", Price: " << artworkForTransfer.price << std::endl;

  /*
  OUTPUT:
  ID: 1, Title: Sunflowers, Artist: Vincentvan Gogh, Medium: oil painting, Price: 1200000
  ID: 2, Title: Starry Night, Artist: Vincent van Gogh, Medium: oil painting, Price: 1000000
  ID: 2, Title: Starry Night, Artist: Vincent van Gogh, Medium: oil painting, Price: 1000000
  ID: 2, Title: , Artist: , Medium: , Price: 1000000
  ID: 2, Title: , Artist: , Medium: , Price: 1000000
  

  -- 14. --
  */

  Artwork theScream("The Scream", "Edvard Munch", 3, "tempera", 1500000);
  Artwork digitalDream("Digital Dream", "Alice Doe", 4, "digital art", 5000);

  Gallery gallery;
  gallery.addArtwork(std::move(sunflowers));  // transfer ownership to the gallery, avoiding unnecessary copying
  gallery.addArtwork(std::move(theScream));
  gallery.addArtwork(std::move(digitalDream));

  gallery.displayGallery();

  // Exhibition exhibition;  // error -- default constructor was deleted
  Exhibition exhibition("A flower and a scream", &gallery.artworks[0]);
  exhibition.addToExhibition(&gallery.artworks[2]);
  exhibition.addToExhibition(&gallery.artworks[1]);

  std::cout << "--- Exhibition displays ---" << std::endl;
  exhibition.showExhibition();

  gallery.sellArtwork(4); // sell artwork with ID 4

  exhibition.showExhibition();

  return 0;
}


/*

Artwork public members:

  std::string title;
  std::string artistName;
  int id;
  std::string medium;
  double price;
  bool sold;

*/