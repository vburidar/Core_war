# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/12 21:54:28 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = asm_cure

PATH_SRC = ./srcs/

PATH_OBJ = ./obj/

LIST_SRC = valid_label.c \
		   get_op.c \
		   get_ocp.c \
		   parse_params.c \
		   endian_swap.c \
		   nbr_parsing.c \
		   split.c \
		   label_handling.c \
		   parse_op.c \
		   parse_cmd.c \
		   get_next_line.c \
		   asm.c \
		   pr_malloc.c \
		   print_error.c \
		   split_op.c \
		   utils.c

LIST_LIB = ./libft/srcs/ft_atoi.c \
		   ./libft/srcs/ft_bzero.c \
		   ./libft/srcs/ft_isalnum.c \
		   ./libft/srcs/ft_isalpha.c \
		   ./libft/srcs/ft_isascii.c \
		   ./libft/srcs/ft_isdigit.c \
		   ./libft/srcs/ft_isprint.c \
		   ./libft/srcs/ft_itoa.c \
		   ./libft/srcs/ft_lstadd.c \
		   ./libft/srcs/ft_lstdel.c \
		   ./libft/srcs/ft_lstdelone.c \
		   ./libft/srcs/ft_lstiter.c \
		   ./libft/srcs/ft_lstmap.c \
		   ./libft/srcs/ft_lstnew.c \
		   ./libft/srcs/ft_memalloc.c \
		   ./libft/srcs/ft_memccpy.c \
		   ./libft/srcs/ft_memchr.c \
		   ./libft/srcs/ft_memcmp.c \
		   ./libft/srcs/ft_memcpy.c \
		   ./libft/srcs/ft_memdel.c \
		   ./libft/srcs/ft_memmove.c \
		   ./libft/srcs/ft_memset.c \
		   ./libft/srcs/ft_putchar.c \
		   ./libft/srcs/ft_putchar_fd.c \
		   ./libft/srcs/ft_putendl.c \
		   ./libft/srcs/ft_putendl_fd.c \
		   ./libft/srcs/ft_putnbr.c \
		   ./libft/srcs/ft_putnbr_fd.c \
		   ./libft/srcs/ft_putstr.c \
		   ./libft/srcs/ft_putstr_fd.c \
		   ./libft/srcs/ft_strcat.c \
		   ./libft/srcs/ft_strchr.c \
		   ./libft/srcs/ft_strclr.c \
		   ./libft/srcs/ft_strcmp.c \
		   ./libft/srcs/ft_strcpy.c \
		   ./libft/srcs/ft_strdel.c \
		   ./libft/srcs/ft_strdup.c \
		   ./libft/srcs/ft_strequ.c \
		   ./libft/srcs/ft_striter.c \
		   ./libft/srcs/ft_striteri.c \
		   ./libft/srcs/ft_strjoin.c \
		   ./libft/srcs/ft_strlcat.c \
		   ./libft/srcs/ft_strlen.c \
		   ./libft/srcs/ft_strmap.c \
		   ./libft/srcs/ft_strmapi.c \
		   ./libft/srcs/ft_strncat.c \
		   ./libft/srcs/ft_strncmp.c \
		   ./libft/srcs/ft_strncpy.c \
		   ./libft/srcs/ft_strnequ.c \
		   ./libft/srcs/ft_strnew.c \
		   ./libft/srcs/ft_strnstr.c \
		   ./libft/srcs/ft_strrchr.c \
		   ./libft/srcs/ft_strsplit.c \
		   ./libft/srcs/ft_strstr.c \
		   ./libft/srcs/ft_strsub.c \
		   ./libft/srcs/ft_strtrim.c \
		   ./libft/srcs/ft_tolower.c \
		   ./libft/srcs/ft_toupper.c \
		   ./libft/srcs/ft_atos.c \
		   ./libft/srcs/error.c \
		   ./libft/srcs/ft_write_count.c \
		   ./libft/srcs/padding.c \
		   ./libft/srcs/parse_specifier.c \
		   ./libft/srcs/get_next_arg.c \
		   ./libft/srcs/big.c \
		   ./libft/srcs/sml.c \
		   ./libft/srcs/ft_write_count.c \
		   ./libft/srcs/ft_putwcharstr.c \
		   ./libft/srcs/ft_printf.c \
		   ./libft/srcs/ft_voidstrlen.c \
		   ./libft/srcs/ft_ntchar.c \
		   ./libft/srcs/ft_skip_digits.c \
		   ./libft/srcs/ft_indexof.c \
		   ./libft/srcs/ft_wcslen.c \
		   ./libft/srcs/ft_lltoa.c \
		   ./libft/srcs/ft_ulltoa_base.c

INC_LIB = ./libft/includes/libft.h

LIST_OBJ = $(LIST_SRC:.c=.o)

SRC = $(addprefix $(PATH_SRC), $(LIST_SRC))

OBJ = $(addprefix $(PATH_OBJ), $(LIST_OBJ))

FLAGS = -Wall -Wextra -Werror

INC = ./includes/asm.h \
	  ./includes/get_next_line.h \
	  ./includes/ft_printf.h

LIB = -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) 
	cp $(NAME) ../asm

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	gcc $(FLAGS) -o $@ -c $< -g

clean :
	make clean -C libft
	rm -rf $(PATH_OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -rf ../asm
	make fclean -C libft

re :
	make fclean
	make
