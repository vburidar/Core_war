/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:37:40 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:13:06 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/op.h"

void	ft_val_proc(t_proc *new, t_corewar *corewar, int i)
{
	ft_bzero(new, sizeof(t_proc));
	new->curseur = corewar->arena + i * (MEM_SIZE / corewar->nb_champ);
	new->live = 0;
	new->init = corewar->arena;
	new->corewar = corewar;
	new->player = i + 1;
	new->reg[1] = -new->player;
	new->ins = NULL;
	new->id = i + 1;
	corewar->id_max++;
	new->champ = corewar->tab_champ[0];
}

t_proc	*ft_init_proc(t_corewar *corewar)
{
	t_proc	*new;
	t_proc	*init;
	t_proc	*curseur;
	int		i;

	i = 0;
	corewar->id_max = 1;
	if (!(new = pr_malloc(sizeof(t_proc))))
		exit(1);
	init = new;
	curseur = new;
	ft_val_proc(new, corewar, i);
	new->nxt = new;
	i++;
	while (corewar->tab_champ[i].code)
	{
		if (!(new = pr_malloc(sizeof(t_proc))))
			exit(1);
		ft_val_proc(new, corewar, i);
		init->nxt = new;
		new->nxt = curseur;
		curseur = new;
		i++;
	}
	return (new);
}

t_proc	*ft_cycle(t_proc *proc, t_corewar *corewar)
{
	static int	max_id = 1;

	max_id = ft_get_procnb(proc) - 1;
	if (corewar->visu_on == 1)
		visu_processes(corewar, max_id);
	if ((corewar->ctd_cur == corewar->ctd_obj || corewar->ctd_obj < 0)
		&& proc->id == max_id)
	{
		if ((proc = ft_cycle_to_die(corewar, proc)) == NULL)
			return (NULL);
		max_id = ft_get_procnb(proc) - 1;
	}
	if (proc->id == max_id)
	{
		corewar->ctd_cur++;
		if (corewar->visu_on == 0 && corewar->verb == 1)
			ft_printf("It is now cycle %d\n", corewar->cycle + 1);
		if ((corewar->cycle++ + 1) == corewar->dump)
			exit(ft_dump(corewar));
	}
	proc->cycle++;
	proc->last_live++;
	if (corewar->visu_on == 1)
		visu_speed(corewar);
	return (proc);
}

char	update_visu(t_corewar *corewar, char inp)
{
	if (corewar->visu_on == 1)
	{
		global_visu(corewar);
		if ((inp = wgetch(corewar->visu.win)))
			visu_inp(corewar, inp);
	}
	return (inp);
}

void	ft_loop(t_corewar *corewar)
{
	t_proc		*lst_proc;
	int			dif;
	char		inp;

	lst_proc = ft_init_proc(corewar);
	while ((lst_proc = ft_cycle(lst_proc, corewar)) && lst_proc)
	{
		inp = update_visu(corewar, inp);
		dif = (lst_proc->cycle > 1 && lst_proc->cycle == lst_proc->ins->cycle);
		if (dif)
		{
			ft_update_ins(lst_proc->curseur, lst_proc->init, lst_proc);
			if ((corewar->visu.change = (lst_proc->ins != NULL)))
				(lst_proc->ins->fun)(lst_proc->ins, lst_proc, corewar);
			lst_proc->cycle = 0;
		}
		if (lst_proc->cycle <= 1)
			LPROC->ins = ft_get_instru(LPROC->curseur, LPROC->init, LPROC->ins);
		if (!dif && lst_proc->ins == NULL)
		{
			lst_proc->curseur = ft_oob(lst_proc->init, lst_proc->curseur + 1);
			lst_proc->cycle = 0;
		}
		lst_proc = lst_proc->nxt;
	}
}
