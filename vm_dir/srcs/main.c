/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:06:45 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:13:50 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
** if % 16 == 0 TEMPORARY (print_code)
**while (1); RETIRER COMMENT POUR CHECKER RANK (main)
*/

static void		ft_display_contestant(t_corewar *corewar, int mode)
{
	int i;

	if (mode == 0)
	{
		i = 0;
		ft_printf("Introducing contestants...\n");
		while (i < corewar->nb_champ)
		{
			ft_printf("* Player %u, weighing %i bytes, \"%s\" (\"%s\") !\n",
			corewar->tab_champ[i].rank, corewar->tab_champ[i].header.prog_size,
			corewar->tab_champ[i].header.prog_name,
			corewar->tab_champ[i].header.comment);
			i++;
		}
	}
	else if (mode == 1)
	{
		ft_printf("Contestant %u, \"%s\", has won !\n",
		corewar->tab_champ[corewar->last_live_id].rank,
		corewar->tab_champ[corewar->last_live_id].header.prog_name);
	}
}

void			ft_print_code(t_champ champ)
{
	unsigned int i;

	i = 0;
	while (i < champ.header.prog_size)
	{
		ft_printf("%02x ", champ.code[i]);
		i++;
		if ((i % 16) == 0)
			ft_printf("\n");
	}
}

static void		ft_init_values(t_corewar *corewar, int argc, char **argv)
{
	if ((corewar->nb_champ = nbr_champs(argc, argv)) == 0)
		error_end(NULL, 0, NULL);
	corewar->a_rank = 1;
	corewar->n_rank = 1;
	corewar->select = 0;
	corewar->dump = -1;
	corewar->nb_proc = 0;
	corewar->visu_on = 0;
	corewar->verb = 0;
	corewar->cbs = "NORMAL";
	corewar->visu.run = 1;
}

static void		ft_init_all(int argc, char **argv, t_corewar *corewar)
{
	int			i;
	int			champ;

	i = 1;
	champ = -1;
	ft_bzero(corewar, sizeof(t_corewar));
	ft_init_values(corewar, argc, argv);
	while (i < argc)
	{
		if (argv[i][0] == '-')
			i = get_options(i, argv, corewar);
		else
			corewar->tab_champ[++champ] = ft_get_champ(argv[i++], corewar);
	}
	corewar->ctd_obj = CYCLE_TO_DIE;
}

int				main(int argc, char **argv)
{
	t_corewar	corewar;
	t_ins		*instru;
	int			i;

	instru = NULL;
	if (argc > 1)
	{
		ft_init_all(argc, argv, &corewar);
		load_arena(&corewar);
		if (corewar.visu_on == 0)
			ft_display_contestant(&corewar, 0);
		corewar.nb_proc = corewar.nb_champ;
		ft_loop(&corewar);
		if (corewar.visu_on == 0)
			ft_display_contestant(&corewar, 1);
		else
			visu_winner(&corewar);
	}
	else
		error_end(NULL, 0, NULL);
	i = 0;
	while (i < corewar.nb_champ)
		pr_free(corewar.tab_champ[i++].code);
	return (0);
}
