# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 11:52:57 by obenazzo          #+#    #+#              #
#    Updated: 2018/04/13 12:02:28 by rthys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all every clean fclean re corewar asm

NAME = every

FLAGS = -Wall -Wextra -Werror

ASM_SRC = ./asm_dir/srcs/valid_label.c \
		  ./asm_dir/srcs/get_op.c \
		  ./asm_dir/srcs/get_ocp.c \
		  ./asm_dir/srcs/parse_params.c \
		  ./asm_dir/srcs/endian_swap.c \
		  ./asm_dir/srcs/nbr_parsing.c \
		  ./asm_dir/srcs/split.c \
		  ./asm_dir/srcs/label_handling.c \
		  ./asm_dir/srcs/parse_op.c \
		  ./asm_dir/srcs/parse_cmd.c \
		  ./asm_dir/srcs/get_next_line.c \
		  ./asm_dir/srcs/asm.c \
		  ./asm_dir/srcs/pr_malloc.c \
		  ./asm_dir/srcs/print_error.c \
		  ./asm_dir/srcs/split_op.c \
		  ./asm_dir/srcs/utils.c

ASM_INC = ./asm_dir/includes/asm.h \
	  ./asm_dir/includes/get_next_line.h \
	  ./asm_dir/includes/ft_printf.h

LIBASM_SRC = ./asm_dir/libft/srcs/ft_atoi.c \
		   ./asm_dir/libft/srcs/ft_bzero.c \
		   ./asm_dir/libft/srcs/ft_isalnum.c \
		   ./asm_dir/libft/srcs/ft_isalpha.c \
		   ./asm_dir/libft/srcs/ft_isascii.c \
		   ./asm_dir/libft/srcs/ft_isdigit.c \
		   ./asm_dir/libft/srcs/ft_isprint.c \
		   ./asm_dir/libft/srcs/ft_itoa.c \
		   ./asm_dir/libft/srcs/ft_lstadd.c \
		   ./asm_dir/libft/srcs/ft_lstdel.c \
		   ./asm_dir/libft/srcs/ft_lstdelone.c \
		   ./asm_dir/libft/srcs/ft_lstiter.c \
		   ./asm_dir/libft/srcs/ft_lstmap.c \
		   ./asm_dir/libft/srcs/ft_lstnew.c \
		   ./asm_dir/libft/srcs/ft_memalloc.c \
		   ./asm_dir/libft/srcs/ft_memccpy.c \
		   ./asm_dir/libft/srcs/ft_memchr.c \
		   ./asm_dir/libft/srcs/ft_memcmp.c \
		   ./asm_dir/libft/srcs/ft_memcpy.c \
		   ./asm_dir/libft/srcs/ft_memdel.c \
		   ./asm_dir/libft/srcs/ft_memmove.c \
		   ./asm_dir/libft/srcs/ft_memset.c \
		   ./asm_dir/libft/srcs/ft_putchar.c \
		   ./asm_dir/libft/srcs/ft_putchar_fd.c \
		   ./asm_dir/libft/srcs/ft_putendl.c \
		   ./asm_dir/libft/srcs/ft_putendl_fd.c \
		   ./asm_dir/libft/srcs/ft_putnbr.c \
		   ./asm_dir/libft/srcs/ft_putnbr_fd.c \
		   ./asm_dir/libft/srcs/ft_putstr.c \
		   ./asm_dir/libft/srcs/ft_putstr_fd.c \
		   ./asm_dir/libft/srcs/ft_strcat.c \
		   ./asm_dir/libft/srcs/ft_strchr.c \
		   ./asm_dir/libft/srcs/ft_strclr.c \
		   ./asm_dir/libft/srcs/ft_strcmp.c \
		   ./asm_dir/libft/srcs/ft_strcpy.c \
		   ./asm_dir/libft/srcs/ft_strdel.c \
		   ./asm_dir/libft/srcs/ft_strdup.c \
		   ./asm_dir/libft/srcs/ft_strequ.c \
		   ./asm_dir/libft/srcs/ft_striter.c \
		   ./asm_dir/libft/srcs/ft_striteri.c \
		   ./asm_dir/libft/srcs/ft_strjoin.c \
		   ./asm_dir/libft/srcs/ft_strlcat.c \
		   ./asm_dir/libft/srcs/ft_strlen.c \
		   ./asm_dir/libft/srcs/ft_strmap.c \
		   ./asm_dir/libft/srcs/ft_strmapi.c \
		   ./asm_dir/libft/srcs/ft_strncat.c \
		   ./asm_dir/libft/srcs/ft_strncmp.c \
		   ./asm_dir/libft/srcs/ft_strncpy.c \
		   ./asm_dir/libft/srcs/ft_strnequ.c \
		   ./asm_dir/libft/srcs/ft_strnew.c \
		   ./asm_dir/libft/srcs/ft_strnstr.c \
		   ./asm_dir/libft/srcs/ft_strrchr.c \
		   ./asm_dir/libft/srcs/ft_strsplit.c \
		   ./asm_dir/libft/srcs/ft_strstr.c \
		   ./asm_dir/libft/srcs/ft_strsub.c \
		   ./asm_dir/libft/srcs/ft_strtrim.c \
		   ./asm_dir/libft/srcs/ft_tolower.c \
		   ./asm_dir/libft/srcs/ft_toupper.c \
		   ./asm_dir/libft/srcs/ft_atos.c \
		   ./asm_dir/libft/srcs/error.c \
		   ./asm_dir/libft/srcs/ft_write_count.c \
		   ./asm_dir/libft/srcs/padding.c \
		   ./asm_dir/libft/srcs/parse_specifier.c \
		   ./asm_dir/libft/srcs/get_next_arg.c \
		   ./asm_dir/libft/srcs/big.c \
		   ./asm_dir/libft/srcs/sml.c \
		   ./asm_dir/libft/srcs/ft_write_count.c \
		   ./asm_dir/libft/srcs/ft_putwcharstr.c \
		   ./asm_dir/libft/srcs/ft_printf.c \
		   ./asm_dir/libft/srcs/ft_voidstrlen.c \
		   ./asm_dir/libft/srcs/ft_ntchar.c \
		   ./asm_dir/libft/srcs/ft_skip_digits.c \
		   ./asm_dir/libft/srcs/ft_indexof.c \
		   ./asm_dir/libft/srcs/ft_wcslen.c \
		   ./asm_dir/libft/srcs/ft_lltoa.c \
		   ./asm_dir/libft/srcs/ft_ulltoa_base.c

