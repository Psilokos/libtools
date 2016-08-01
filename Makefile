##
## Makefile for libtools in /home/lecouv_v/rendu/PSU_2015_zappy/server/lib/tools
##
## Made by Victorien LE COUVIOUR--TUFFET
## Login   <lecouv_v@epitech.eu>
##
## Started on  Thu Jun  9 17:41:08 2016 Victorien LE COUVIOUR--TUFFET
## Last update Mon Aug  1 17:31:57 2016 Victorien LE COUVIOUR--TUFFET
##

CC		= gcc

NAME		= $(BIN_PATH)libtools.so

CFLAGS		+= -W -Wall -Werror -Wextra
CFLAGS		+= -I inc/
CFLAGS		+= -fPIC

LDFLAGS		= -shared

DIR_SRC		= src/

SRCS		= $(DIR_SRC)destroy.c	\
		  $(DIR_SRC)errors.c	\
		  $(DIR_SRC)get_arg.c	\
		  $(DIR_SRC)init.c	\
		  $(DIR_SRC)log.c

OBJS		= $(SRCS:.c=.o)

RM		= rm -f
PRINTF		= @printf

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $@ $(LDFLAGS)
		$(PRINTF) '\033[1;32m> Compiled\033[0m\n'

clean:
		$(RM) $(OBJS)
		$(PRINTF) '\033[1;35m> Directory cleaned\033[0m\n'

fclean:		clean
		$(RM) $(NAME)
		$(PRINTF) '\033[1;35m> Remove binary\033[0m\n'

re:		fclean all

.PHONY:		all clean fclean re
