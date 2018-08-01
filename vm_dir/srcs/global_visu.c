/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 08:37:18 by rthys             #+#    #+#             */
/*   Updated: 2018/04/04 20:13:36 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static void	visu_sides(WINDOW *win)
{
	int x;
	int y;

	y = 0;
	while (y <= ORD)
	{
		x = 0;
		while (x <= ABS)
		{
			if ((y > 0 && y < ORD - 1) && (x == 0 || x == INF || \
			x == ABS - 2))
				mvwprintw(win, y, x, "  ");
			x++;
		}
		y++;
	}
}

static void	visu_top_bot(WINDOW *win)
{
	int x;
	int y;

	y = 0;
	while (y <= ORD)
	{
		x = 0;
		while (x <= ABS)
		{
			if (((y == 0 && x > 0) && (y == 0 && x < ABS - 1)) || \
			((y == ORD - 1 && x > 0) && (y == ORD - 1 && x < ABS - 1)))
				mvwprintw(win, y, x, " ");
			x++;
		}
		y++;
	}
}

static void	visu_corner(WINDOW *win)
{
	int x;
	int y;

	y = 0;
	while (y <= ORD)
	{
		x = 0;
		while (x <= ABS)
		{
			if ((y == 0 && x == 0) || (y == ORD - 1 && x == 0) || \
			(y == 0 && x == ABS - 1) || (y == ORD - 1 && x == ABS - 1))
				mvwprintw(win, y, x, " ");
			x++;
		}
		y++;
	}
}

void		visu_startup(t_corewar *corewar)
{
	corewar->visu.change = 0;
	corewar->visu.win = initscr();
	noecho();
	nodelay(corewar->visu.win, 1);
	curs_set(0);
	keypad(corewar->visu.win, 1);
	start_color();
	define_colors();
	wattron(corewar->visu.win, A_STANDOUT);
	visu_corner(corewar->visu.win);
	visu_top_bot(corewar->visu.win);
	visu_sides(corewar->visu.win);
	wattroff(corewar->visu.win, A_STANDOUT);
	visu_credits(corewar);
	visu_contestants(corewar);
	visu_delta(corewar);
	visu_processes(corewar, corewar->nb_proc);
	visu_keys(corewar);
	visu_champs_arena(corewar);
}

void		global_visu(t_corewar *corewar)
{
	static int		ok = 0;
	static int		i = 0;

	if (ok == 0)
		visu_startup(corewar);
	visu_ctd(corewar);
	visu_acycle(corewar);
	visu_nbr_lives(corewar);
	visu_cbs(corewar);
	if (i == MEM_SIZE)
		i = 0;
	if (ok == 0)
	{
		visu_run(corewar);
		ok = 1;
	}
	if (corewar->visu.change == 1)
	{
		visu_champs_arena(corewar);
		corewar->visu.change = 0;
	}
	i++;
}
