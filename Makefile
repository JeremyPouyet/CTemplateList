CC	= gcc

RM	= rm -f

NAME	= list

SRC_D	= srcs

SRCS	= $(SRC_D)/main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Werror -Wall -W

CFLAGS	+= -I./includes

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean

		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
