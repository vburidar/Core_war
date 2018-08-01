/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	save_file(char *input_filename, t_header *header, char *champion,
	int input_fd)
{
	int			output_fd;
	char		*output_filename;
	int			save;
	char		c;

	c = 0;
	save = header->prog_size;
	header->prog_size = endian_swap_32(header->prog_size);
	input_filename[ft_strlen(input_filename) - ft_strlen(INPUT_EXTENSION)] = 0;
	if (!(output_filename = ft_strjoin(input_filename, OUTPUT_EXTENSION)))
		print_error(ERR_MALLOC);
	if ((output_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR)) == -1)
		print_error(ERR_FILE_CREATION);
	lseek(input_fd, -1L, SEEK_END);
	if (read(input_fd, &c, 1) == -1 || c != '\n')
		print_error(c != '\n' ? ERR_SYNTAX : ERR_FILE_READING);
	write(output_fd, header, sizeof(t_header));
	write(output_fd, champion, save);
	ft_printf("Writing output program to %s\n", output_filename);
	pr_free(output_filename);
}

char	*parse_champion(t_header *header, int input_fd)
{
	static char	champion[CHAMP_MAX_SIZE + 1];
	char		*line;
	int			g;

	g = 1;
	line = 0;
	ft_bzero(champion, CHAMP_MAX_SIZE + 1);
	while (g == 1)
	{
		skip_empty_lines(&line, input_fd, &g);
		if (line)
		{
			if (ft_strchr(line, COMMENT_CHAR))
				*ft_strchr(line, COMMENT_CHAR) = 0;
			if (ft_strchr(line, COMMENT_CHAR_2))
				*ft_strchr(line, COMMENT_CHAR_2) = 0;
			parse_op(split_op(line), header, champion);
		}
		pr_free(line);
		if ((g = get_next_line(input_fd, &line)) == -1)
			print_error(ERR_GNL);
	}
	(!(header->prog_size)) ? print_error("EMPTY PROGRAM\n")
	: add_label(champion, (char *)-1, (int[3]){-1, -1, -1}, -1);
	return (champion);
}

int		main(int argc, char *argv[])
{
	t_header	header;
	int			input_fd;

	if (argc < 2)
		print_error(ERR_USAGE);
	if (ft_strcmp(INPUT_EXTENSION, argv[1] + ft_strlen(argv[1])
											- ft_strlen(INPUT_EXTENSION)))
		print_error(ERR_WRONG_EXTENSION);
	if ((input_fd = open(argv[1], O_RDONLY, S_IRUSR)) == -1)
		print_error(ERR_FILE_READING);
	ft_bzero(&header, sizeof(t_header));
	header.magic = endian_swap_32(COREWAR_EXEC_MAGIC);
	parse_cmd(&header, NAME_CMD_STRING, input_fd);
	parse_cmd(&header, COMMENT_CMD_STRING, input_fd);
	save_file(argv[1], &header, parse_champion(&header, input_fd), input_fd);
	return (0);
}
