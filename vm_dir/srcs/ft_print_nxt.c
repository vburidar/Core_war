/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nxt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:45:21 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 17:56:37 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_nxt(unsigned char *init, unsigned char *curseur, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%02x ", *ft_oob(init, curseur + i));
		i++;
	}
	ft_printf("\n");
}
