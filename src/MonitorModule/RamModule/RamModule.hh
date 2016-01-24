//
// RamModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorCore
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 18:25:50 2016 querat_g
// Last update Sat Jan 23 21:10:17 2016 querat_g
//

#ifndef RAMMODULE_HH_
# define RAMMODULE_HH_

#include <string>
#include "MonitorModule.hh"

class RamModule : public MonitorModule
{
public:
  RamModule();
  RamModule(RamModule const &other);
  RamModule& operator=(RamModule const &other);
  ~RamModule();
  
private:
  std::string	_totalRam;
  std::string	_freeRam;
  std::string	_usedRam;

  std::string	_totalSwap;
  std::string	_freeSwap;
  std::string	_usedSwap;

public:
  void		loadData(void);

  std::string const &	getTotalRam() const;
  std::string const &	getFreeRam() const;
  std::string const &	getUsedRam() const;
  
  std::string const &	getTotalSwap() const;
  std::string const &	getFreeSwap() const;
  std::string const &	getUsedSwap() const;
  

};

#endif
