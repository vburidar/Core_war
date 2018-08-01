/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		empty_line(char *str)
{
	while (str && *str)
	{
		if (*str == COMMENT_CHAR || *str == COMMENT_CHAR_2)
			break ;
		if (!ft_strchr(" \t\n\v\f\r", *str))
			return (0);
		str++;
	}
	return (1);
}

void	skip_empty_lines(char **line, int input_fd, int *g)
{
	while (!(*line) || empty_line(*line))
	{
		pr_free(*line);
		if ((*g = get_next_line(input_fd, line)) == -1)
			print_error(ERR_GNL);
		else if (!(*g))
			break ;
	}
}

void	pr_free_char_arr(char **to_free)
{
	int i;

	i = 0;
	while (to_free[i])
		pr_free(to_free[i++]);
	pr_free(to_free);
}

int		ft_arrstrlen(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}
