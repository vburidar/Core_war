/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/04/06 18:27:19 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		visu_delta(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 16, INF + 3,
		"CYCLE_DELTA : %-3u", CYCLE_DELTA);
	wrefresh(corewar->visu.win);
}

void		visu_nbr_lives(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 19, INF + 3,
		"NBR_LIVES : %-4d", corewar->nb_live);
	wrefresh(corewar->visu.win);
}

void		visu_processes(t_corewar *corewar, int proc)
{
	mvwprintw(corewar->visu.win, 22, INF + 3,
		"Processes : %-4d", corewar->nb_proc + proc - proc);
	wrefresh(corewar->visu.win);
}

void		visu_cbs(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 13, INF + 3, "Speed : %-27s", corewar->cbs);
	wrefresh(corewar->visu.win);
}

void		visu_champs_arena(t_corewar *corewar)
{
	int	y;
	int	x;
	int	i;

	x = 3;
	y = 1;
	i = 0;
	while (i < MEM_SIZE)
	{
		while (x < INF)
		{
			wattron(corewar->visu.win, COLOR_PAIR(corewar->arena_id[i]));
			mvwprintw(corewar->visu.win, y, x, "%02x ", corewar->arena[i]);
			wattroff(corewar->visu.win, COLOR_PAIR(corewar->arena_id[i]));
			i++;
			x += 3;
		}
		y++;
		if (y > 64)
			y -= 63;
		x = 3;
	}
	wrefresh(corewar->visu.win);
}
