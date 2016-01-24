//
// DateTimeModule.cpp for  in /home/querat_g/tmp/cpp_gkrellm/src/MonitorModule/DateTimeModule
// 
// Made by querat_g
// Login   <querat_g@epitech.net>
// 
// Started on  Sat Jan 23 19:11:23 2016 querat_g
// Last update Sun Jan 24 00:07:57 2016 querat_g
//

#include "DateTimeModule.hh"

// Coplien form
DateTimeModule::DateTimeModule()
  : _hour("")
  , _date("")
{
  _type = GKrellM::MODULE_DATETIME;
}
DateTimeModule::~DateTimeModule() {}

DateTimeModule::DateTimeModule(DateTimeModule const &other) 
  : MonitorModule()
  , _hour(other.getHour())
  , _date(other.getDate())
{
  _type = GKrellM::MODULE_DATETIME;
}

DateTimeModule&
DateTimeModule::operator=(DateTimeModule const &other) {
  _hour = other.getHour();
  _date = other.getDate();
  return (*this);
}

// Member function
void
DateTimeModule::loadData() {
  _hour = GKrellM::execBashCommand("date -R | cut -d\\  -f5     | head -c -1");
  _date = GKrellM::execBashCommand("date | cut -d\\  -f1,2,3 | head -c -1");
}

// Getters
std::string const &
DateTimeModule::getHour() const {
  return (_hour);
}
std::string const &
DateTimeModule::getDate() const {
  return (_date);
}
