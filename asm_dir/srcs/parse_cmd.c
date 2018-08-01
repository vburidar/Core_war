/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*skip_whitespaces(char *s)
{
	while (ft_strchr(" \t\n\v\f\r", *s) && *s)
		s++;
	return (s);
}

void	check_line(char *s)
{
	s = skip_whitespaces(s);
	if (*s && *s != COMMENT_CHAR && *s != COMMENT_CHAR_2)
		print_error(ERR_SYNTAX);
}

void	cmd_buffering(char *dest, int fd, char *line, int type)
{
	int		g;
	char	*temp;

	temp = ft_strlen(line) + line + 1;
	while (1)
	{
		if (ft_strchr(temp, '"'))
		{
			if (ft_strchr(temp, '"') - temp + ft_strlen(dest) >
			(type ? COMMENT_LENGTH : PROG_NAME_LENGTH))
				print_error(ERR_INVALID_COMMAND);
			ft_strncpy(dest + ft_strlen(dest), temp,
			ft_strchr(temp, '"') - temp);
			check_line(ft_strchr(temp, '"') + 1);
			return (pr_free(line));
		}
		if (ft_strlen(temp) + ft_strlen(dest) > (type ? C_LENGTH : PN_LENGTH))
			print_error(ERR_INVALID_COMMAND);
		ft_strcpy(dest + ft_strlen(dest), temp);
		ft_memcpy(dest + ft_strlen(dest), "\n", 2);
		pr_free(line);
		if ((g = get_next_line(fd, &line)) != 1)
			print_error(ERR_GNL);
		temp = line;
	}
}

void	parse_cmd(t_header *header, char *cmd, int fd)
{
	char	*line;
	char	*temp;
	int		g;
	char	**line_arr;

	if ((g = get_next_line(fd, &line)) != 1)
		print_error(ERR_GNL);
	skip_empty_lines(&line, fd, &g);
	if (!(temp = ft_strchr(line, '"')))
		print_error(ERR_INVALID_COMMAND);
	*temp = 0;
	if (ft_arrstrlen(line_arr = split(line)) != 1 || !(line_arr[0][0]))
		print_error(ERR_INVALID_COMMAND);
	if (ft_strncmp(line_arr[0], line_arr[0][1] == COMMENT_CMD_STRING[1] ?
		COMMENT_CMD_STRING : NAME_CMD_STRING, ft_strlen(cmd)))
		print_error(ERR_INVALID_COMMAND);
	cmd_buffering(line_arr[0][1] == COMMENT_CMD_STRING[1] ?
		header->comment : header->prog_name, fd, line,
		line_arr[0][1] == COMMENT_CMD_STRING[1]);
	pr_free_char_arr(line_arr);
}
