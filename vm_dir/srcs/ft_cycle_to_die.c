/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cycle_to_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:11:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:12:09 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_proc	*ft_check_live(t_proc *proc, int id, t_corewar *corewar)
{
	while (proc && id > proc->id)
	{
		id = proc->id;
		if (proc->live == 0)
		{
			if (corewar->visu_on == 0 && corewar->verb == 1)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				proc->id, proc->last_live, corewar->ctd_obj);
			proc = ft_del(proc);
		}
		else
		{
			proc->live = 0;
			proc = proc->nxt;
		}
	}
	return (proc);
}

t_proc	*ft_cycle_to_die(t_corewar *corewar, t_proc *proc)
{
	int		id;

	corewar->check += 1;
	id = ft_get_procnb(proc);
	proc = ft_check_live(proc, id, corewar);
	if (corewar->nb_live >= NBR_LIVE || corewar->check >= MAX_CHECKS)
	{
		corewar->check = 0;
		corewar->ctd_obj -= CYCLE_DELTA;
		if (corewar->visu_on == 0 && corewar->verb == 1)
			ft_printf("Cycle to die is now %d\n", corewar->ctd_obj);
	}
	corewar->ctd_cur = 0;
	corewar->nb_live = 0;
	if (proc == NULL)
		return (proc);
	while (proc->id < ft_get_procnb(proc) - 1)
		proc = proc->nxt;
	return (proc);
}
