//
// Exception.hh for Exeception in /home/thibau_j/rendu/cpp_abstractvm
//
// Made by Jean-Stéphane THIBAULT
// Login   <thibau_j@epitech.net>
//
// Started on  Sun Feb 23 17:46:52 2014 thibau_j
// Last update Sat Mar  1 16:24:51 2014 thibau_j
//

#ifndef				EXCEPTION_HH_
# define			EXCEPTION_HH_

# include			<exception>

class				Exception : public std::exception
{

private:
  std::string			_msg;
  int				_line;
  std::string			_inst;

public:
  Exception(std::string const &msg, int const &line) throw();
  Exception(std::string const &msg, std::string const &inst) throw();
  Exception(std::string const &msg) throw();
  virtual			~Exception() throw();
  virtual const char		 *what() const throw();
};

#endif				/* !EXECEPTION_HH_ */
