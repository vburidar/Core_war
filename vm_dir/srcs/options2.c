/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:42:20 by mlegeay           #+#    #+#             */
/*   Updated: 2018/04/04 20:14:12 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int	available_nrank(t_corewar *corewar)
{
	int	i;
	int	unavailable;

	i = 0;
	unavailable = 0;
	while (i < corewar->nb_champ)
	{
		if (corewar->n_rank == corewar->tab_champ[i].rank)
		{
			if (unavailable == 1)
				corewar->a_rank++;
			unavailable = 1;
			corewar->n_rank = corewar->a_rank;
			i = -1;
		}
		i++;
	}
	if (unavailable == 1)
		corewar->a_rank = corewar->n_rank;
	else if (unavailable == 0 && corewar->n_rank == corewar->a_rank)
		next_arank(corewar);
	return (1);
}

int	nbr_champs(int argc, char **argv)
{
	int	i;
	int	champs;

	i = 1;
	champs = 0;
	while (i < argc)
	{
		if (ft_strequ(&argv[i][ft_strlen(argv[i]) - 4], ".cor"))
			champs++;
		i++;
	}
	if (champs > MAX_PLAYERS)
		error_end("Too much champions", 13, NULL);
	return (champs);
}
