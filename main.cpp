#include <iostream>
#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "MexicanJapaneseFusion.hpp"

using namespace std;

int main() {
    cout << "Testing Restaurant Inheritance Hierarchy:" << endl;
    
    MexicanRestaurant laCasa = MexicanRestaurant("La Casa", "123 Spice Lane", 4);
    JapaneseRestaurant sakura = JapaneseRestaurant("Sakura", "456 Sushi Road", true);
    MexicanJapaneseFusion fusionFiesta = MexicanJapaneseFusion("Fusion Fiesta", "789 Fusion Ave", 3, true);
    
    laCasa.addMenuItem(MenuItem("Tacos", 8.99));
    laCasa.addMenuItem(MenuItem("Enchiladas", 12.99));
    
    sakura.addMenuItem(MenuItem("Sushi Roll", 14.99));
    sakura.addMenuItem(MenuItem("Ramen", 11.99));
    
    fusionFiesta.addMenuItem(MenuItem("Sushi Tacos", 15.99));
    fusionFiesta.addMenuItem(MenuItem("Wasabi Guacamole", 7.99));
    
    laCasa.displayInfo();
    laCasa.describeCuisine();
    laCasa.removeLastMenuItem();
    laCasa.displayMenu();

    sakura.displayInfo();
    sakura.describeCuisine();
    sakura.displayMenu();

    fusionFiesta.displayInfo();
    fusionFiesta.describeCuisine();
    fusionFiesta.displaySpecialty();
    fusionFiesta.removeLastMenuItem();
    fusionFiesta.displayMenu();

    Restaurant tasca = Restaurant("Tasca do Ze", "Rua das Telhas, 233");
    tasca.addMenuItem(MenuItem("Sarrabulho", 7.50));
    tasca.addMenuItem(MenuItem("Feijoada", 8.11));
    tasca.displayInfo();
    tasca.describeCuisine();
    tasca.displayMenu();

    // cout << tasca.menu[0] << endl;  // member Restaurant::menu is inaccessible

    return 0;
}
