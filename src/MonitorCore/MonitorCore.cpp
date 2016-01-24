//
// MonitorCore.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 17:50:45 2016 querat_g
// Last update Sun Jan 24 06:19:24 2016 Adrien Schmouker
//

#include <iostream>
#include <string>
#include "MonitorCore.hh"
#include "CpuModule.hh"
#include "DateTimeModule.hh"
#include "MachineUserNameModule.hh"
#include "OSKernelModule.hh"
#include "RamModule.hh"
#include "IMonitorModule.hh"

// Coplien form
MonitorCore::MonitorCore() {

}
MonitorCore::MonitorCore(MonitorCore const &other) {
  _modules = other.getModulesConst();
}
MonitorCore&
MonitorCore::operator=(MonitorCore const &other) {
  _modules = other.getModulesConst();
  return (*this);
}
MonitorCore::~MonitorCore() {
  
}

void
MonitorCore::createUnknown() {}
void
MonitorCore::createCpu() {
  _modules["CpuModule"] = new CpuModule();
}
void
MonitorCore::createOS() {
  _modules["OSKernelModule"] = new OSKernelModule();
}
void
MonitorCore::createUser() {
  _modules["MachineUserNameModule"] = new MachineUserNameModule();
}
void
MonitorCore::createTime() {
  _modules["DateTimeModule"] = new DateTimeModule();
}
void
MonitorCore::createRam() {
  _modules["RamModule"] = new RamModule();
}




void	MonitorCore::coreInit(int ac, char **av, MonitorCore &core)
{
  std::string   tab[] = {
    "Inconnu ?"
    , "-cpu"
    , "-OS"
    , "-user"
    , "-time"
    , "-ram"
  };
  
  void(MonitorCore::*ptr[6])() = {
    &MonitorCore::createUnknown
    , &MonitorCore::createCpu
    , &MonitorCore::createOS
    , &MonitorCore::createUser
    , &MonitorCore::createTime
    , &MonitorCore::createRam
  };

  std::string   arg;
  for (int i = 2; i < ac && i < 8; i++)
    {
      arg.assign(av[i]);
      for (int j = 0; j < 6; j++)
        {
          if (arg == tab[j]){
	    (core.*ptr[j])();
	  }
	}
    }
} //!coreInit

// Getters
std::map<std::string, IMonitorModule*> const & 
MonitorCore::getModulesConst() const {
  return (_modules);
}

std::map<std::string, IMonitorModule*>  & 
MonitorCore::getModules() {
  return (_modules);
}
