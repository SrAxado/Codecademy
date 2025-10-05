#include <iostream>
#include "Restaurant.hpp"

using namespace std;
int main() {
  // Initialize Restaurant with 2 tables
  Restaurant restauranteChines = Restaurant(2);

  // Create customers and make reservations
  Customer zeDaEsquina = Customer("Zé da Esquina");
  restauranteChines.reserveTable(zeDaEsquina&);
  
  // Release a table and demonstrate waitlist notification

  return 0;
}