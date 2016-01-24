//
// NCurses.hh for rush3/3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 16:42:10 2016 Killian Corbel
// Last update Sun Jan 24 00:58:07 2016 Killian Corbel
//

#ifndef	NCURSES_HH_
#define NCURSES_HH_

#include <map>
#include <string>
#include <array>
#include "panel.h"
#include "IMonitorDisplay.hh"
#include "IMonitorModule.hh"

class	NCurses : public IMonitorDisplay
{
public:
  NCurses(std::map<std::string, IMonitorModule*> &_map);
  ~NCurses();

public:
  void	display_ncurses(std::map<std::string, IMonitorModule*> map);

private:
  std::map<std::string, IMonitorModule*>* _map;

private:
  std::array<WINDOW*, 5>	init_windows(std::array<WINDOW*, 5> &array, int row, int col);
};

#endif
