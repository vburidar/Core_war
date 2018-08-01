/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:57:09 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:12:22 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_ld(t_proc *proc)
{
	if ((proc->ins->ocp == 144 || proc->ins->ocp == 146
		|| proc->ins->ocp == 208)
		&& proc->ins->param[1] > 0 && proc->ins->param[1] < REG_NUMBER + 1)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_printf(" %d r%d\n", proc->ins->tab[0].val_type,
		proc->ins->param[1]);
	}
	ft_print_instru(proc);
}

void	ft_print_lld(t_proc *proc, int value)
{
	if ((proc->ins->ocp == 144 || proc->ins->ocp == 208)
		&& proc->ins->fail == 0)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_printf(" %d r%d\n", value, proc->ins->param[1]);
	}
	ft_print_instru(proc);
}

void	ft_ld(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	if ((ins->ocp == 144 || ins->ocp == 146 || ins->ocp == 208)
		&& ins->param[1] > 0
		&& ins->param[1] < REG_NUMBER + 1)
	{
		proc->reg[ins->param[1]] = ins->tab[0].val_type;
		if (ins->tab[0].val_type == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else if (ins->ocp & 8 && ins->ocp & 4)
		ins->size -= 2;
	else if (ins->ocp & 8)
		ins->size -= 4;
	else if (ins->ocp & 4)
		ins->size -= 1;
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_ld(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

void	ft_lld(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	int value;

	value = ins->tab[0].val_type;
	if (ins->tab[0].type == 3 && value > 32768)
		value = value - 65536;
	if ((ins->ocp == 144 || ins->ocp == 208) && proc->ins->fail == 0)
	{
		proc->reg[ins->param[1]] = value;
		if (ins->param[0] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else if (ins->ocp & 8 && ins->ocp & 4)
		ins->size -= 2;
	else if (ins->ocp & 8)
		ins->size -= 4;
	else if (ins->ocp & 4)
		ins->size -= 1;
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_lld(proc, value);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
