#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(const int pid, const string& cmd, const string& user) : m_pid(pid), m_cmd(cmd), m_user(user) {

}

int Process::Pid() { return m_pid; }

float Process::CpuUtilization() { 
    auto newActive = LinuxParser::ActiveJiffies(m_pid);
    auto newTotal = LinuxParser::Jiffies();

    auto utilization = static_cast<float>(newActive - oldActive) / (newTotal - oldTotal);

    oldActive = newActive;
    oldTotal = newTotal;

    return utilization;
}

string Process::Command() { return m_cmd; }

string Process::Ram() { return LinuxParser::Ram(m_pid); }

string Process::User() { return m_user; }

long int Process::UpTime() { return LinuxParser::UpTime(m_pid); }

bool Process::operator<(Process const& a) const { return m_pid < a.m_pid; }