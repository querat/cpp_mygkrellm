//
// IMonitorModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/MonitorModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 17:31:32 2016 querat_g
// Last update Sun Jan 24 04:44:36 2016 querat_g
//

#ifndef IMONITORMODULE_HH_
# define IMONITORMODULE_HH_

#include "GKrellM.h"

class IMonitorModule
{
public:
  virtual ~IMonitorModule() {}

public:
  virtual void		loadData(void) = 0;
  virtual GKrellM::ModuleType	getType() const = 0;
};

#endif
