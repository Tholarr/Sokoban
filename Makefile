##
## EPITECH PROJECT, 2022
## BTTF_sokoban
## File description:
## Makefile
##

SRC = 	main.c				\
		help.c				\
		info_file.c			\
		init_map.c			\
		verif.c				\
		inputs_gestion.c	\
		moves.c				\
		end_screen.c

NAME = 	my_sokoban

all:	$(NAME)

$(NAME):
		@gcc -g -o $(NAME) $(SRC) -lncurses
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
