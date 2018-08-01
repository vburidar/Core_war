/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:48:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:13:13 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_st(t_proc *proc)
{
	int value;

	value = proc->ins->param[1];
	if (value > 32768)
		value -= 65536;
	if ((proc->ins->tab[0].type == 1 && proc->ins->tab[1].type != 0)
		&& proc->ins->param[0] > 0 && proc->ins->param[0] < REG_NUMBER + 1
		&& (proc->ins->tab[1].type != 1
		|| proc->ins->param[1] < REG_NUMBER + 1))
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		if (proc->ins->tab[1].type == 1)
			ft_printf(" r%d %d", proc->ins->param[0], proc->ins->param[1]);
		else
			ft_printf(" r%d %d", proc->ins->param[0], value);
		ft_printf("\n");
	}
	ft_print_instru(proc);
}

void	ft_resize_ins(t_ins *ins)
{
	if (ins->ocp & 8 && ins->ocp & 4)
		ins->size -= 2;
	else if (ins->ocp & 8)
		ins->size -= 4;
	else if (ins->ocp & 4)
		ins->size -= 1;
}

void	ft_st(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	unsigned char	*tmp;
	int				value;

	value = proc->ins->param[1];
	if ((proc->ins->tab[0].type == 1 && proc->ins->tab[1].type != 0)
		&& proc->ins->param[0] > 0 && proc->ins->param[0] < REG_NUMBER + 1
		&& (proc->ins->tab[1].type != 1
		|| proc->ins->param[1] < REG_NUMBER + 1))
	{
		if (((ins->ocp & 0x20) && (ins->ocp & 0x10)) || (ins->ocp & 0x20))
		{
			if (value > 37768)
				value -= 65536;
			tmp = ft_oob(proc->init, proc->curseur + value % IDX_MOD);
			ft_write_ram(proc->reg[ins->param[0]], 4, tmp, proc);
		}
		else
			proc->reg[ins->param[1]] = proc->reg[ins->param[0]];
	}
	ft_resize_ins(ins);
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_st(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
