FUSION KITCHEN

Imagine that you’re designing a system to manage different types of restaurants. You notice that all restaurants share some basic features - they all have a name, an address, and they all serve some kind of food. However, each type of restaurant also has its unique characteristics. A Mexican restaurant might have a spice level rating, while a Japanese restaurant might have a traditional seating style.

In this project, we’ll use inheritance in C++ to model these relationships. We’ll start with a base Restaurant class that contains the common features all restaurants share. Then, we’ll create specialized restaurant classes for different cuisines using a single inheritance. Finally, we’ll explore the exciting world of fusion cuisine by creating a Mexican-Japanese fusion restaurant using multiple inheritance!

Think of it like a family tree:

    -- The Restaurant class is the parent, containing all the basic features.
    -- Specific restaurant types (Mexican, Japanese) are children, inheriting these basic features while adding their own unique traits.
    -- The fusion restaurant is like a child of both Mexican and Japanese restaurants, combining features from both cuisines!

Through this project, you’ll practice how to:

    -- create a base class with common functionality
    -- use single inheritance to create specialized restaurant types
    -- implement multiple inheritance to create a fusion restaurant
    -- manage restaurant-specific features and menus

The source code for this project will be organized into the following files:

    -- Restaurant base class: Restaurant.hpp and Restaurant.cpp
    -- MenuItem class: MenuItem.hpp and MenuItem.cpp
    -- MexicanRestaurant class: MexicanRestaurant.hpp and MexicanRestaurant.cpp
    -- JapaneseRestaurant class: JapaneseRestaurant.hpp and JapaneseRestaurant.cpp
    -- MexicanJapaneseRestaurant class: MexicanJapaneseRestaurant.hpp and MexicanJapaneseRestaurant.cpp



