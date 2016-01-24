//
// MonitorModule.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 17:38:47 2016 querat_g
// Last update Sun Jan 24 00:15:18 2016 querat_g
//

#include <iostream>
#include <string>
#include "MonitorModule.hh"

MonitorModule::MonitorModule()
  : _type(GKrellM::MODULE_UNKNOWN)
{}

MonitorModule::MonitorModule(MonitorModule const &other) {
  (void)other;
}
MonitorModule&
MonitorModule::operator=(MonitorModule const &other) {
  (void)other;
  return (*this);
}
MonitorModule::~MonitorModule() {}

GKrellM::ModuleType
MonitorModule::getType() const {
  return (_type);
}			
