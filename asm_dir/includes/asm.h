/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/04/12 19:32:07 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define ERR_NBR_PARSING		"Invalid character after a number\n"
# define ERR_ARG_TYPE			"Wrong arg type\n"
# define ERR_LABEL_NOT_FOUND	"Label not found\n"
# define ERR_USAGE				"Usage: ./asm <sourcefile.s>\n"
# define ERR_FILE_READING 		"Can't read source file\n"
# define ERR_FILE_CREATION		"Can't create champion\n"
# define ERR_MALLOC				"malloc returned 0\n"
# define ERR_PARSING			"Parsing error\n"
# define ERR_GNL				"GNL returned 0 or -1\n"
# define ERR_SYNTAX				"Syntax error\n"
# define ERR_COMMAND_LENGTH		"A command is too long\n"
# define ERR_INVALID_COMMAND	"A command is invalid\n"
# define ERR_WRONG_EXTENSION	"The filename extension must be .s\n"
# define ERR_UNKNOWN_OPERATION	"Unknown operation\n"
# define ERR_ARG_LEN			"Wrong number of arguments\n"
# define ERR_INVALID_LABEL		"Invalid label\n"
# define ERR_CHAMPION_SIZE		"The champion is too large\n"
# define INPUT_EXTENSION		".s"
# define OUTPUT_EXTENSION 		".cor"
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3
# define MEM_SIZE				(4*1024)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define COMMENT_CHAR			'#'
# define COMMENT_CHAR_2			';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_R					T_REG
# define T_D					T_DIR
# define T_I					T_IND
# define DATA					content
# define SZ						sizeof
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define PN_LENGTH				PROG_NAME_LENGTH
# define C_LENGTH				COMMENT_LENGTH
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char			*name;
	int				arg_len;
	int				args_type[3];
	char			op_code;
	char			ocp;
	int				print_ocp;
	int				d2;
}					t_op;

typedef struct		s_label
{
	char			*name;
	short			location;
	short			spg;
	int				d2;
}					t_label;

typedef struct		s_labels
{
	t_list			*to_replace;
	t_list			*saved;
}					t_labels;

char				*check_cmd(char *cmd, int fd, char **line,
						size_t max_length);
void				parse_cmd(t_header *header, char *cmd, int fd);
int					parse_op(char **op_arr, t_header *header, char *champion);
void				parse_params(char **op_arr, t_header *header, int o,
						char *champion);
t_op				*get_op(char *name);
char				get_ocp(char **op_arr, int o);
void				save_bytes(t_header *header, char *champion, void *temp,
						int i);
int					valid_label(char *label);
t_label				*get_label(char *champion, char *name, int type);
t_label				*add_label(char *champion, char *name, int loc_type_st[3],
						int d2);
void				skip_empty_lines(char **line, int input_fd, int *g);
int					empty_line(char *str);
void				*pr_malloc(size_t n);
void				pr_free(void *p);
void				print_error(char *err);
char				**split_op(char *str);
char				**while_char(char *str, char **words, int save, int w);
char				**w_char(char *str, char **words, int save, int w);
char				**split(char *str);
void				pr_free_char_arr(char **to_free);
int					ft_arrstrlen(char **arr);
int					pr_atoi(const char *str);
short				pr_atos(const char *str);
void				check_nbr_parsing(char c);
short				endian_swap_16(short n);
int					endian_swap_32(int n);
#endif
