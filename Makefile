##
## Makefile for list in /home/pouyet_j/perso/Template_List
##
## Made by Jérémy POUYET
## Login   <pouyet_j@epitech.net>
##
## Started on  Thu Jun 26 15:57:03 2014 Jérémy POUYET
## Last update Thu Jun 26 16:05:48 2014 Jérémy POUYET
##

CC	= gcc

RM	= rm -f

NAME	= list

SRC_D	= srcs

SRCS	= $(SRC_D)/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Werror -Wall -W

CFLAGS	+= -I./include

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean

		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
