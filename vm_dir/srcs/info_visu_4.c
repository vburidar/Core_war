/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:43:38 by rthys             #+#    #+#             */
/*   Updated: 2018/04/06 19:18:17 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		visu_mod_speed(t_corewar *corewar, char inp)
{
	if (ft_strequ("SLOW", corewar->cbs) && inp == '+')
		corewar->cbs = "NORMAL";
	else if (ft_strequ("NORMAL", corewar->cbs))
	{
		if (inp == '+')
			corewar->cbs = "FAST";
		else
			corewar->cbs = "SLOW";
	}
	else if (ft_strequ("FAST", corewar->cbs))
	{
		if (inp == '+')
			corewar->cbs = "MAX";
		else
			corewar->cbs = "NORMAL";
	}
	else if (ft_strequ("MAX", corewar->cbs) && inp == '-')
		corewar->cbs = "FAST";
	visu_cbs(corewar);
}

void		visu_inp(t_corewar *corewar, char inp)
{
	if (inp == 27)
	{
		endwin();
		exit(0);
	}
	else if (inp == '+' || inp == '-')
		visu_mod_speed(corewar, inp);
	else if (inp == ' ')
		visu_run(corewar);
	wrefresh(corewar->visu.win);
}

void		visu_keys(t_corewar *corewar)
{
	if (corewar->nb_champ <= 4)
	{
		mvwprintw(corewar->visu.win, 36, INF + 3, "'+' : Faster");
		mvwprintw(corewar->visu.win, 38, INF + 3, "'-' : Slower");
	}
	mvwprintw(corewar->visu.win, 40, INF + 3, "'SPACE' : Start/Pause");
	mvwprintw(corewar->visu.win, 42, INF + 3, "'ESC' : Exit");
	wrefresh(corewar->visu.win);
}
