# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 17:11:33 by gd-innoc          #+#    #+#              #
#    Updated: 2023/06/19 10:00:18 by gd-innoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC = pipex utils checks

NAME_BONUS = pipex_bonus
SRC_BONUS = bonus/pipex_bonus bonus/utils_bonus	\
				bonus/checks_bonus bonus/fd_helpers_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

$(VERBOSE).SILENT:

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
FT_PRINTF = ./printf/libftprintf.a
FT_PRINTF_PATH = ./printf

#use phone to declare targets that are not associated with 
#file dependencies and should always be considered out-of-date
.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC:=.o)
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(NAME_BONUS): $(SRC_BONUS:=.o)
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(SRC_BONUS:=.o) $(LIBFT) $(FT_PRINTF) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	$(RM) $(SRC:=.o) $(SRC_BONUS:=.o)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus
