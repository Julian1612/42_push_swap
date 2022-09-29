# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 10:32:35 by jschneid          #+#    #+#              #
#    Updated: 2022/09/29 20:26:26 by jschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Werror -Wextra -g
#-fsanitize=address,undefined

MANDATORY = main.c parser_00.c parser_01.c parser_02.c opperations_00.c opperations_01.c \
opperations_02.c opperations_03.c sorting_00.c sorting_01.c sorting_02.c sorting_03.c \
sorting_04.c utils_00.c

LIB = ./libft/libft.a

CC = gcc

OBJ = $(MANDATORY:.c=.o)

all: lib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

lib:
	@$(MAKE) -C libft/


# $(NAME):
$(NAME): $(OBJ) $(LIB)
	@cp ./libft/libft.a ./
	@$(CC) $(FLAGS) $(OBJ) -L. -lft -o $(NAME)
	@echo "make done"

# -Wno-gnu-include-next -I./LeakSanitizer/include -L./LeakSanitizer -llsan -lc++

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ) $(OBJB)
	@echo "make clean done"

fclean: clean
	@/bin/rm -f libft.a
	@/bin/rm -f $(NAME)
	@echo "make fclean done"

re: fclean all
	@echo "make re done"

.PHONY:	all bonus clean fclean re
