//
// NCurses.hh for rush3/3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 16:42:10 2016 Killian Corbel
// Last update Sun Jan 24 04:42:07 2016 Killian Corbel
//

#ifndef	NCURSES_HH_
#define NCURSES_HH_

#include <map>
#include <string>
#include <vector>
#include <cmath>
#include "panel.h"
#include "IMonitorDisplay.hh"
#include "IMonitorModule.hh"

class	NCurses : public IMonitorDisplay
{
public:
  NCurses(std::map<std::string, IMonitorModule*> const &_map);
  ~NCurses();

public:
  void	display_ncurses(std::map<std::string, IMonitorModule*> const &map);

private:
  std::map<std::string, IMonitorModule*> const &_map;

private:
  std::vector<WINDOW*>	init_windows(std::vector<WINDOW*> &array, int row, int col, int _n);
};

#endif
