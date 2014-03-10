//
// Parser.cpp for Parser.cpp in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Tue Feb 25 18:48:54 2014 thibau_j
// Last update Wed Mar  5 16:41:54 2014 thibau_j
//

#include <iomanip>
#include <fstream>
#include <sstream>
#include "Parser.hh"
#include "OperandMaker.hh"
#include "IOperand.hpp"
#include "Exception.hh"

Parser::Parser(char const *av)
{
  this->_funcTab["pop"] = &OperandMaker::pop;
  this->_funcTab["dump"] =  &OperandMaker::dump;
  this->_funcTab["add"] =  &OperandMaker::add;
  this->_funcTab["sub"] =  &OperandMaker::sub;
  this->_funcTab["mul"] =  &OperandMaker::mul;
  this->_funcTab["div"] =  &OperandMaker::div;
  this->_funcTab["mod"] =  &OperandMaker::mod;
  this->_funcTab["print"] =  &OperandMaker::print;
  setTab(av);
  setList();
  executeList();
}

Parser::~Parser()
{
}

int					Parser::cmpStruc(std::string tmp, t_valueGrammar Value[])
{
  int					i = 0;
  int					j = 0;

  j = tmp.find("(");
  if (j == -1)
    throw Exception(" has no value.", tmp);
  tmp = tmp.substr(0, j);
  while (i <= 4)
    {
      if (tmp == Value[i].inst)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (-1);
}

int					Parser::cmpStruc(std::string tmp, t_instGrammar Instruction[])
{
  int					i = 0;

  while (i <= 9)
    {
      if (tmp == Instruction[i].inst)
  	return (i);
      i = i + 1;
    }
  return (-1);
}

void					Parser::setList()
{
  std::vector<std::string>::iterator	tmp;
  bool					val = false;
  int					k = 0;
  int					p = 0;
  int					j;
  int					i;
  std::string				value;
  t_instGrammar				ptr;
  t_valueGrammar			*ptr2;

  for (tmp = this->_tab.begin(); tmp != this->_tab.end(); ++tmp)
    {
      i = -1;
      j = -1;
      if (val == false && (j = this->cmpStruc(*tmp, Instruction)) == -1)
  	throw Exception(" does not exist.", *tmp);
      else if (val == false)
  	ptr = Instruction[j];
      if (val == true && (i = this->cmpStruc(*tmp, Value)) == -1)
      	throw Exception("Does not an eOperandType.");
      else if (val == true)
  	{
  	  ptr2 = new t_valueGrammar;
  	  k = (*tmp).find('(');
  	  if ((p = (*tmp).find(')')) == -1)
  	    throw Exception ("Didn't close a (");
  	  ptr2->inst = (*tmp).substr(0, k);
  	  ptr2->value = (*tmp).substr(k + 1, p);
	  p = ptr2->value.find(')');
	  ptr2->value = ptr2->value.substr(0, p);
  	  ptr2->type = Value[i].type;
  	  ptr.ptr = ptr2;
  	}
      if (val == false && (Instruction[j].value == true))
  	{
  	  val = true;
  	}
      else
  	{
  	  this->_list.push_back(ptr);
  	  val = false;
  	}
    }
  if (val == true)
    throw Exception ("Missing an operandType.");
}

void						Parser::executeList()
{
  std::list<t_instGrammar>::iterator		tmp;
  t_instGrammar					ind;
  OperandMaker					make;
  IOperand					*op;

  for (tmp = this->_list.begin(); tmp != this->_list.end(); ++tmp)
    {
      op = NULL;
      ind = (*tmp);
      if (ind.inst == "push")
	{
	  op = make.createOperand(ind.ptr->type, ind.ptr->value);
	  make.push(op);
	}
      else if (ind.inst == "assert")
  	{
	  op = make.createOperand(ind.ptr->type, ind.ptr->value);
	  make.assert(op);
	}
      else
	{
	  ((make).*(this->_funcTab[ind.inst]))();
	}
    }
}

std::string			Parser::noSpace(std::string const &str)
{
  std::istringstream		stream(str);
  std::string			tmp;
  std::string			res;

  if (stream >> tmp)
    {
      res += tmp;
    }
  while (stream >> tmp)
    {
      res += ' ' + tmp;
    }
  return (res);
}

void				Parser::setString(std::string str)
{
  std::string			tmp;
  int				i;

  tmp = str;
  i = str.find(";");
  if (i != -1)
    str = str.substr(0, i - 1);
  i = str.find(" ");
  if (i != -1)
    {
      tmp = str.substr(i + 1);
      tmp = this->noSpace(tmp);
      str = str.substr(0, i);
      str = this->noSpace(str);
      if (str != "")
	this->_tab.push_back(str);
      if (tmp != "")
	this->_tab.push_back(tmp);
    }
  else
    {
      if (tmp != "")
	this->_tab.push_back(str);
    }
}

void				Parser::setTab(char const *av)
{
  std::fstream			file_open(av, std::ios::in);
  std::string			tmp;
  std::string			tmpCom;
  int				i = 0;

  tmp = "-";
  if (!file_open)
    {
      while (tmp != ";;" && tmp.length() != 0)
	{
	  getline(std::cin, tmp);
	  if (tmp != "\n" && tmp != ";;" && tmp != " " && tmp != "exit")
	    {
	      i = tmp.find(";");
	      if (i != -1)
		tmpCom = tmp.substr(0, i);
	      else
		tmpCom = tmp;
	      this->setString(tmpCom);
	    }
	}
    }
  else
    {
      while (!(file_open.eof()) && tmp != "exit")
	{
	  getline(file_open, tmp);
	  if (tmp != "\n" && tmp != ";;" && tmp != " " && tmp != "exit")
	    {
	      i = tmp.find(";");
	      if (i != -1)
		tmpCom = tmp.substr(0, i);
	      else
		tmpCom = tmp;
	      this->setString(tmpCom);
	    }
	}
      if (tmp != "exit")
	throw Exception("Forget to use exit on your file");
    }
}

int		main(int ac, char **av)
{
  try
    {
      if (ac < 2)
      	new Parser(NULL);
      else
      	new Parser(av[1]);
    }
  catch (Exception const &e)
    {
      std::cout << e.what() << std::endl;
    }
  return (0);
}
