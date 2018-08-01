/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:38:08 by mlegeay           #+#    #+#             */
/*   Updated: 2018/04/04 20:11:50 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_add(t_proc *proc, t_ins *ins)
{
	if (proc->ins->fail == 0 && ins->ocp == 84)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc, 0, 0, 0);
		ft_printf("\n");
	}
	ft_print_instru(proc);
}

void	ft_add(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	if (proc->ins->fail == 0 && ins->ocp == 0x54)
	{
		proc->reg[ins->param[2]] =
			proc->reg[ins->param[0]] +
			proc->reg[ins->param[1]];
		proc->carry = !(proc->reg[ins->param[2]]);
	}
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_add(proc, ins);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
