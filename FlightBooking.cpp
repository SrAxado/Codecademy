#include "FlightBooking.hpp"

int FlightBooking::availableSeats = 100;
int FlightBooking::totalBookings = 0;
int FlightBooking::totalNumBookings = 0;
int FlightBooking::totalCancellations = 0;

FlightBooking::FlightBooking(string flightName, string passengerName)
  : bookingID(0), flightName(flightName), passengerName(passengerName) {}

void FlightBooking::bookFlight() {
  if (availableSeats > 0) {
    bookingID = ++totalBookings;
    totalNumBookings++;
    availableSeats--;  // Reduce available seats
    cout << "Flight booked for " << passengerName << " on " << flightName << endl;
    cout << "Booking ID: " << bookingID << endl;
    historyBookings.push_back("Booking ID #" + std::to_string(bookingID) + " added.");
  } else {
    cout << "No seats available!" << endl;
    historyBookings.push_back("Tried to book an already full flight.");
  }
}

void FlightBooking::cancelFlight() {
  if (bookingID != 0) {
    cout << "Flight booking cancelled for " << passengerName << endl;
    cout << "Booking ID: " << bookingID << endl;
    totalBookings--;
    totalCancellations++;
    historyBookings.push_back("Booking ID #" + std::to_string(bookingID) + " cancelled.");
  } else {
    cout << "No booking to cancel!" << endl;
    historyBookings.push_back("Tried to cancel a non-existant booking.");
  }
}

void FlightBooking::showFlightDetails() const {
  cout << "Passenger: " << passengerName << endl;
  cout << "Flight: " << flightName << endl;
  cout << "Booking ID: " << bookingID << endl;
}

void FlightBooking::demonstrateAuto() const {
  auto flightInfo = "Flight: " + flightName + " for " + passengerName;
  cout << "Auto-deduced variable: " << flightInfo << endl;
}

void FlightBooking::showTotalBookings() {
  cout << "Total Bookings: " << totalBookings << endl;
}


void FlightBooking::showTotalNumBookings(){
  cout << "Total number of bookings: " << totalNumBookings << endl;
}

void FlightBooking::showTotalCancellations() {
  cout << "Number of cancellations: " << totalCancellations << endl;
}

void FlightBooking::showTotalRevenue() {
}

void FlightBooking::printHistory() const {
  cout << "--- " << passengerName << "'s booking history ---" << endl;
  for (string evnt : historyBookings)
    cout << evnt << endl;
  cout << "=================================" << endl;
}