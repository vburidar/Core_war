/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <rthys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:50:29 by rthys             #+#    #+#             */
/*   Updated: 2018/04/04 20:11:45 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void			error_end(char *error, int id_error, char *info)
{
	if (id_error == 0)
	{
		ft_putstr("Usage: ./corewar [-visu] [-v] [-dump N] [[-n N] ");
		ft_putendl("<champion.cor>] ...");
		ft_putendl("	-a: Prints output from aff (Default is to hide it)");
		ft_putendl("	-visu: Activates visualizer");
		ft_putendl("	-v: Enables verbosity");
		ft_putendl("	-dump N: Dumps memory after N cycles then exits");
		ft_putendl("	-n N: Number N assigned to the following champion");
	}
	else
	{
		ft_putstr("\x1b[31mError ");
		ft_putnbr(id_error);
		ft_putstr(":\x1b[0m ");
		if (info)
		{
			ft_putstr(info);
			ft_putstr(": ");
		}
		ft_putendl(error);
	}
	exit(id_error);
}
