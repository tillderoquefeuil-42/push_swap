#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 14:38:34 by tde-roqu          #+#    #+#              #
#    Updated: 2016/02/09 16:49:56 by tde-roqu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

SRC = ft_dblswap.c ft_middle_algo.c ft_putnbr.c ft_atoi.c ft_initialisation.c\
ft_mini_algo.c ft_putstr.c push_swap.c ft_bonus.c ft_lstft.c ft_putchar.c\
ft_swap.c main.c ft_bigalgotry.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
