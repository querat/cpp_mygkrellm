//
// myPanel.hh for rush3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 22:07:09 2016 Killian Corbel
// Last update Sun Jan 24 06:55:57 2016 Killian Corbel
//

#ifndef MYPANEL_HH_
#define MYPANEL_HH_

#include <iostream>
#include <panel.h>
#include <cmath>
#include "IMonitorModule.hh"
#include "RamModule.hh"
#include "CpuModule.hh"
#include "OSKernelModule.hh"
#include "MachineUserNameModule.hh"
#include "DateTimeModule.hh"

class	myPanel
{
public:
  myPanel(PANEL*, int, int, int);
  ~myPanel() {}

public:
  int	getX() const;
  int	getY() const;
  PANEL*	getPanel() const;
  IMonitorModule*	getData() const;
  void	setData(IMonitorModule*);
  void	printData();
  myPanel*	getNext() const;
  void	setNext(myPanel*);

private:
  PANEL*		_panel;
  int			_x;
  int			_y;
  myPanel*		_next;
  int			_col;
  int			_row;
  IMonitorModule*	data;
  int			_n;
};


#endif