LIBASM_INC = ./asm_dir/libft/includes/libft.h

VM_SRC = ./vm_dir/srcs/main.c\
	  ./vm_dir/srcs/ft_get_champ.c\
	  ./vm_dir/srcs/ft_get_instru.c\
	  ./vm_dir/srcs/ft_get_int.c\
	  ./vm_dir/srcs/ft_get_indireg.c\
	  ./vm_dir/srcs/ft_loop.c\
	  ./vm_dir/srcs/ft_live.c\
	  ./vm_dir/srcs/ft_ld.c\
	  ./vm_dir/srcs/ft_st.c\
	  ./vm_dir/srcs/load_arena.c\
	  ./vm_dir/srcs/ft_print_arena.c\
	  ./vm_dir/srcs/ft_ldi.c\
	  ./vm_dir/srcs/ft_sti.c\
	  ./vm_dir/srcs/ft_add.c\
	  ./vm_dir/srcs/ft_sub.c\
	  ./vm_dir/srcs/ft_fork.c\
	  ./vm_dir/srcs/ft_andorxor.c\
	  ./vm_dir/srcs/ft_zjmp.c\
	  ./vm_dir/srcs/ft_aff.c\
	  ./vm_dir/srcs/ft_oob.c\
	  ./vm_dir/srcs/ft_print_instru.c\
	  ./vm_dir/srcs/ft_addlim.c\
	  ./vm_dir/srcs/ft_print_proc.c\
	  ./vm_dir/srcs/ft_verbose.c\
	  ./vm_dir/srcs/ft_del.c\
	  ./vm_dir/srcs/ft_cycle_to_die.c\
	  ./vm_dir/srcs/ft_val_ocp.c\
	  ./vm_dir/srcs/ft_print_nxt.c\
	  ./vm_dir/srcs/ft_update_ins.c\
	  ./vm_dir/srcs/ft_output_arena.c\
	  ./vm_dir/srcs/pr_malloc.c\
	  ./vm_dir/srcs/error.c\
	  ./vm_dir/srcs/error_2.c\
	  ./vm_dir/srcs/options.c\
	  ./vm_dir/srcs/options2.c\
	  ./vm_dir/srcs/global_visu.c\
	  ./vm_dir/srcs/info_visu.c\
	  ./vm_dir/srcs/info_visu_2.c\
	  ./vm_dir/srcs/info_visu_3.c\
	  ./vm_dir/srcs/info_visu_4.c\
	  ./vm_dir/srcs/credits_visu.c\

