//
// myPanel.cpp for rush3 in /home/corbel_k/Downloads/ncurses_programs/panels
// 
// Made by Killian Corbel
// Login   <corbel_k@epitech.net>
// 
// Started on  Sat Jan 23 22:12:02 2016 Killian Corbel
// Last update Sun Jan 24 07:22:04 2016 Killian Corbel
//

#include "myPanel.hh"

myPanel::myPanel(PANEL* panel, int x, int y, int n) : _panel(panel), _x(x), _y(y), _next(NULL)
{
  getmaxyx(stdscr, this->_row, this->_col);
  this->data = NULL;
  this->_n = n;
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


myPanel*	myPanel::getNext() const
{
  return (this->_next);
}

void	myPanel::setNext(myPanel* next)
{
  this->_next = next;
}

IMonitorModule*	myPanel::getData() const
{
  return (this->data);
}

void	myPanel::setData(IMonitorModule* newData)
{
  this->data = newData;
}

void	myPanel::printData()
{
  if (this->getData()->getType() == GKrellM::MODULE_RAM)
    {
      int	used_ram = std::stoi(dynamic_cast<RamModule*>(this->getData())->getUsedRam());
      int	total_ram = std::stoi(dynamic_cast<RamModule*>(this->getData())->getTotalRam());
      int	percent = static_cast<int>(static_cast<float>(used_ram) / static_cast<float>(total_ram) * 100);
      std::string	pipes("");

      wattron(panel_window(this->_panel), COLOR_PAIR(1));
      mvwprintw(panel_window(this->_panel), 1, (_col / static_cast<int>(sqrt(_n - 1) + 1) - 3) / 2, "Ram");
      wattroff(panel_window(this->_panel), COLOR_PAIR(1));
  
      
      mvwprintw(panel_window(this->_panel), 4, 2, "Used Ram : %s", dynamic_cast<RamModule*>(this->getData())->getUsedRam().c_str());
      mvwprintw(panel_window(this->_panel), 5, 2, "Free Ram : %s", dynamic_cast<RamModule*>(this->getData())->getFreeRam().c_str());
      mvwprintw(panel_window(this->_panel), 6, 2, "Total Ram : %s", dynamic_cast<RamModule*>(this->getData())->getTotalRam().c_str());
      for (int i = 0; i < percent / 10; i++)
	pipes += "|";
      mvwprintw(panel_window(this->_panel), 8, 3, "%d%%", percent);
      mvwprintw(panel_window(this->_panel), 9, 5, "%s", pipes.c_str());
      mvwprintw(panel_window(this->_panel), 9, 2, "0%:");
      mvwprintw(panel_window(this->_panel), 9, 15, ":100%%");


      wrefresh(panel_window(this->_panel));
    }
  else if (this->getData()->getType() == GKrellM::MODULE_CPU)
    {
      wattron(panel_window(this->_panel), COLOR_PAIR(2));
      mvwprintw(panel_window(this->_panel), 1, (_col / static_cast<int>(sqrt(_n - 1) + 1) - 3) / 2, "CPU");
      wattroff(panel_window(this->_panel), COLOR_PAIR(2));

      mvwprintw(panel_window(this->_panel), 4, 2, "Name : %s", dynamic_cast<CpuModule*>(this->getData())->getCpuName().c_str());
      mvwprintw(panel_window(this->_panel), 5, 2, "Architecture : %s", dynamic_cast<CpuModule*>(this->getData())->getCpuArch().c_str());
      mvwprintw(panel_window(this->_panel), 6, 2, "Usage : %s", dynamic_cast<CpuModule*>(this->getData())->getCpuUsage().c_str());
      wrefresh(panel_window(this->_panel));
    }
  else if (this->getData()->getType() == GKrellM::MODULE_OSKERNEL)
    {
      wattron(panel_window(this->_panel), COLOR_PAIR(3));
      mvwprintw(panel_window(this->_panel), 1, (_col / static_cast<int>(sqrt(_n - 1) + 1) - 9) / 2, "OS Kernel");
      wattroff(panel_window(this->_panel), COLOR_PAIR(3));

      mvwprintw(panel_window(this->_panel), 4, 2, "OS : %s", dynamic_cast<OSKernelModule*>(this->getData())->getOsName().c_str());
      mvwprintw(panel_window(this->_panel), 5, 2, "Kernel : %s", dynamic_cast<OSKernelModule*>(this->getData())->getKernelName().c_str());
      wrefresh(panel_window(this->_panel));
    }
  else if (this->getData()->getType() == GKrellM::MODULE_USERNAME)
    {
      wattron(panel_window(this->_panel), COLOR_PAIR(4));
      mvwprintw(panel_window(this->_panel), 1, ((_col / static_cast<int>(sqrt(_n - 1) + 1)) - 18) / 2, "Machine - Username");
      wattroff(panel_window(this->_panel), COLOR_PAIR(4));

      mvwprintw(panel_window(this->_panel), 4, 2, "Machine : %s", dynamic_cast<MachineUserNameModule*>(this->getData())->getMachineName().c_str());
      mvwprintw(panel_window(this->_panel), 5, 2, "User : %s", dynamic_cast<MachineUserNameModule*>(this->getData())->getUserName().c_str());
      wrefresh(panel_window(this->_panel));
    }
  else if (this->getData()->getType() == GKrellM::MODULE_DATETIME)
    {
      wattron(panel_window(this->_panel), COLOR_PAIR(5));
      mvwprintw(panel_window(this->_panel), 1, (_col / static_cast<int>(sqrt(_n - 1) + 1) - 11) / 2, "Date - Time");
      wattroff(panel_window(this->_panel), COLOR_PAIR(5));

      mvwprintw(panel_window(this->_panel), 4, 2, "Date : %s", dynamic_cast<DateTimeModule*>(this->getData())->getDate().c_str());
      mvwprintw(panel_window(this->_panel), 5, 2, "Hour : %s", dynamic_cast<DateTimeModule*>(this->getData())->getHour().c_str());
      wrefresh(panel_window(this->_panel));
    }
}
