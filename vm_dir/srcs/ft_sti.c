/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:09:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:13:18 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_sti(t_proc *proc, int val_1, int val_2)
{
	if (proc->ins->tab[0].type == 1 && proc->ins->tab[1].type > 0
			&& proc->ins->tab[2].type > 0 && proc->ins->fail == 0)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_printf(" r%d %d %d", proc->ins->param[0], val_1, val_2);
		ft_printf("\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
				val_1, val_2, val_1 + val_2,
				proc->curseur - proc->init + (val_1 + val_2) % IDX_MOD);
	}
	ft_print_instru(proc);
}

void	ft_sti(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	int				val_1;
	int				val_2;
	unsigned char	*tmp;

	val_1 = 0;
	val_2 = 0;
	if (ins->tab[0].type == 1 && ins->tab[1].type > 0 && ins->tab[2].type > 0
			&& proc->ins->fail == 0)
	{
		val_1 = ins->tab[1].val_type;
		val_2 = ins->tab[2].val_type;
		tmp = ft_oob(proc->init, proc->curseur + (val_1 + val_2) % IDX_MOD);
		ft_write_ram(proc->reg[ins->param[0]], 4, tmp, proc);
	}
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_sti(proc, val_1, val_2);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
