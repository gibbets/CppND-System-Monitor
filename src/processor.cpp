#include "processor.h"
#include "linux_parser.h"

float Processor::Utilization() {
    static auto oldActive = 0;
    static auto oldIdle = 0;
    auto newActive = LinuxParser::ActiveJiffies();
    auto newIdle = LinuxParser::IdleJiffies();

    auto utilization = static_cast<float>(newActive - oldActive)/(newActive - oldActive + newIdle - oldIdle);

    oldActive = newActive;
    oldIdle = newIdle;
    
    return utilization;
    
}