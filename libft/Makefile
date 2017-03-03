# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epillot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 15:38:05 by epillot           #+#    #+#              #
#    Updated: 2017/02/08 19:57:28 by epillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC_STR_NAME = 	ft_atoi.c\
				ft_atol.c\
				ft_strcat.c\
				ft_strclr.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strdel.c\
				ft_strcpy.c\
				ft_striter.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strnjoin.c\
				ft_strlen.c\
				ft_strlcat.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_split_whitespace.c\
				ft_strncpy.c\
				ft_strncmp.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strnequ.c\
				ft_strrchr.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strupcase.c\
				ft_strsplit_lst.c\
				ft_strtrim.c\
				ft_strsplit.c\

SRC_FTPF_NAME = c_convert.c\
				d_convert.c\
				encode_unicode.c\
				ft_printf.c\
				ft_sprintf.c\
				ft_printf_fd.c\
				get_option.c\
				get_param.c\
				s_convert.c\
				str_format.c\
				tools_for_convert.c\
				tools_for_convert2.c\
				u_convert.c\
				wc_convert.c\
				ws_convert.c\

SRC_CHAR_NAME =	ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_isspace.c\
				ft_tolower.c\
				ft_toupper.c\

SRC_LST_NAME =	ft_lstadd.c\
				ft_lstadd_back.c\
				ft_lstiter.c\
				ft_lstdelone.c\
				ft_lstdel.c\
				ft_lstnew.c\
				ft_lstmap.c\
				ft_lst_size.c\
				ft_lst_at.c\
				ft_lst_swap_cnt.c\
				ft_lst_insert.c\
				ft_lstfree_cnt.c\

SRC_MEM_NAME =	ft_bzero.c\
				ft_memalloc.c\
				ft_memchr.c\
				ft_memccpy.c\
				ft_memcmp.c\
				ft_memdel.c\
				ft_memcpy.c\
				ft_memset.c\
				ft_memmove.c\

SRC_INT_NAME =	ft_itoa.c\
				ft_abs.c\
				ft_itoa_base.c\
				ft_max.c\
				nb_size.c\

SRC_GNL_NAME = 	get_next_line.c\

SRC_OUT_NAME =	ft_putchar.c\
				ft_putnchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putstr.c\
				ft_putnbr.c\
				ft_putstr_fd.c\
				ft_putnbr_base.c\
				ft_putnbr_fd.c\
				ft_print_memory.c\
				ft_print_bits.c\
				ft_putwchar.c\
				ft_putwchar_fd.c\
				ft_putwstr_fd.c\
				ft_putwstr.c\

SRC_STR_PATH = srcs/str_tools/

SRC_FTPF_PATH = srcs/ft_printf/

SRC_CHAR_PATH = srcs/char_tools/

SRC_LST_PATH = srcs/list/

SRC_MEM_PATH = srcs/mem_tools/

SRC_INT_PATH = srcs/int_tools/

SRC_GNL_PATH = srcs/gnl/

SRC_OUT_PATH = srcs/stdout/

INC = ./includes/

OBJ_NAME = $(SRC_STR_NAME:.c=.o)\
	       $(SRC_FTPF_NAME:.c=.o)\
	       $(SRC_CHAR_NAME:.c=.o)\
	  	   $(SRC_LST_NAME:.c=.o)\
	  	   $(SRC_MEM_NAME:.c=.o)\
	       $(SRC_INT_NAME:.c=.o)\
	       $(SRC_GNL_NAME:.c=.o)\
	       $(SRC_OUT_NAME:.c=.o)\

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
			
$(NAME): $(OBJ)
	@echo "\033[35mmaking $(NAME)...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mdone\033[0m"

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_STR_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_FTPF_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_CHAR_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_LST_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_MEM_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_INT_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_GNL_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRC_OUT_PATH)%.c
	@mkdir -p obj
	@gcc $(FLAG) -c -I $(INC) $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[34mlibft obj \033[32mcleaned\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[34m$(NAME) \033[32mremoved\033[0m"

re: fclean all
