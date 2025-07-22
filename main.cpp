#include <iostream>
#include "Restaurant.hpp"

using namespace std;
int main() {
  // Initialize Restaurant with 2 tables
  Restaurant restauranteChines = Restaurant(2);

  // Create customers and make reservations
  shared_ptr<Customer> customer1 = make_shared<Customer>("Zé da Esquina");
  shared_ptr<Customer> customer2 = make_shared<Customer>("Maria do Bar");
  shared_ptr<Customer> customer3 = make_shared<Customer>("João da Esquina");
  shared_ptr<Customer> customer4 = make_shared<Customer>("Pedro do Bar");
  
  restauranteChines.reserveTable(customer1);
  restauranteChines.reserveTable(customer2);
  restauranteChines.reserveTable(customer3);
  restauranteChines.reserveTable(customer4);
  
  // restauranteChines.notifyWaitlist();

  // Release a table and demonstrate waitlist notification
  restauranteChines.printActiveCustomersList();
  restauranteChines.releaseTable(1);
  restauranteChines.printActiveCustomersList();
  restauranteChines.printWaitlist();

  return 0;
}


/*

You’ve successfully finished creating a basic restaurant management system in C++. Congratulations!

As a challenge, try to make some improvements to your system. For example, you could do the following:

  -- Improve feedback by printing strings regarding the results of a reserve or release operation.
  -- Improve the release table functionality by removing the customer from the activeCustomer list.
  -- Add new methods that simulate other aspects of a restaurant (such as a loyalty program where a select group of customers get special deals).

*/