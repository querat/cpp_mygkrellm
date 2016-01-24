//
// main.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Fri Jan 22 22:20:31 2016 querat_g
// Last update Sun Jan 24 05:56:12 2016 Adrien Schmouker
//

#include <iostream>
#include <string>
#include "DateTimeModule.hh"
#include "GKrellM.h"
#include "MachineUserNameModule.hh"
#include "RamModule.hh"
#include "CpuModule.hh"
#include "OSKernelModule.hh"
#include "NCurses.hh"

static void	dispUsage()
{
  std::cerr 
    << "Usage : ./mygkrellm [ -ncurses | -graph ]"
    " [-cpu [-ram [-time [-user [-OS]]]]])" 
    << std::endl;
}

int	main(int ac, char **argv)
{
  MonitorCore		core;
  std::string	        libCheck;

  if (!argv || ac < 2) {
    dispUsage();
    return (0);
  }

  core.coreInit(ac, argv, core);

  NCurses	ncurses(core.getModules());

  libCheck.assign(argv[1]);
  if (libCheck == "-ncurses" && (!core.getModules().empty()))
    ncurses.display_ncurses(core.getModules());
  else if (libCheck == "-graph")
    std::cerr << "Not available yet." << std::endl;
  else
    dispUsage();
  return (0);
}
