//
// NCurses.cpp for rush3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 17:09:33 2016 Killian Corbel
// Last update Sun Jan 24 04:15:47 2016 Killian Corbel
//

#include <array>
#include <string>
#include "myPanel.hh"

std::array<WINDOW*, 5>	init_windows(std::array<WINDOW*, 5> &array, int row, int col);

int	main()
{
  std::array<WINDOW*, 5>	windows;
  std::array<myPanel*, 5>	panels;
  myPanel*			current;
  int	row, col, ch;
  bool	_move = false, _resize = false;

  initscr();
  getmaxyx(stdscr, row, col);
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  init_pair(1, COLOR_RED, COLOR_BLACK); // ram
  init_pair(2, COLOR_BLUE, COLOR_BLACK); // CPU
  init_pair(3, COLOR_GREEN, COLOR_BLACK); // OSKernel
  init_pair(4, COLOR_CYAN, COLOR_BLACK); // Machine User Name
  init_pair(5, COLOR_WHITE, COLOR_BLACK); // Date Time

  windows = init_windows(windows, row, col);
  
  for (int i = 0; i < 5; i++)
    panels[i] = new myPanel(new_panel(windows[i]), (i * col / 2) % col, (i * row / 3) % row);

  for (int i = 0; i < 5; i++)
    panels[i]->setNext(panels[(i + 1) % 5]);

  update_panels();
  doupdate();

  current = panels[4];
  while ((ch = getch()) != KEY_F(2))
    {
      switch(ch)
	{
	case	9:
	  current = current->getNext();
	  top_panel(current->getPanel());
	  break;
	case 'm':
	  _move = true;
	  break;
	case 'r':
	  _resize = true;
	  break;
	case KEY_LEFT:
	  if (_move == true)
	    current->move(current->getX() - 1, current->getY());
	  break;
	case KEY_RIGHT:
	  if (_move == true)
	    current->move(current->getX() + 1, current->getY());
	  break;
	case KEY_UP:
	  if (_move == true)
	    current->move(current->getX(), current->getY() - 1);
	  break;
	case KEY_DOWN:
	  if (_move == true)
	    current->move(current->getX(), current->getY() + 1);
	  break;
	case 10:
	  _move = false;
	  break;
	case ' ':
	  if (current->isHidden())
	    current->show();
	  else
	    current->hide();
	}
      refresh();
      update_panels();
      doupdate();
    }

  for (int i = 0; i < 5; i++)
    delete panels[i];
  endwin();
  return (0);
}

std::array<WINDOW*, 5>	init_windows(std::array<WINDOW*, 5> &array, int row, int col)
{
  for (int i = 0; i < 5; i++)
    {
      array[i] = newwin(row / 3, col / 2, (i * row / 3) % row, (i * col / 2) % col);
      box(array[i], 0, 0);
      mvwaddch(array[i], 2, 0, ACS_LTEE);
      mvwhline(array[i], 2, 1, ACS_HLINE, (col / 2) - 2);
      mvwaddch(array[i], 2, (col / 2) - 1, ACS_RTEE);
      wattron(array[i], COLOR_PAIR(i));
    }

  mvwprintw(array[0], 1, ((col / 2) - 3) / 2, "Ram");
  mvwprintw(array[1], 1, ((col / 2) - 3) / 2, "CPU");
  mvwprintw(array[2], 1, ((col / 2) - 8) / 2, "OSKernel");
  mvwprintw(array[3], 1, ((col / 2) - 15) / 2, "MachineUserName");
  mvwprintw(array[4], 1, ((col / 2) - 8) / 2, "DateTime");

  for (int i = 0; i < 5; i++)
    wattroff(array[i], COLOR_PAIR(i + 1));

  refresh();

  return (array);
}
