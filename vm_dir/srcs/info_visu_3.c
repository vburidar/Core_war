/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/04/06 18:39:43 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		visu_winner(t_corewar *corewar)
{
	char inp;

	inp = 0;
	wattron(corewar->visu.win, COLOR_PAIR(corewar->last_live_id + 1));
	mvwprintw(corewar->visu.win, 45, INF + 3,
		"Constestant %u, \"%s\", has won !", \
	corewar->tab_champ[corewar->last_live_id].rank, \
	corewar->tab_champ[corewar->last_live_id].header.prog_name);
	wattroff(corewar->visu.win, COLOR_PAIR(corewar->last_live_id + 1));
	mvwprintw(corewar->visu.win, 48, INF + 3, "PRESS ANY KEY TO EXIT");
	wrefresh(corewar->visu.win);
	while (1)
	{
		inp = wgetch(corewar->visu.win);
		if (inp > 0)
			visu_inp(corewar, 27);
	}
}

void		visu_speed_2(t_corewar *corewar)
{
	if (corewar->nb_champ == 3)
	{
		if (ft_strequ("SLOW", corewar->cbs))
			usleep(250000 / 20);
		else if (ft_strequ("NORMAL", corewar->cbs))
			usleep(250000 / 200);
		else if (ft_strequ("FAST", corewar->cbs))
			usleep(150000 / 500);
	}
	else if (corewar->nb_champ == 4)
	{
		if (ft_strequ("SLOW", corewar->cbs))
			usleep(150000 / 20);
		else if (ft_strequ("NORMAL", corewar->cbs))
			usleep(150000 / 200);
		else if (ft_strequ("FAST", corewar->cbs))
			usleep(50000 / 500);
	}
	else
	{
		corewar->cbs = "Max (Locked : > 4 champions)";
		visu_cbs(corewar);
	}
}

void		visu_speed(t_corewar *corewar)
{
	if (corewar->nb_champ == 1)
	{
		if (ft_strequ("SLOW", corewar->cbs))
			usleep(850000 / 20);
		else if (ft_strequ("NORMAL", corewar->cbs))
			usleep(850000 / 200);
		else if (ft_strequ("FAST", corewar->cbs))
			usleep(850000 / 500);
	}
	else if (corewar->nb_champ == 2)
	{
		if (ft_strequ("SLOW", corewar->cbs))
			usleep(650000 / 40);
		else if (ft_strequ("NORMAL", corewar->cbs))
			usleep(650000 / 400);
		else if (ft_strequ("FAST", corewar->cbs))
			usleep(650000 / 600);
	}
	else
		visu_speed_2(corewar);
}

void		visu_run(t_corewar *corewar)
{
	char	*run;
	char	inp;

	run = NULL;
	inp = 0;
	if (corewar->visu.run == 0)
	{
		run = ">> START <<";
		corewar->visu.run = 1;
	}
	else
	{
		run = ">> PAUSE <<";
		corewar->visu.run = 0;
	}
	mvwprintw(corewar->visu.win, 7, INF + 6, " %s", run);
	wrefresh(corewar->visu.win);
	while (corewar->visu.run == 0 && (inp = wgetch(corewar->visu.win)) != ' ')
		visu_inp(corewar, inp);
	if (corewar->visu.run == 0)
		visu_run(corewar);
}
