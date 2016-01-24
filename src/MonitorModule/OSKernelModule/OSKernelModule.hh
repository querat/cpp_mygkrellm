//
// OSKernelModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/OSKernelModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 18:55:16 2016 querat_g
// Last update Sun Jan 24 00:02:24 2016 querat_g
//

#ifndef OSKERNELMODULE_HH_
# define OSKERNELMODULE_HH_

#include <string>
#include "GKrellM.h"
#include "MonitorModule.hh"

class OSKernelModule : public MonitorModule
{
public:
  OSKernelModule();
  OSKernelModule(OSKernelModule const &other);
  OSKernelModule& operator=(OSKernelModule const &other);
  ~OSKernelModule();

private:
  std::string	_osName;
  std::string	_kernelName;

public:
  void		loadData();
  std::string const &getOsName() const;
  std::string const &getKernelName() const;

};

#endif
