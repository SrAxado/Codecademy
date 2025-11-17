#include "Logger.hpp"
#include "values.hpp"
#include "Algorithms.hpp"
using namespace std;

void Algorithms::singleLoop() {
  for (int i = 0; i < 1000; ++i) {
  }
}

void Algorithms::doubleLoop() {
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
    }
  }
}

void Algorithms::tripleLoop() {
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      for (int k = 0; k < 1000; ++k) {
      }
    }
  }
}
