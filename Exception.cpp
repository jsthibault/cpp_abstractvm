//
// Exception.cpp for Exeption.cpp in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Sun Feb 23 18:05:49 2014 thibau_j
// Last update Thu Feb 27 12:15:20 2014 thibau_j
//

#include <iostream>

#include			<sstream>
#include			"Exception.hh"

Exception::Exception(std::string const &msg, int const &line) throw() : _msg(msg), _line(line), _inst("")
{
}

Exception::Exception(std::string const &msg, std::string const &inst) throw() : _msg(msg),  _line(-2), _inst(inst)
{
}

Exception::Exception(std::string const &msg) throw() : _msg(msg),  _line(-1), _inst("")
{
}

Exception::~Exception() throw()
{
}

const char			*Exception::what() const throw()
{
  std::ostringstream			oss;

  if (this->_line == -1)
    oss << this->_msg;
  else if (this->_line == -2)
    oss << this->_inst << this->_msg;
  else
    oss << this->_msg << " at line " << this->_line;
  return (oss.str().c_str());
}
