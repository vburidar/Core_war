/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:40:52 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:13:29 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_zjmp(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	int value;

	value = ins->param[0];
	if (value > 32768)
		value -= 65536;
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_printf("P%5d | zjmp %d", proc->id, value);
	if (proc->carry == 1)
	{
		if (corewar->visu_on == 0 && corewar->verb == 1)
			ft_printf(" OK\n");
		proc->curseur = ft_oob(proc->init, proc->curseur + value % IDX_MOD);
	}
	else
	{
		if (corewar->visu_on == 0 && corewar->verb == 1)
		{
			ft_printf(" FAILED\n");
			ft_print_instru(proc);
		}
		proc->curseur = ft_oob(proc->init, proc->curseur + 3);
	}
}
