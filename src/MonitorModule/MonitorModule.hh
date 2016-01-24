//
// MonitorModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 17:37:10 2016 querat_g
// Last update Sun Jan 24 04:44:51 2016 querat_g
//

#ifndef MONITORMODULE_HH_
# define MONITORMODULE_HH_

#include <iostream>
#include <string>
#include "GKrellM.h"
#include "MonitorCore.hh"
#include "IMonitorModule.hh"

class MonitorModule : public IMonitorModule
{
public:
  MonitorModule();
  virtual ~MonitorModule();
  MonitorModule(MonitorModule const &other);
  MonitorModule &operator=(MonitorModule const &other);
protected:
  GKrellM::ModuleType	_type;
  
public:
  virtual void		loadData(void) = 0;
  GKrellM::ModuleType	getType() const;
};

#endif
