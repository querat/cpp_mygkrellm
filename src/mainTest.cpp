//
// main.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Fri Jan 22 22:20:31 2016 querat_g
// Last update Sun Jan 24 06:21:46 2016 Adrien Schmouker
//

#include <iostream>
#include <string>
#include "DateTimeModule.hh"
#include "GKrellM.h"
#include "MachineUserNameModule.hh"
#include "RamModule.hh"
#include "CpuModule.hh"
#include "OSKernelModule.hh"

int	main()
{
  MonitorCore		core;

  CpuModule		*p = new CpuModule();
  RamModule		*a = new RamModule();
  DateTimeModule	*b = new DateTimeModule();
  MachineUserNameModule	*c = new MachineUserNameModule();
  OSKernelModule	*d = new OSKernelModule();


  while (true) {
  a->loadData();
  b->loadData();
  c->loadData();
  d->loadData();
  p->loadData();

  std::cout << "cpu usage  : " << p->getCpuUsage() << "%" << std::endl;
  std::cout << "machine    : " << c->getMachineName() << std::endl;
  std::cout << "OS         : " << d->getOsName() << std::endl;
  std::cout << "Kernel     : " << d->getKernelName() << std::endl;
  std::cout << "user       : " << c->getUserName() << std::endl;
  std::cout << "date       : " << b->getDate() << std::endl;
  std::cout << "hour       : " << b->getHour() << std::endl;
  std::cout << "total ram  : " << a->getTotalRam() << std::endl;
  std::cout << "free ram   : " << a->getFreeRam() << std::endl;
  std::cout << "used ram   : " << a->getUsedRam() << std::endl;
  std::cout << "total swap : " << a->getTotalSwap() << std::endl;
  std::cout << "free swap  : " << a->getFreeSwap() << std::endl;
  std::cout << "used swap  : " << a->getUsedSwap() << std::endl;
  std::cout << GKrellM::execBashCommand("clear;");
  }
  return (0);
}
