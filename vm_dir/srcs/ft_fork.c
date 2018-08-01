/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:35:25 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:12:18 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/op.h"

int		ft_get_procnb(t_proc *proc)
{
	int init;
	int	ret;

	init = proc->id;
	ret = proc->id + 1;
	proc = proc->nxt;
	while (proc->id != init)
	{
		if (proc->id >= ret)
			ret = proc->id + 1;
		proc = proc->nxt;
	}
	return (ret);
}

t_proc	*ft_find_init(t_proc *proc)
{
	int		id;
	int		min;
	t_proc	*best;

	id = proc->id;
	min = proc->id;
	best = proc;
	proc = proc->nxt;
	while (proc->id != id)
	{
		if (proc->id < min)
		{
			best = proc;
			min = proc->id;
		}
		proc = proc->nxt;
	}
	return (best);
}

void	ft_print_fork(t_proc *proc)
{
	int value;

	value = proc->ins->param[0];
	if (value > 32768)
		value = value - 65536;
	ft_printf("P%5d | %s", proc->id, proc->ins->name);
	ft_printf(" %d", value);
	if (ft_strcmp(proc->ins->name, "fork") == 0)
		ft_printf(" (%d)\n", proc->curseur + value % IDX_MOD - proc->init);
	if (ft_strcmp(proc->ins->name, "lfork") == 0)
		ft_printf(" (%d)\n", proc->curseur + value - proc->init);
	ft_print_instru(proc);
}

void	ft_fork(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	t_proc	*new;
	t_proc	*init;
	int		value;

	corewar->nb_proc++;
	value = ins->param[0];
	if (value > 32768)
		value = value - 65536;
	new = pr_malloc(sizeof(t_proc));
	new = ft_memmove(new, proc, sizeof(t_proc));
	new->curseur = ft_oob(proc->init, proc->curseur + value % IDX_MOD);
	new->id = proc->corewar->id_max;
	proc->corewar->id_max++;
	init = ft_find_init(proc);
	new->nxt = init->nxt;
	init->nxt = new;
	new->ins = NULL;
	new->cycle = 0;
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_fork(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + 3);
	new->ins = ft_get_instru(new->curseur, proc->init, 0);
}

void	ft_lfork(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	t_proc	*new;
	t_proc	*init;
	int		value;

	corewar->nb_proc++;
	value = ins->param[0];
	if (value > 32768)
		value -= 65536;
	new = pr_malloc(sizeof(t_proc));
	new = ft_memmove(new, proc, sizeof(t_proc));
	new->curseur = ft_oob(proc->init, proc->curseur + value % MEM_SIZE);
	new->id = proc->corewar->id_max;
	proc->corewar->id_max++;
	init = ft_find_init(proc);
	new->nxt = init->nxt;
	init->nxt = new;
	new->ins = NULL;
	new->cycle = 0;
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_fork(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + 3);
	new->ins = ft_get_instru(new->curseur, proc->init, 0);
}
