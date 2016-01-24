//
// CpuModule.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/CpuModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 21:16:14 2016 querat_g
// Last update Sun Jan 24 02:13:48 2016 querat_g
//

#include <fstream>
#include <bitset>
#include <string>
#include "CpuModule.hh"

// Coplien
CpuModule::CpuModule() 
  : _cpuName("")
  , _cpuUsage("")
  , _cpuArch("")
{
  _type = GKrellM::MODULE_CPU;
}

CpuModule::CpuModule(CpuModule const &other)
  : MonitorModule()
  , _cpuName(other.getCpuName())
  , _cpuUsage(other.getCpuUsage())
  , _cpuArch(other.getCpuArch())
{
  _type = GKrellM::MODULE_CPU;
}

CpuModule & 
CpuModule::operator=(CpuModule const &other) {
  _cpuName = other.getCpuName();
  return (*this);
}

CpuModule::~CpuModule() {}

// Getters
std::string const &
CpuModule::getCpuName() const {
  return (_cpuName);
}
std::string const &
CpuModule::getCpuUsage() const {
  return (_cpuUsage);
}
std::string const &
CpuModule::getCpuArch() const {
  return (_cpuArch);
}

// Member functions
void
CpuModule::loadData() {

  // Cpu's name
  _cpuName = GKrellM::execBashCommand("cat /proc/cpuinfo    | "
				      "grep -i 'model name' | "
				      "cut -d: -f2          | "
				      "sed -E 's/^\\s//g'   | "
				      "head -n1 |head -c -1");
  
  // Cpu's architecture
  _cpuArch = GKrellM::execBashCommand("lscpu                  | "
				      "grep -i 'architecture' | "
				      "cut -d: -f2            | "
				      "sed -E 's/\\s//g'      | "
				      "head -c -1"	      );  
  
  // Cpu's average load in percents
  _cpuUsage = std::string(this->calcCpuUsage());
}
