//
// OperandMaker.cpp for Operandmaker.cpp in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Mon Feb 24 15:51:56 2014 thibau_j
// Last update Sat Mar  1 16:13:44 2014 thibau_j
//

#include <iostream>
#include "OperandMaker.hh"
#include "Operand.hpp"

OperandMaker::OperandMaker()
{
  this->_funcTab[0] = &OperandMaker::createInt8;
  this->_funcTab[1] = &OperandMaker::createInt16;
  this->_funcTab[2] = &OperandMaker::createInt32;
  this->_funcTab[3] = &OperandMaker::createFloat;
  this->_funcTab[4] = &OperandMaker::createDouble;
}

IOperand		*OperandMaker::createInt8(const std::string &value)
{
  IOperand		*res;

  res = new Operand<char>(INT8, my_atof(value));
  return (res);
}

IOperand		*OperandMaker::createInt16(const std::string &value)
{
  IOperand		*res = new Operand<short>(INT16, my_atof(value));;

  return (res);
}

IOperand		*OperandMaker::createInt32(const std::string &value)
{
  IOperand		*res = new Operand<int>(INT32, my_atof(value));;

  return (res);
}

IOperand		*OperandMaker::createFloat(const std::string &value)
{
  IOperand		*res = new Operand<float>(FLOAT, my_atof(value));;

  return (res);
}

IOperand		*OperandMaker::createDouble(const std::string &value)
{
  IOperand		*res = new Operand<double>(DOUBLE, my_atof(value));;

  return (res);
}

IOperand                *OperandMaker::createOperand(eOperandType type, const std::string &value)
{
  IOperand		*res = (this->*_funcTab[type])(value);

  return (res);
}

IOperand		*OperandMaker::next()
{
  if (this->_operatorStack.size() <= 0)
    return (NULL);
  return (this->_operatorStack.front());
}

double			OperandMaker::operandValue(IOperand const *tmp)
{
  return (my_atof(tmp->toString()));
}

void			OperandMaker::push(IOperand *rhs)
{
  this->_operatorStack.push_front(rhs);
}

void			OperandMaker::pop()
{
  if (this->_operatorStack.size() <= 0)
    throw Exception("Pop on empty stack Kreooooooooog !");
  this->_operatorStack.pop_front();
}

void			OperandMaker::dump()
{
  double		tmp;

  if (this->_operatorStack.size() <= 0)
    throw Exception("Dump on empty stack Kreooooooooog !");
  for(std::list<IOperand *>::iterator listIter = this->_operatorStack.begin(); listIter != this->_operatorStack.end(); listIter++)
    {
      tmp = my_atof((*listIter)->toString());
      std::cout << tmp << std::endl;
    }
}

void			OperandMaker::assert(IOperand *rhs)
{
  IOperand		*tmp = this->_operatorStack.front();

  if (this->_operatorStack.size() <= 0)
    throw Exception("Assert on empty stack Kreoooooooog !");
  if (this->operandValue(tmp) != this->operandValue(rhs))
    {
      throw Exception ("Assert comparaison failed, different value here. Kreoooooooooog !");
    }
}

void			OperandMaker::add()
{
  IOperand		*tmp1;
  IOperand		*tmp2;
  IOperand		*res;

  if (this->_operatorStack.size() < 2)
    throw Exception("Stack is inferior at 2 Kreooooooooog !");
  tmp1 = next();
  pop();
  tmp2 = next();
  pop();
  res = *tmp2 + *tmp1;
  push(res);
}

void			OperandMaker::sub()
{
  IOperand		*tmp1;
  IOperand		*tmp2;
  IOperand		*res;

  if (this->_operatorStack.size() < 2)
    throw Exception("Stack is inferior at 2 Kreooooooooog !");
  tmp1 = next();
  pop();
  tmp2 = next();
  pop();
  res = *tmp2 - *tmp1;
  push(res);
}

void			OperandMaker::mul()
{
  IOperand		*tmp1;
  IOperand		*tmp2;
  IOperand		*res;

  if (this->_operatorStack.size() < 2)
    throw Exception("Stack is inferior at 2 Kreooooooooog !");
  tmp1 = next();
  pop();
  tmp2 = next();
  pop();
  res = *tmp2 * *tmp1;
  push(res);
}

void			OperandMaker::div()
{
  IOperand		*tmp1;
  IOperand		*tmp2;
  IOperand		*res;

  if (this->_operatorStack.size() < 2)
    throw Exception("Stack is inferior at 2 Kreooooooooog !");
  tmp1 = next();
  pop();
  tmp2 = next();
  pop();
  res = *tmp2 / *tmp1;
  push(res);
}

void			OperandMaker::mod()
{
  IOperand		*tmp1;
  IOperand		*tmp2;
  IOperand		*res;

  if (this->_operatorStack.size() < 2)
    throw Exception("Stack is inferior at 2 Kreooooooooog !");
  tmp1 = next();
  pop();
  tmp2 = next();
  pop();
  res = *tmp2 % *tmp1;
  push(res);
}

void			OperandMaker::print()
{
  IOperand		*tmp1 = next();

  if (tmp1->getType() != INT8)
    throw Exception ("TRY TO PRINT A NON CHAR VALUE ... SERIOUSLY ? PUT ME A TWENTY PLS <3");
  std::cout << (char)my_atoi(tmp1->toString()) << std::endl;
}
