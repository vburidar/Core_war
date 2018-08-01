/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credits_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:58:51 by rthys             #+#    #+#             */
/*   Updated: 2018/04/12 16:21:54 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	visu_credits(t_corewar *corewar)
{
	int x;

	x = INF + 1;
	mvwprintw(corewar->visu.win, 2, INF + 23, "C O R E W A R");
	mvwprintw(corewar->visu.win, 3, INF + 10, " by : ");
	wattron(corewar->visu.win, COLOR_PAIR(3));
	mvwprintw(corewar->visu.win, 3, INF + 16, "mlegeay");
	wattroff(corewar->visu.win, COLOR_PAIR(3));
	mvwprintw(corewar->visu.win, 3, INF + 23, ", ");
	wattron(corewar->visu.win, COLOR_PAIR(4));
	mvwprintw(corewar->visu.win, 3, INF + 25, "obenazzo");
	wattroff(corewar->visu.win, COLOR_PAIR(4));
	mvwprintw(corewar->visu.win, 3, INF + 33, ", ");
	wattron(corewar->visu.win, COLOR_PAIR(5));
	mvwprintw(corewar->visu.win, 3, INF + 35, "rthys");
	wattroff(corewar->visu.win, COLOR_PAIR(5));
	mvwprintw(corewar->visu.win, 3, INF + 40, ", ");
	wattron(corewar->visu.win, COLOR_PAIR(6));
	mvwprintw(corewar->visu.win, 3, INF + 42, "vburidar");
	wattroff(corewar->visu.win, COLOR_PAIR(6));
	wrefresh(corewar->visu.win);
	wattron(corewar->visu.win, A_STANDOUT);
	while (++x < ABS - 2)
		mvwprintw(corewar->visu.win, 5, x, " ", A_STANDOUT);
	wattroff(corewar->visu.win, A_STANDOUT);
}
