/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/04/12 14:15:42 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		define_colors(void)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i <= 6)
	{
		if (i == 1)
			init_pair(i, COLOR_RED, COLOR_BLACK);
		else if (i == 2)
			init_pair(i, COLOR_GREEN, COLOR_BLACK);
		else if (i == 3)
			init_pair(i, COLOR_YELLOW, COLOR_BLACK);
		else if (i == 4)
			init_pair(i, COLOR_BLUE, COLOR_BLACK);
		else if (i == 5)
			init_pair(i, COLOR_MAGENTA, COLOR_BLACK);
		else if (i == 6)
			init_pair(i, COLOR_CYAN, COLOR_BLACK);
		i++;
	}
}

void		visu_ctd(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 16, INF + 3, "Cycle to Die : %-4d", \
	corewar->ctd_obj);
	wrefresh(corewar->visu.win);
}

void		visu_acycle(t_corewar *corewar)
{
	mvwprintw(corewar->visu.win, 10, INF + 3, "Cycle : %-3d", corewar->cycle);
	wrefresh(corewar->visu.win);
}

void		visu_contestants(t_corewar *corewar)
{
	int i;
	int y;

	i = 0;
	y = 25;
	mvwprintw(corewar->visu.win, y, INF + 3, "Champions (%d) :",
	corewar->nb_champ);
	y += 2;
	while (i < corewar->nb_champ && i < 6)
	{
		corewar->tab_champ[i].color = i + 1;
		wattron(corewar->visu.win, COLOR_PAIR(i + 1));
		mvwprintw(corewar->visu.win, y, INF + 3, "%u . %s", \
		corewar->tab_champ[i].rank, corewar->tab_champ[i].header.prog_name);
		wattroff(corewar->visu.win, COLOR_PAIR(i + 1));
		i++;
		y += 2;
		wrefresh(corewar->visu.win);
	}
}
