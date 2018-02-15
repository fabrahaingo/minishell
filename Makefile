# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frahaing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 15:12:16 by frahaing          #+#    #+#              #
#    Updated: 2018/02/12 13:29:34 by frahaing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRC =		srcs/ft_fill_tab.c \
			srcs/ft_lastdir.c \
			srcs/ft_binary_there.c \
			srcs/ft_parse_tab.c \
			srcs/ft_notfound.c \
			srcs/ft_initialize.c \
			srcs/ft_parse_ident.c \
			srcs/ft_empty.c \
			builtins/ft_cd/ft_cd.c \
			builtins/ft_cd/ft_signstart.c \
			builtins/ft_echo.c \
			builtins/ft_env.c \
			builtins/ft_setenv.c \
			builtins/ft_unsetenv.c \
			builtins/ft_cd/ft_ispath.c

OBJ =		$(SRC:.c=.o)

FLAG =		-Wall -Werror -Wextra -g

INC =		includes/

MAIN =		main.c

all :		$(NAME)

$(NAME) : $(OBJ)
			@$(MAKE) -C libft/ all
			@gcc -o $(NAME) $(FLAG) $(MAIN) $(SRC) -I $(INC) libft/libft.a

%.o: %.c
			@gcc -c $< -o $@ $(FLAG)

clean :
			@rm -f $(OBJ)
			@$(MAKE) -C libft/ clean

fclean :	clean
			@rm -f $(NAME)
			@$(MAKE) -C libft/ fclean

re :		fclean all
