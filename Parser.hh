//
// Parser.hh for Parser.hh in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Tue Feb 25 16:30:30 2014 thibau_j
// Last update Sun Mar  2 22:53:47 2014 thibau_j
//

#ifndef PARSER_HH_
# define PARSER_HH_

# include "IOperand.hpp"
# include "OperandMaker.hh"
# include <iostream>
# include <vector>
# include <string>
# include <list>
# include <map>

typedef struct		s_valueGrammar
{
  std::string		inst;
  std::string		value;
  eOperandType		type;
}			t_valueGrammar;

typedef struct		s_instGrammar
{
  std::string		inst;
  bool			value;
  t_valueGrammar	*ptr;
}			t_instGrammar;

static t_instGrammar		Instruction[] =
  {
    {"push", true, NULL},
    {"pop", false, NULL},
    {"dump", false, NULL},
    {"assert", true, NULL},
    {"add", false, NULL},
    {"sub", false, NULL},
    {"mul", false, NULL},
    {"div", false, NULL},
    {"mod", false, NULL},
    {"print", false, NULL},
  };

static t_valueGrammar		Value[] =
  {
    {"int8", "", INT8},
    {"int16", "", INT16},
    {"int32", "", INT32},
    {"float", "", FLOAT},
    {"double", "", DOUBLE},
  };


class					Parser
{
private:
  typedef void				(OperandMaker::*funcTab)();

  std::vector<std::string>		_tab;
  std::list<t_instGrammar>		_list;
  std::map<std::string, funcTab>	_funcTab;

  void					setString(std::string str);
  void					setTab(char const *av);
  void					setList();

  std::string				noSpace(std::string const &str);
  int					cmpStruc(std::string tmp, t_instGrammar Instruction[]);
  int					cmpStruc(std::string tmp, t_valueGrammar Value[]);
  void					executeList();

public:
  Parser(char const *av);
  ~Parser();

};

#endif					/* !PARSER_HH_ */
