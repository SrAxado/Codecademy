#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FlightBooking {
private:
  mutable int bookingID;
  static int totalBookings;
  static int availableSeats;
  static int totalNumBookings;
  static int totalCancellations;
  static int totalRevenue;

  string flightName;
  string passengerName;

  vector<string> historyBookings;

public:
  FlightBooking(string flightName, string passengerName);
  void bookFlight();
  void cancelFlight();
  void showFlightDetails() const;
  void demonstrateAuto() const;
  static void showTotalBookings();
  static void showTotalNumBookings();
  static void showTotalCancellations();
  static void showTotalRevenue();
  void printHistory() const;
};