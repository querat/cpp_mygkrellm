//
// GKrellM.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 21:34:29 2016 querat_g
// Last update Sat Jan 23 21:37:02 2016 querat_g
//

#include <cstdio>
#include <unistd.h>
#include "GKrellM.h"

std::string	
GKrellM::execBashCommand(std::string const &cmd)
{
  FILE		*f;
  char		buf[BUF_SIZE];
  
  f = popen(cmd.c_str(), "r");
  if (!f)
    return ("");  
  buf[fread(buf, sizeof(char), BUF_SIZE, f)] = 0;
  fclose(f);

  return (std::string(buf));
}

