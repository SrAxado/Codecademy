#include <iostream>
#include "FlightBooking.hpp"
using namespace std;

int main() {
  // Creating an instance of FlightBooking class
  FlightBooking booking1("FlightA", "John Doe");
  FlightBooking booking2("FlightB", "Jane Smith");

  booking1.bookFlight();
  booking2.bookFlight();

  booking1.showFlightDetails();
  booking2.showFlightDetails();

  // Show total bookings
  FlightBooking::showTotalBookings();
  FlightBooking::showTotalNumBookings();

  // Demonstrating cancellation and use of const function
  booking1.cancelFlight();
  booking2.cancelFlight();

  FlightBooking::showTotalBookings();
  FlightBooking::showTotalNumBookings();

  booking1.printHistory();
  booking2.printHistory();

  // Demonstrating auto keyword
  booking1.demonstrateAuto();

  return 0;
}
