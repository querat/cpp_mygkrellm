//
// MachineUserNameModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/MachineUserNameModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 19:04:52 2016 querat_g
// Last update Sat Jan 23 21:04:42 2016 querat_g
//

#ifndef MACHINEUSERNAMEMODULE_HH_
# define MACHINEUSERNAMEMODULE_HH_

#include "MonitorModule.hh"

class MachineUserNameModule : public MonitorModule
{
public:
  MachineUserNameModule();
  MachineUserNameModule(MachineUserNameModule const &other);
  MachineUserNameModule& operator=(MachineUserNameModule const &other);
  ~MachineUserNameModule();

private:
  std::string		_machineName;
  std::string		_userName;

public:
  void			loadData();
  
  std::string const &	getMachineName() const;
  std::string const &	getUserName() const;
};

#endif
