##
## EPITECH PROJECT, 2017
## File description:
## Makefile
##

SRCC = ./src/

SRC	=	$(SRCC)eraser.c		\
		$(SRCC)animation.c	\
		$(SRCC)init.c		\
		$(SRCC)main.c		\
		$(SRCC)score.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Iinclude -g

LDFLAGS	=	-lm -Llib/my/ -lmy -lc_graph_prog

NAME	=	my_hunter

$(NAME):	 $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
