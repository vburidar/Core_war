/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:46:34 by mlegeay           #+#    #+#             */
/*   Updated: 2018/03/09 15:36:11 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static void	place_champ(t_corewar *corewar, int i, int id)
{
	unsigned int	j;

	j = 0;
	while (j < corewar->tab_champ[id].header.prog_size)
	{
		corewar->arena_id[i] = id + 1;
		corewar->arena[i] = corewar->tab_champ[id].code[j];
		i++;
		j++;
	}
}

static int	load_champ(t_corewar *corewar, int id)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (i < MEM_SIZE && res == 0)
	{
		if (corewar->arena_id[i] == 0)
		{
			corewar->last_live_id = id;
			place_champ(corewar, i, id);
			return (1);
		}
		i += (MEM_SIZE / corewar->nb_champ);
	}
	if (res == 0)
		return (-1);
	return (0);
}

void		load_arena(t_corewar *corewar)
{
	int	i;
	int	res;

	i = 0;
	while (i < corewar->nb_champ)
	{
		res = 0;
		while (res == 0)
			res = load_champ(corewar, i);
		i++;
	}
}
