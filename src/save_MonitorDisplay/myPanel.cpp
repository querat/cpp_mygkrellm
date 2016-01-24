//
// myPanel.cpp for rush3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 22:12:02 2016 Killian Corbel
// Last update Sun Jan 24 04:19:22 2016 Killian Corbel
//

#include "ncurses.h"
#include "myPanel.hh"

myPanel::myPanel(PANEL* panel, int x, int y) : _panel(panel), _x(x), _y(y), _next(NULL)
{
  getmaxyx(stdscr, this->_row, this->_col);
}

PANEL*	myPanel::getPanel() const
{
  return (this->_panel);
}

int	myPanel::getX() const
{
  return (this->_x);
}

int	myPanel::getY() const
{
  return (this->_y);
}

void	myPanel::move(int x, int y)
{
  if (x >= 0 && x <= this->_col && y >= 0 && y <= this->_row)
    {
      move_panel(this->_panel, y, x);
      this->_x = x;
      this->_y = y;
    }
}

myPanel*	myPanel::getNext() const
{
  return (this->_next);
}

void	myPanel::setNext(myPanel* next)
{
  this->_next = next;
}

void	myPanel::hide() const
{
  hide_panel(this->_panel);
}

void	myPanel::show() const
{
  show_panel(this->_panel);
}

bool	myPanel::isHidden() const
{
  return (panel_hidden(this->_panel));
}
