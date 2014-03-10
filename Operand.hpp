// Operand.hh for Operand in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Thu Feb 20 14:24:05 2014 thibau_j
// Last update Sun Mar  2 22:53:01 2014 thibau_j
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

# include <sstream>
# include <climits>

# include "function.hh"
# include "Exception.hh"

typedef struct		s_check
{
  eOperandType		type;
  int			rank;
  long			min;
  long		 	max;
}			t_check;

static t_check			check[] =
  {
    {INT8, 0, SCHAR_MIN, SCHAR_MAX},
    {INT16, 1, SHRT_MIN, SHRT_MAX},
    {INT32, 2, INT_MIN, INT_MAX},
    {FLOAT, 3, -32768, 32767},
    {DOUBLE, 4, -2147483648, 2147483647}
  };

template <typename T>
class				Operand : public IOperand
{
private:

  eOperandType			_type;
  int				_precision;
  T				_value;

public:
  Operand(eOperandType type, const T &value)
  {
    this->_type = type;
    if (value > check[type].min)
      {
	if (value < check[type].max)
	  this->_precision = check[type].rank;
	else
	  throw Exception("Overflow detected Kreooooog !");
      }
    else
      {
	throw Exception("Underflow detected Kreooooog !");
      }
    this->_value = value;
    }
  ~Operand()
  {
  };
  Operand(Operand const &Operand);
  const Operand			&operator=(Operand const &Picture);

  virtual T			getValue()
  {
    return (this->_value);
  }
  virtual eOperandType		getType() const
  {
    return (this->_type);
  }
  virtual int			getPrecision() const
  {
    return (this->_precision);
  }
  virtual std::string const	&toString() const
  {
    std::string			*str = new std::string();
    std::ostringstream		res;

    if (this->getType() == INT8)
      res << (int)this->_value;
    else
      res << this->_value;
    str->append(res.str());
    return (*str);
  }

  virtual IOperand		*operator+(const IOperand &rhs) const
  {
    IOperand			*res;
    eOperandType		type;
    double			value = this->_value + my_atof(rhs.toString());

    if (this->_precision >= rhs.getPrecision())
      type = this->_type;
    else
      type = rhs.getType();
    switch (type)
      {
      case INT8 :
	{
	  res = new Operand<char>(type, value);
	  break;
	}
      case INT16 :
	{
	  res = new Operand<short>(type, value);
	  break;
	}
      case INT32 :
	{
	  res = new Operand<int>(type, value);
	  break;
	}
      case FLOAT :
	{
	  res = new Operand<float>(type, value);
	  break;
	}
      case DOUBLE :
	{
	  res = new Operand<double>(type, value);
	  break;
	}
      }
    return (res);
  }
  virtual IOperand		*operator-(const IOperand &rhs) const
  {
    IOperand			*res;
    eOperandType		type;
    double			value = this->_value  - my_atof(rhs.toString());

    if (this->_precision >= rhs.getPrecision())
      type = this->_type;
    else
      type = rhs.getType();
    switch (type)
      {
      case INT8 :
	{
	  res = new Operand<char>(type, value);
	  break;
	}
      case INT16 :
	{
	  res = new Operand<short>(type, value);
	  break;
	}
      case INT32 :
	{
	  res = new Operand<int>(type, value);
	  break;
	}
      case FLOAT :
	{
	  res = new Operand<float>(type, value);
	  break;
	}
      case DOUBLE :
	{
	  res = new Operand<double>(type, value);
	  break;
	}
      }
    return (res);
  }
  virtual IOperand		*operator*(const IOperand &rhs) const
  {
    IOperand			*res;
    eOperandType		type;
    double			value = this->_value * my_atof(rhs.toString());

    if (this->_precision >= rhs.getPrecision())
      type = this->_type;
    else
      type = rhs.getType();
    switch (type)
      {
      case INT8 :
	{
	  res = new Operand<char>(type, value);
	  break;
	}
      case INT16 :
	{
	  res = new Operand<short>(type, value);
	  break;
	}
      case INT32 :
	{
	  res = new Operand<int>(type, value);
	  break;
	}
      case FLOAT :
	{
	  res = new Operand<float>(type, value);
	  break;
	}
      case DOUBLE :
	{
	  res = new Operand<double>(type, value);
	  break;
	}
      }
    return (res);
  }
  virtual IOperand		*operator/(const IOperand &rhs) const
  {
    IOperand			*res;
    eOperandType		type;
    double			value;

    if (my_atof(rhs.toString()) == 0)
      throw Exception("Division by zero bro, \"Are u madding brooo ?! Kreooooog\"");
    value = this->_value / my_atof(rhs.toString());
    if (this->_precision >= rhs.getPrecision())
      type = this->_type;
    else
      type = rhs.getType();
    switch (type)
      {
      case INT8 :
	{
	  res = new Operand<char>(type, value);
	  break;
	}
      case INT16 :
	{
	  res = new Operand<short>(type, value);
	  break;
	}
      case INT32 :
	{
	  res = new Operand<int>(type, value);
	  break;
	}
      case FLOAT :
	{
	  res = new Operand<float>(type, value);
	  break;
	}
      case DOUBLE :
	{
	  res = new Operand<double>(type, value);
	  break;
	}
      }
    return (res);
  }
  virtual IOperand		*operator%(const IOperand &rhs) const
  {
    IOperand			*res;
    eOperandType		type;

    if (my_atof(rhs.toString()) == 0)
      throw Exception("Modulo by zero bro, \"Are u madding brooo ?! Kreooooog\"");
    if (this->_precision >= rhs.getPrecision())
      type = this->_type;
    else
      type = rhs.getType();
    if (this->_type == FLOAT || rhs.getType() == FLOAT)
      throw Exception("Try to make a modulo with FLOAT ? Kreog u Bro !");
    else if (this->_type == DOUBLE || rhs.getType() == DOUBLE)
      throw Exception("Try to make a modulo with DOUBLE ? Kreog u Bro !");
    res = new Operand(type, (int)this->_value % my_atoi(rhs.toString()));
    return (res);
  }
};

#endif		/* OPERAND_HPP_ */
