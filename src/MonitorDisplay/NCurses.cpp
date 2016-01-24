//
// NCurses.cpp for rush3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 17:09:33 2016 Killian Corbel
// Last update Sun Jan 24 07:16:47 2016 Killian Corbel
//

#include <unistd.h>
#include "NCurses.hh"
#include "myPanel.hh"

void	NCurses::display_ncurses(std::map<std::string, IMonitorModule*> const &map)
{
  int	_n = map.size();
  std::vector<WINDOW*>	windows;
  std::vector<myPanel*>	panels;
  int	row, col;

  initscr();
  curs_set(0);
  getmaxyx(stdscr, row, col);
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);

  windows = this->init_windows(windows, row, col, _n);
  
  for (int i = 0; i < _n; i++)
    panels.push_back(new myPanel(new_panel(windows[i]), (i * col / static_cast<int>(sqrt(_n - 1) + 1)) % col, (i * row / static_cast<int>(round(sqrt(_n)))) % row, _n));

  for (int i = 0; i < _n; i++)
    panels[i]->setNext(panels[(i + 1) % _n]);

  int	j = 0;
  for (std::map<std::string, IMonitorModule*>::const_iterator it = map.begin(); it != map.end(); ++it)
    {
      panels[j]->setData(it->second);
      j++;
    }

  update_panels();
  doupdate();

  while (42)
    {
      for (int i = 0; i < _n; i++)
	{
	  panels[i]->getData()->loadData();
	  panels[i]->printData();
	}
      usleep(1000000);
    }

  for (int i = 0; i < _n; i++)
    delete panels[i];
  endwin();
}

std::vector<WINDOW*>	NCurses::init_windows(std::vector<WINDOW*> &array, int row, int col, int _n)
{
  int	nb_x;
  int	nb_y;
  for (int i = 0; i < _n; i++)
    {
      nb_x = static_cast<int>(sqrt(_n - 1) + 1);
      nb_y = static_cast<int>(round(sqrt(_n)));
      array.push_back(newwin(row / nb_y, col / nb_x, (i / nb_x) * (row / nb_y), (i % nb_x) * (col / nb_x)));
      box(array[i], 0, 0);
      mvwaddch(array[i], 2, 0, ACS_LTEE);
      mvwhline(array[i], 2, 1, ACS_HLINE, (col / static_cast<int>(sqrt(_n - 1) + 1)) - 2);
      mvwaddch(array[i], 2, (col / static_cast<int>(sqrt(_n - 1) + 1)) - 1, ACS_RTEE);
    }

  for (int i = 0; i < _n; i++)
    wattroff(array[i], COLOR_PAIR((i + 1) % (_n + 1)));

  refresh();

  return (array);
}

NCurses::NCurses(std::map<std::string, IMonitorModule*> const &map) : _map(map)
{
}

NCurses::~NCurses() {}
