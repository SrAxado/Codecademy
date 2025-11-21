#include <iostream>
#include "values.hpp"
#include "Logger.hpp"
// #include  "mode.hpp"  // there's no such file, but assuming it's part of the project
#include "Algorithms.hpp"
using namespace std;

int main() {
  #ifdef DEBUG_MODE
    COMPILE_INFO();

    // Logger logTest;
    Algorithms algorithmsBench;
    algorithmsBench.singleLoop();
    algorithmsBench.doubleLoop();
    algorithmsBench.tripleLoop();

  #endif

  return 0;
}
