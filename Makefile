# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 16:40:08 by epillot           #+#    #+#              #
#    Updated: 2017/03/10 13:26:47 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAG = -Wall -Wextra -Werror

SRC_NAME = main.c\
		   get_cmd_path.c\
		   process_cmd.c\
		   check_error_path.c\
		   minishell_error.c\
		   manage_env.c\
		   ft_cd.c\
		ft_getenv.c\
		minishell_init.c\
		ft_setenv.c\
		ft_unsetenv.c\

SRC_PATH = srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = -I./includes/ -I./libft/includes/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@echo "\033[35mmaking $(NAME)...\033[0m"
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(INC) -Llibft -lft
	@echo "\033[32mdone\033[0m"
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c $< -o $@ $(INC)

clean:
	@make fclean -C libft/
	@/bin/rm -f $(OBJ)
	@echo "\033[34mobj \033[32mcleaned\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[34m$(NAME) \033[32mremoved\033[0m"

re: fclean all
