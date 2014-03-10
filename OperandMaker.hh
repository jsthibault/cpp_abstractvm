//
// OperandMaker.hh for OperandMaker in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Mon Feb 24 15:38:38 2014 thibau_j
// Last update Sat Mar  1 16:04:19 2014 thibau_j
//

#ifndef OPERANDMAKER_HH_
# define OPERANDMAKER_HH_

# include <string>
# include <list>
# include "IOperand.hpp"

class			OperandMaker
{
private:

  typedef IOperand		*(OperandMaker::*funcTab)(const std::string &fct);

  std::list<IOperand *>		_operatorStack;
  funcTab			_funcTab[5];
  IOperand			*createInt8(const std::string &value);
  IOperand			*createInt16(const std::string &value);
  IOperand			*createInt32(const std::string &value);
  IOperand			*createFloat(const std::string &value);
  IOperand			*createDouble(const std::string &value);

public:
  OperandMaker();
  ~OperandMaker() {}

  IOperand			*createOperand(eOperandType type, const std::string &value);

  IOperand			*next();
  double			operandValue(IOperand const *tmp);

  void				push(IOperand *rhs);
  void				pop();
  void				dump();
  void				assert(IOperand *rhs);
  void				add();
  void				sub();
  void				mul();
  void				div();
  void				mod();
  void				print();
};

#endif				/* !OPERANDMAKER_HH_ */
