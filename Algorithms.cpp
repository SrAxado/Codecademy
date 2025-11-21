#include "Logger.hpp"
#include "values.hpp"
#include "Algorithms.hpp"
using namespace std;

void Algorithms::singleLoop() {
  LOG_LOCATION("Running single loop");  // Logs the current code location

  START_TIMER();  // Starts the timer
  for (int i = 0; i < 1000; ++i) {
  }
  STOP_TIMER(); // Stops the timer and logs the duration
}

void Algorithms::doubleLoop() {
  LOG_LOCATION("Running double loop");  // Logs the current code location

  START_TIMER();  // Starts the timer
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
    }
    // STOP_TIMER(); // Stops time in an intermediate loop and logs its duration
  }
  STOP_TIMER(); // Stops the timer and logs the duration
}

void Algorithms::tripleLoop() {
  LOG_LOCATION("Running triple loop");  // Logs the current code location

  START_TIMER();  // Starts the timer
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      for (int k = 0; k < 1000; ++k) {
      }
      // STOP_TIMER(); // Stops time in the first intermediate loop and logs its duration
    }
    // STOP_TIMER(); // Stops time in the second intermediate loop and logs its duration
  }
  STOP_TIMER(); // Stops the timer and logs the duration
}
