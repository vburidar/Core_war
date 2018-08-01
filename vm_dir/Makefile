# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/18 20:37:27 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = corewar_cure

PATH_SRC = ./srcs/

PATH_OBJ = ./obj/

LIST_SRC = main.c\
	  ft_get_champ.c\
	  ft_get_instru.c\
	  ft_get_int.c\
	  ft_get_indireg.c\
	  ft_loop.c\
	  ft_live.c\
	  ft_ld.c\
	  ft_st.c\
	  load_arena.c\
	  ft_print_arena.c\
	  ft_ldi.c\
	  ft_sti.c\
	  ft_add.c\
	  ft_sub.c\
	  ft_fork.c\
	  ft_andorxor.c\
	  ft_zjmp.c\
	  ft_aff.c\
	  ft_oob.c\
	  ft_print_instru.c\
	  ft_addlim.c\
	  ft_print_proc.c\
	  ft_verbose.c\
	  ft_del.c\
	  ft_cycle_to_die.c\
	  ft_val_ocp.c\
	  ft_print_nxt.c\
	  ft_update_ins.c\
	  ft_output_arena.c\
	  pr_malloc.c\
	  error.c\
	  error_2.c\
	  options.c\
	  options2.c\
	  global_visu.c\
	  info_visu.c\
	  info_visu_2.c\
	  info_visu_3.c\
	  info_visu_4.c\
	  credits_visu.c\

LIST_LIBSRC = ./libft/srcs/ft_atoi.c\
		  ./libft/srcs/ft_bzero.c\
		  ./libft/srcs/ft_char_str.c\
		  ./libft/srcs/ft_concat.c\
		  ./libft/srcs/ft_fill_buff.c\
		  ./libft/srcs/ft_filltab.c\
		  ./libft/srcs/ft_getwchar.c\
		  ./libft/srcs/ft_isdigit.c\
		  ./libft/srcs/ft_itoa_base.c\
		  ./libft/srcs/ft_modif_len.c\
		  ./libft/srcs/ft_plus_space.c\
		  ./libft/srcs/ft_precision.c\
		  ./libft/srcs/ft_printf.c\
		  ./libft/srcs/ft_printfd.c\
		  ./libft/srcs/ft_putchar.c\
		  ./libft/srcs/ft_secure_strsub.c\
		  ./libft/srcs/ft_signed_nb_pt.c\
		  ./libft/srcs/ft_strcat.c\
		  ./libft/srcs/ft_strchr.c\
		  ./libft/srcs/ft_strcpy.c\
		  ./libft/srcs/ft_strncpy.c\
		  ./libft/srcs/ft_strdup.c\
		  ./libft/srcs/ft_strjoin.c\
		  ./libft/srcs/ft_strlen.c\
		  ./libft/srcs/ft_strsub.c\
		  ./libft/srcs/ft_tools.c\
		  ./libft/srcs/ft_unsigned_nb.c\
		  ./libft/srcs/get_next_line.c\
		  ./libft/srcs/ft_memchr.c\
		  ./libft/srcs/ft_memdel.c\
		  ./libft/srcs/ft_memmove.c\
		  ./libft/srcs/ft_bnull.c\
		  ./libft/srcs/ft_strcmp.c\
		  ./libft/srcs/ft_strsplit.c\
		  ./libft/srcs/ft_abs.c\
		  ./libft/srcs/ft_strequ.c\
		  ./libft/srcs/ft_putstr.c\
		  ./libft/srcs/ft_putchar.c\
		  ./libft/srcs/ft_putendl.c\
		  ./libft/srcs/ft_putnbr.c\
		  ./libft/srcs/ft_uatoi.c\
		  ./libft/srcs/ft_ulongatoi.c

LIB_INC = ./libft/includes/libft.h \
	  ./libft/includes/get_next_line.h

LIST_OBJ = $(LIST_SRC:.c=.o)

SRC = $(addprefix $(PATH_SRC), $(LIST_SRC))

OBJ = $(addprefix $(PATH_OBJ), $(LIST_OBJ))

FLAGS = -Wall -Wextra -Werror

INC = ./includes/op.h

LIB = -L./libft -lft -lncurses

all: $(NAME)


$(NAME): $(OBJ) $(INC) 
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) 
	cp $(NAME) ../corewar

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	gcc $(FLAGS) -o $@ -c $< -g 

$(FT_PRINTF):
	make all -C libft

clean :
	make clean -C libft
	rm -rf $(PATH_OBJ)

fclean : clean
	rm -rf $(NAME)
	rm -f ../corewar
	make fclean -C libft

re :
	make fclean
	make
