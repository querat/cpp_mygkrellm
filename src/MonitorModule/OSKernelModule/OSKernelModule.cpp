//
// OSKernelModule.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/OSKernelModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 18:59:12 2016 querat_g
// Last update Sun Jan 24 00:06:40 2016 querat_g
//

#include "OSKernelModule.hh"

// Ctor Dtor
OSKernelModule::OSKernelModule()
  : MonitorModule()
  , _osName("")
  , _kernelName("")
{
  _type = GKrellM::MODULE_OSKERNEL; 
}

OSKernelModule::OSKernelModule(OSKernelModule const &other) 
  : MonitorModule()
  , _osName(other.getOsName())
  , _kernelName(other.getKernelName())
{
  _type = GKrellM::MODULE_OSKERNEL;
}

OSKernelModule& 
OSKernelModule::operator=(OSKernelModule const &other) {
  _osName = other.getOsName();
  _kernelName = other.getKernelName();
  return (*this);
}

OSKernelModule::~OSKernelModule()
{}

void
OSKernelModule::loadData() {
  // TODO
  _kernelName = GKrellM::execBashCommand("uname -r | head -c -1");
  _osName = GKrellM::execBashCommand("uname -v | cut -d\\  -f1 | head -c -1");
}

// Getters
std::string const &
OSKernelModule::getOsName() const {
  return (_osName);
}
std::string const &
OSKernelModule::getKernelName() const {
  return (_kernelName);
}

