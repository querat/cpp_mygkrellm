//
// CpuModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/CpuModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 21:16:35 2016 querat_g
// Last update Sun Jan 24 01:59:10 2016 querat_g
//

#ifndef CPUMODULE_HH_
# define CPUMODULE_HH_

#include <vector>
#include "MonitorModule.hh"

class CpuModule : public MonitorModule
{
public:
  CpuModule();
  CpuModule(CpuModule const &other);
  CpuModule & operator=(CpuModule const &other);
  ~CpuModule();

private:
  std::string				_cpuName;
  std::string				_cpuUsage;
  std::string				_cpuArch;

private:
  std::string				calcCpuUsage() const;

public:
  void					loadData();
  
  std::string const &			getCpuUsage() const;
  std::string const &			getCpuName() const;
  std::string const &			getCpuArch() const;
  std::string const &			getData() const;
};

#endif
