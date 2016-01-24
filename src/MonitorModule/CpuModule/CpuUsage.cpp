//
// CpuUsage.cpp for  in /home/schmou_a/piscine/cpp_gkrellm/src/MonitorModule/CpuModule
// 
// Made by Adrien Schmouker
// Login   <schmou_a@epitech.net>
// 
// Started on  Sat Jan 23 23:29:35 2016 Adrien Schmouker
// Last update Sun Jan 24 01:22:25 2016 querat_g
//

#include <fstream>
#include <unistd.h>
#include "CpuModule.hh"

std::string
CpuModule::calcCpuUsage() const
{
  std::ifstream cpuRead("/proc/stat", std::ios::in);
  std::string	tmp;

  long double fUser, fNice, fSystem, fIdle;
  long double sUser, sNice, sSystem, sIdle;

  double	percentage = 0.0;

  cpuRead >> tmp;
  cpuRead >> fUser;
  cpuRead >> fNice;
  cpuRead >> fSystem;
  cpuRead >> fIdle;

  usleep(CPU_READ_TICK_LENGTH);

  std::ifstream cpuRead2("/proc/stat", std::ios::in);

  cpuRead2 >> tmp;
  cpuRead2 >> sUser;
  cpuRead2 >> sNice;
  cpuRead2 >> sSystem;
  cpuRead2 >> sIdle;

  if ((sUser + sNice + sSystem + sIdle) - (fUser + fNice + fSystem + fIdle) != 0.0)
    percentage = ((sUser + sNice + sSystem) - (fUser + fNice + fSystem)) / ((sUser + sNice + sSystem + sIdle) - (fUser + fNice + fSystem + fIdle));

  percentage *= 100.0;

  return std::to_string(percentage);
}
