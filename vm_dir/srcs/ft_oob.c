/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oob.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:51:26 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/19 19:22:24 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int				ft_decal(unsigned char *init, unsigned char *curseur, int decal)
{
	decal = decal % MEM_SIZE;
	if (curseur - init + decal >= MEM_SIZE)
		return (decal - MEM_SIZE);
	else
		return (decal);
}

unsigned char	*ft_oob(unsigned char *init, unsigned char *dest)
{
	unsigned char *tmp;

	if (dest - init >= MEM_SIZE)
	{
		tmp = init + (dest - init) % MEM_SIZE;
		if (tmp < 0)
			return (MEM_SIZE + tmp);
		else
			return (tmp);
	}
	else if (dest - init < 0)
		return (MEM_SIZE + init + (dest - init) % MEM_SIZE);
	return (dest);
}
