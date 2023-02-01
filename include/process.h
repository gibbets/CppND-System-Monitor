#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(const int pid, const std::string& cmd, const std::string& user);
  int Pid();                               
  std::string User();                      
  std::string Command();                  
  float CpuUtilization();             
  std::string Ram();                       
  long int UpTime();                      
  bool operator<(Process const& a) const;  

 
 private:
  int const m_pid;
  std::string const m_cmd;
  std::string const m_user;
  long oldActive = 0;
  long oldTotal = 0;
};

#endif