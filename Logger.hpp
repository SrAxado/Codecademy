#include "values.hpp"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class Logger {
private:
  // Timer start time
  static TIME_POINT startTime;

public:
  static void logLocation(const std::string& message,
                           const std::string& file,
                           int line,
                           const std::string& function);

  // Timer functions
  static void startTimer();
  static void stopTimer(const std::string& function);
  
  // Logs to the console the compiler info
  static void printCompileInfo();
};

// Macros for easy usage
// Log location macro
#define LOG_LOCATION(msg) Logger::logLocation(msg, __FILE__, __LINE__, __func__)
// Timer macros
#define START_TIMER() Logger::startTimer()
#define STOP_TIMER() Logger::stopTimer(__func__)
// Compiler info macro
#define COMPILE_INFO() Logger::printCompileInfo()