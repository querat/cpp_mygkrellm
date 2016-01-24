//
// DateTimeModule.hh for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/DateTimeModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 19:11:32 2016 querat_g
// Last update Sat Jan 23 20:54:25 2016 querat_g
//

#ifndef DATETIMEMODULE_HH_
# define DATETIMEMODULE_HH_

#include "MonitorModule.hh"

class DateTimeModule : public MonitorModule
{
public:
  DateTimeModule();
  DateTimeModule(DateTimeModule const &other);
  ~DateTimeModule();
  DateTimeModule& operator=(DateTimeModule const &other);

private:
  std::string	_hour;
  std::string	_date;

public:
  void		loadData();

  std::string const &	getHour() const;
  std::string const &	getDate() const;

};

#endif
