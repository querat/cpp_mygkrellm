//
// MonitorCore.hpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 17:48:53 2016 querat_g
// Last update Sun Jan 24 04:36:43 2016 Adrien Schmouker
//

#ifndef MONITORCORE_HPP_
# define MONITORCORE_HPP_

#include <iostream>
#include <string>
#include <map>
#include "IMonitorModule.hh"
#include "GKrellM.h"

class MonitorCore
{

public:
  // Coplien
  MonitorCore();
  MonitorCore(MonitorCore const &other);
  ~MonitorCore();
  MonitorCore&		
  operator=(MonitorCore const &other);
  
private:
  // Attributes
  std::map<std::string, IMonitorModule*>		_modules;

  void	createUnknown();
  void	createCpu();
  void	createOS();
  void	createUser();
  void	createTime();
  void	createRam();


  
public:
  // Members functions

  void		coreInit(int ac, char **av, MonitorCore &core);
  void		reload();
  std::map<std::string, IMonitorModule*> const &getModulesConst() const;
  std::map<std::string, IMonitorModule*> &	getModules();
  
};

#endif 
