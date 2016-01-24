//
// myPanel.hh for rush3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 22:07:09 2016 Killian Corbel
// Last update Sun Jan 24 04:14:46 2016 Killian Corbel
//

#ifndef MYPANEL_HH_
#define MYPANEL_HH_

#include <iostream>
#include <panel.h>

class	myPanel
{
public:
  myPanel(PANEL*, int, int);
  ~myPanel() {}

public:
  int	getX() const;
  int	getY() const;
  PANEL*	getPanel() const;
  void	move(int x, int y);
  myPanel*	getNext() const;
  void	setNext(myPanel*);
  void	hide() const;
  void	show() const;
  bool	isHidden() const;

private:
  PANEL*		_panel;
  int			_x;
  int			_y;
  myPanel*		_next;
  int			_col;
  int			_row;
};


#endif