VM_INC = ./vm_dir/includes/op.h

LIBVM_SRC = ./vm_dir/libft/srcs/ft_atoi.c\
		  ./vm_dir/libft/srcs/ft_bzero.c\
		  ./vm_dir/libft/srcs/ft_char_str.c\
		  ./vm_dir/libft/srcs/ft_concat.c\
		  ./vm_dir/libft/srcs/ft_fill_buff.c\
		  ./vm_dir/libft/srcs/ft_filltab.c\
		  ./vm_dir/libft/srcs/ft_getwchar.c\
		  ./vm_dir/libft/srcs/ft_isdigit.c\
		  ./vm_dir/libft/srcs/ft_itoa_base.c\
		  ./vm_dir/libft/srcs/ft_modif_len.c\
		  ./vm_dir/libft/srcs/ft_plus_space.c\
		  ./vm_dir/libft/srcs/ft_precision.c\
		  ./vm_dir/libft/srcs/ft_printf.c\
		  ./vm_dir/libft/srcs/ft_printfd.c\
		  ./vm_dir/libft/srcs/ft_putchar.c\
		  ./vm_dir/libft/srcs/ft_secure_strsub.c\
		  ./vm_dir/libft/srcs/ft_signed_nb_pt.c\
		  ./vm_dir/libft/srcs/ft_strcat.c\
		  ./vm_dir/libft/srcs/ft_strchr.c\
		  ./vm_dir/libft/srcs/ft_strcpy.c\
		  ./vm_dir/libft/srcs/ft_strncpy.c\
		  ./vm_dir/libft/srcs/ft_strdup.c\
		  ./vm_dir/libft/srcs/ft_strjoin.c\
		  ./vm_dir/libft/srcs/ft_strlen.c\
		  ./vm_dir/libft/srcs/ft_strsub.c\
		  ./vm_dir/libft/srcs/ft_tools.c\
		  ./vm_dir/libft/srcs/ft_unsigned_nb.c\
		  ./vm_dir/libft/srcs/get_next_line.c\
		  ./vm_dir/libft/srcs/ft_memchr.c\
		  ./vm_dir/libft/srcs/ft_memdel.c\
		  ./vm_dir/libft/srcs/ft_memmove.c\
		  ./vm_dir/libft/srcs/ft_bnull.c\
		  ./vm_dir/libft/srcs/ft_strcmp.c\
		  ./vm_dir/libft/srcs/ft_strsplit.c\
		  ./vm_dir/libft/srcs/ft_abs.c\
		  ./vm_dir/libft/srcs/ft_strequ.c\
		  ./vm_dir/libft/srcs/ft_putstr.c\
		  ./vm_dir/libft/srcs/ft_putchar.c\
		  ./vm_dir/libft/srcs/ft_putendl.c\
		  ./vm_dir/libft/srcs/ft_putnbr.c\
		  ./vm_dir/libft/srcs/ft_uatoi.c\
		  ./vm_dir/libft/srcs/ft_ulongatoi.c

LIBVM_INC = ./vm_dir/libft/includes/libft.h \
	  ./vm_dir/libft/includes/get_next_line.h



all:	$(NAME)

$(NAME): corewar asm

corewar: libcor
	make -C ./vm_dir/

asm: libasm
	make -C ./asm_dir/

libasm:
	make -C ./asm_dir/libft/

libcor:
	make -C ./vm_dir/libft/

clean:
	make -C ./vm_dir/ clean
	make -C ./asm_dir/ clean

fclean:
	make -C ./vm_dir/ fclean
	make -C ./asm_dir/ fclean

re: fclean all
