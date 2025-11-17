#include "Logger.hpp"
using namespace std;

// Logs to the console the log location
void Logger::logLocation(const std::string& message,
                         const std::string& file,
                         int line,
                         const std::string& function) {
  std::cout << "[LOG] " << file << ":" << line << " (" << function << ") - " << message << std::endl;
}

TIME_POINT Logger::startTime;

// Log start time
void Logger::startTimer() {
  startTime = NOW;
}

// Get end time and log to the console the duration
void Logger::stopTimer(const std::string& function) {
  TIME_POINT endTime = NOW;
  auto duration = DURATION(startTime, endTime);
  std::cout << "[TIMER] (" << function << ") - Duration: " << duration << " µs" << std::endl;
}

// Logs to the console the compiler info
void Logger::printCompileInfo() {
  std::cout << "[INFO] Date: " << __DATE__ << std::endl;
  std::cout << "[INFO] Time: " << __TIME__ << std::endl;

  #ifdef __GNUC__
    std::cout << "[INFO] Compiler: GCC " << __GNUC__ << "." << __GNUC_MINOR__ << std::endl;
  #elif defined(__clang__)
    std::cout << "[INFO] Compiler: Clang " << __clang_major__ << "." << __clang_minor__ << std::endl;
  #elif _MSC_VER
    std::cout << "[INFO] Compiler: MSVC " << __MSC_VER << std::endl;
  #endif

  std::cout << "[INFO] " << PLATFORM << std::endl;
}
