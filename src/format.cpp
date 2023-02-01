#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"

using std::string;
using std::chrono::duration_cast;
using std::chrono::hours;
using std::chrono::seconds;
using std::chrono::minutes;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long secondsPassed) { 
    const auto totalSeconds = seconds(secondsPassed);

    const auto hrs = duration_cast<hours>(totalSeconds);
    const auto mins = duration_cast<minutes>(totalSeconds - hrs);
    const auto secs = duration_cast<seconds>(totalSeconds - hrs - mins);

    std::stringstream ret;
    ret << std::setw(2) << std::setfill('0') << hrs.count() << ":"
    << std::setw(2) << std::setfill('0') << mins.count() << ":"
    << std::setw(2) << std::setfill('0') << secs.count();
    
    return ret.str(); 
}