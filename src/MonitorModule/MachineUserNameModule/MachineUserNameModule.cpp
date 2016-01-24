//
// MachineUserNameModule.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/MachineUserNameModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 19:04:50 2016 querat_g
// Last update Sun Jan 24 00:08:42 2016 querat_g
//

#include "MachineUserNameModule.hh"

// Ctor Dtor
MachineUserNameModule::MachineUserNameModule()
  : _machineName("")
  , _userName("")
{
  _type = GKrellM::MODULE_USERNAME; 
}

MachineUserNameModule::MachineUserNameModule(MachineUserNameModule const &other) 
  : MonitorModule()
  , _machineName(std::string(other.getMachineName()))
  , _userName(std::string(other.getUserName()))
{
  _type = GKrellM::MODULE_USERNAME;
}

MachineUserNameModule&
MachineUserNameModule::operator=(MachineUserNameModule const &other) {
  _machineName = std::string(other.getMachineName());
  _userName = std::string(other.getUserName());
  return (*this);
}
  

MachineUserNameModule::~MachineUserNameModule() {}

// Member function
void
MachineUserNameModule::loadData() {
  _machineName = GKrellM::execBashCommand("uname -n | head -c -1");
  _userName    = GKrellM::execBashCommand("whoami | head -c -1");
}
  
// Getters
std::string const &
MachineUserNameModule::getMachineName() const {
  return (_machineName);
}
std::string const &
MachineUserNameModule::getUserName() const {
  return (_userName);
}
 
