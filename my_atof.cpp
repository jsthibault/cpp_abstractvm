//
// my_atof.cpp for my_atof in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Mon Feb 24 01:44:05 2014 thibau_j
// Last update Thu Feb 27 12:15:41 2014 thibau_j
//

#include <sstream>

double			my_atof(std::string str)
{
  std::stringstream	stream;
  double       		res;

  stream << str;
  stream >> res;
  return (res);
}
