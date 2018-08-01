/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulongatoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:10:48 by rthys             #+#    #+#             */
/*   Updated: 2018/03/19 13:11:23 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned long	ft_ulongatoi(const char *str)
{
	unsigned long	atoi;
	int				i;

	atoi = 0;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || \
	str[i] == '\v') || (str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		atoi = atoi * 10 + str[i] - '0';
		i++;
	}
	return (atoi);
}
