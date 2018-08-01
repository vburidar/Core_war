# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/12 17:15:38 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

PATH_SRC = ./srcs/

PATH_OBJ = ./obj/

LIST_SRC = ft_atoi.c\
		  ft_bzero.c\
		  ft_char_str.c\
		  ft_concat.c\
		  ft_fill_buff.c\
		  ft_filltab.c\
		  ft_getwchar.c\
		  ft_isdigit.c\
		  ft_itoa_base.c\
		  ft_modif_len.c\
		  ft_plus_space.c\
		  ft_precision.c\
		  ft_printf.c\
		  ft_printfd.c\
		  ft_putchar.c\
		  ft_secure_strsub.c\
		  ft_signed_nb_pt.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strcpy.c\
		  ft_strncpy.c\
		  ft_strdup.c\
		  ft_strjoin.c\
		  ft_strlen.c\
		  ft_strsub.c\
		  ft_tools.c\
		  ft_unsigned_nb.c\
		  get_next_line.c\
		  ft_memchr.c\
		  ft_memdel.c\
		  ft_memmove.c\
		  ft_bnull.c\
		  ft_strcmp.c\
		  ft_strsplit.c\
		  ft_abs.c\
		  ft_strequ.c\
		  ft_putstr.c\
		  ft_putchar.c\
		  ft_putendl.c\
		  ft_putnbr.c\
		  ft_uatoi.c\
		  ft_ulongatoi.c

LIST_OBJ =  $(LIST_SRC:.c=.o)

SRC = $(addprefix $(PATH_SRC), $(LIST_SRC))

OBJ = $(addprefix $(PATH_OBJ), $(LIST_OBJ))

FLAGS = -Wall -Wextra -Werror

INC	= ./includes/libft.h \
	  ./includes/get_next_line.h

all: $(NAME)

$(NAME)	: $(OBJ) $(INC)
	ar -r $@ $^

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	gcc $(FLAGS) -o $@ -c $<

clean	:
	rm -rf $(PATH_OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean clean re
