##
## Makefile for Makefile in /home/thibauj/rendu/cpp_abstractvm
## 
## Made by thibau_j
## Login   <thibau_j@epitech.net>
## 
## Started on  Sat Mar  1 16:02:13 2014 thibau_j
## Last update Sun Mar  2 16:21:24 2014 thibau_j
##

NAME	= avm

SRC	= Exception.cpp \
	my_atof.cpp \
	my_atoi.cpp \
	OperandMaker.cpp \
	Parser.cpp

OBJ	= $(SRC:.cpp=.o)

CPP	= g++

CFLAGS	= -W -Wall -Wextra

RM	= rm -f

ECHO	= echo -e

$(NAME)	: $(OBJ)
	-@$(CPP) $(CFLAGS) -o $(NAME) $(OBJ)
	@$(ECHO) '\033[0;32m> Compiled With flags\033[0m'

all	: $(NAME)

clean	:
	-@$(RM) $(OBJ)
	@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'


fclean	: clean
	-@$(RM) $(NAME)
	@$(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re


