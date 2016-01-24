/*
** Enum.h for  in /home/querat_g/tmp/cpp_gkrellm/src
** 
** Made by querat_g
** Login   <querat_g@epitech.net>
** 
** Started on  Sat Jan 23 17:59:51 2016 querat_g
** Last update Sun Jan 24 02:43:09 2016 querat_g
*/

#ifndef ENUM_H_
# define ENUM_H_

#include <string>

#define BUF_SIZE		2048
#define CPU_READ_TICK_LENGTH	100000

namespace GKrellM
{
  std::string execBashCommand(std::string const &cmd);
  
  enum		ModuleType {
    MODULE_UNKNOWN	= 0
    , MODULE_CPU	= 1
    , MODULE_OSKERNEL	= 2
    , MODULE_USERNAME	= 3
    , MODULE_DATETIME	= 4
    , MODULE_RAM	= 5
  };

  enum		Library {
    LIB_UNKNOWN
    , LIB_QT
    , LIB_NCURSES
  };
}

#endif
