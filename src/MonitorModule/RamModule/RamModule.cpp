//
// RamModule.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorCore
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 18:27:17 2016 querat_g
// Last update Sun Jan 24 00:07:33 2016 querat_g
//

#include <sstream>
#include "RamModule.hh"

RamModule::RamModule() 
  : _totalRam("")
  , _freeRam("")
  , _usedRam("")
  , _totalSwap("")
  , _freeSwap("")
  , _usedSwap("")
{
  _type = GKrellM::MODULE_RAM;
}

RamModule::RamModule(RamModule const &other) 
  : MonitorModule()
  , _totalRam(other.getTotalRam())
  , _freeRam(other.getFreeRam())
  , _usedRam(other.getUsedRam())
  , _totalSwap(other.getTotalSwap())
  , _freeSwap(other.getFreeSwap())
  , _usedSwap(other.getUsedSwap())
{
  _type = GKrellM::MODULE_RAM;
}

RamModule& 
RamModule::operator=(RamModule const &other) {
  _totalRam = other.getTotalRam();
  _freeRam = other.getFreeRam();
  _usedRam = other.getUsedRam();
  _totalSwap = other.getTotalSwap();
  _freeSwap = other.getFreeSwap();
  _usedSwap = other.getUsedSwap();
  return (*this);
}

RamModule::~RamModule() {}

// Member function
void
RamModule::loadData() {
  int			t, f, used;
  std::stringstream	tmp;
  
  // Total ram
  _totalRam = GKrellM::execBashCommand("cat /proc/meminfo | grep -i memtotal | sed -E 's/\\s//g' | cut -d: -f2 | sed -E 's/.{5}$//g' | head -c -1");
  
  // free Ram
  _freeRam = GKrellM::execBashCommand("cat /proc/meminfo | grep -i memfree | sed -E 's/\\s//g' | cut -d: -f2 | sed -E 's/.{5}$//g' | head -c -1");
  
  // Ram currently in use
  std::stringstream(_totalRam) >> t;
  std::stringstream(_freeRam) >> f;
  used = t - f;  
  tmp << used;
  _usedRam = tmp.str();

  // Total swap
  _totalSwap = GKrellM::execBashCommand("cat /proc/meminfo | grep -i swapTotal | sed -E 's/\\s//g' | cut -d: -f2 | sed -E 's/.{5}$//g' | head -c -1");

  // Free swap
  _freeSwap = GKrellM::execBashCommand("cat /proc/meminfo | grep -i swapFree | sed -E 's/\\s//g' | cut -d: -f2 | sed -E 's/.{5}$//g' | head -c -1");

  // Used swap
  std::stringstream(_totalSwap) >> t;
  std::stringstream(_freeSwap) >> f;
  used = t - f;
  tmp.str(""); // empties tmp
  tmp << used;
  _usedSwap = tmp.str();  
}

// Getters
std::string const &	
RamModule::getTotalRam() const {
  return (_totalRam);
}
std::string const &	
RamModule::getFreeRam() const {
  return (_freeRam);
}
std::string const &	
RamModule::getUsedRam() const {
  return (_usedRam);
}  
std::string const &	
RamModule::getTotalSwap() const {
  return (_totalSwap);
}
std::string const &	
RamModule::getFreeSwap() const {
  return (_freeSwap);
}
std::string const &	
RamModule::getUsedSwap() const {
  return (_usedSwap);
}
