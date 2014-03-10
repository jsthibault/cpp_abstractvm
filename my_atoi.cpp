//
// my_atoi.cpp for my_atoi.cpp in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Mon Feb 24 01:42:20 2014 thibau_j
// Last update Thu Feb 27 12:15:36 2014 thibau_j
//

#include <sstream>

int			my_atoi(std::string str)
{
  std::stringstream	stream;
  int			res;

  stream << str;
  stream >> res;
  return (res);
}
