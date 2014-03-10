//
// IOperand.hh for IOperand in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Mon Feb 24 14:54:57 2014 thibau_j
// Last update Thu Feb 27 12:15:57 2014 thibau_j
//

#ifndef IOPERAND_HH_
# define IOPERAND_HH_

# include <string>

  enum	eOperandType
    {
      INT8,
      INT16,
      INT32,
      FLOAT,
      DOUBLE,
    };

class				IOperand
{
public:

  virtual std::string const	&toString() const = 0;	                // Renvoie une string reprensentant l’instance
  virtual int			getPrecision() const = 0;		// Renvoie la precision du type de l’instance
  virtual eOperandType		getType() const = 0;			// Renvoie le type de l’instance. Voir plus bas

  virtual IOperand		*operator+(const IOperand &rhs) const = 0;	// Somme
  virtual IOperand		*operator-(const IOperand &rhs) const = 0;	// Difference
  virtual IOperand		*operator*(const IOperand &rhs) const = 0;	// Produit
  virtual IOperand		*operator/(const IOperand &rhs) const = 0;	// Quotient
  virtual IOperand		*operator%(const IOperand &rhs) const = 0;	// Modulo

  virtual			~IOperand() {}
};

#endif				/* !IOPERAND_HH_ */
