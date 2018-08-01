/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:22:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:13:00 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_live(t_proc *proc)
{
	int param;

	param = proc->ins->param[0];
	if (param == 0)
		param = 999999;
	ft_printf("P%5d | %s %d\n", proc->id, proc->ins->name, proc->ins->param[0]);
	if (proc->ins->param[0] > 2147483647)
		proc->ins->tab[0].val_type -= 4294967295;
	if (ft_abs(param) <= proc->corewar->nb_champ && param < 0)
	{
		ft_printf("Player %d (%s) is said to be alive\n",
			-param, proc->corewar->tab_champ[-param - 1].header.prog_name);
		proc->corewar->last_live_id = -param - 1;
	}
	ft_print_instru(proc);
}

void	ft_live(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	proc->corewar->nb_live += 1;
	if (proc->corewar->ctd_obj > 0)
		proc->live = 1;
	proc->last_live = 0;
	ins->size = ins->size;
	ins->param[0] = ft_get_int(proc->init, proc->curseur + 1, 4);
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_live(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + 5);
}
