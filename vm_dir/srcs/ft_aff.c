/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:16:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/25 19:00:48 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

/*
**	if (ins->fail == 0)
**	{
**		//ft_printf("P%5d | %s", proc->id, ins->name);
**		//ft_print_ocp(proc, 0, 0, 0);
**		//ft_printf("\n");
**	}
** (in ft_print_aff before calling ft_print_instru)
**
**ft_printf("%c", ins->param[0] % 256);
** ( in ft_aff first if)
*/

void	ft_print_aff(t_ins *ins, t_proc *proc)
{
	if (ins->fail == 0)
		ins->fail = 0;
	ft_print_instru(proc);
}

void	ft_aff(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	if (ins->tab[0].type == 1)
		ins->size = 2;
	else
	{
		if (ins->tab[0].type == 3)
			ins->size = 3;
		else
			ins->size = 1;
		proc->ins->fail = 1;
	}
	if (proc->ins->fail == 0 && proc->ins->ocp == 64)
		proc->ins->param[1] = 0;
	if (!(corewar->visu_on) && !(proc->ins->fail)
	&& corewar->aff && !(proc->ins->fail))
		ft_printf("Aff: %c\n", proc->reg[proc->ins->param[0]]);
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_aff(ins, proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
