/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:34:04 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 17:53:23 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
** ft_printf("emplacement ram = %d, ram %p\n", ram - proc->init, ram);
*/

int		ft_pow(int time, int val)
{
	int i;
	int ret;

	i = 0;
	ret = 1;
	while (i < time)
	{
		ret = ret * val;
		i++;
	}
	return (ret);
}

void	ft_write_ram(int value, int size, unsigned char *ram, t_proc *proc)
{
	int				i;
	unsigned long	max;

	i = 0;
	max = ft_pow(size * 2, 16);
	if (value < 0)
		max = max + value;
	else
		max = value;
	while (i < size)
	{
		*ft_oob(proc->init, ram + i) = max / ft_pow((size - i - 1) * 2, 16);
		*ft_oob((unsigned char *)&(proc->corewar->arena_id[0]),
		ram + i - 1) = proc->player;
		i = i + 1;
	}
}

int		ft_get_int(unsigned char *init, unsigned char *code_champ, int size)
{
	int i;
	int ret;

	i = size;
	ret = 0;
	while (i > 0)
	{
		ret = ret + *ft_oob(init, code_champ + i - 1)
			* ft_pow((size - i), 256);
		i = i - 1;
	}
	return (ret);
}
