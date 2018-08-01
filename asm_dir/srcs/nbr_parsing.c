/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_nbr_parsing(char c)
{
	if (c && (!ft_strchr(" \t\n\v\f\r", c) && c != SEPARATOR_CHAR
	&& c != COMMENT_CHAR && c != COMMENT_CHAR_2))
		print_error(ERR_NBR_PARSING);
}

short	pr_atos(const char *str)
{
	short i;
	short nb;
	short nega;

	nega = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		nega = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (!i)
		print_error(ERR_NBR_PARSING);
	check_nbr_parsing(str[i]);
	return (nb * nega);
}

int		pr_atoi(const char *str)
{
	int i;
	int nb;
	int nega;

	nega = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		nega = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (!i)
		print_error(ERR_NBR_PARSING);
	check_nbr_parsing(str[i]);
	return (nb * nega);
}
