/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:49:00 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/04 20:12:26 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_ldi(t_proc *proc)
{
	int	val_1;
	int	val_2;

	val_1 = proc->ins->tab[0].val_type;
	val_2 = proc->ins->tab[1].val_type;
	if (proc->ins->fail == 0 && proc->ins->tab[0].type != 0 &&
			proc->ins->tab[1].type != 0 && proc->ins->tab[2].type == 1)
	{
		ft_printf("P%5d | %s", proc->id, proc->ins->name);
		ft_print_ocp(proc, 1, 1, 0);
		if (ft_strcmp(proc->ins->name, "ldi") == 0)
		{
			ft_printf("\n       | -> load from %d + %d = ", val_1, val_2);
			ft_printf("%d (with pc and mod %d)\n", val_1 + val_2,
				proc->curseur + (val_1 + val_2) % IDX_MOD - proc->init);
		}
		else
			ft_printf("\n       | -> load from %d + %d = %d (with pc %d)\n",
				val_1, val_2, val_1 + val_2,
				proc->curseur + (val_1 + val_2) - proc->init);
	}
	ft_print_instru(proc);
}

void	ft_ldi(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	int				val_1;
	int				val_2;
	unsigned char	*tmp;

	val_1 = proc->ins->tab[0].val_type;
	val_2 = proc->ins->tab[1].val_type;
	tmp = ft_oob(proc->init, proc->curseur + (val_1 + val_2) % IDX_MOD);
	if (proc->ins->fail == 0 && proc->ins->tab[0].type != 0 &&
			proc->ins->tab[1].type != 0 && proc->ins->tab[2].type == 1)
	{
		proc->reg[ins->param[2]] = ft_get_int(proc->init,
			ft_oob(proc->init, tmp), REG_SIZE);
	}
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_ldi(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}

void	ft_lldi(t_ins *ins, t_proc *proc, t_corewar *corewar)
{
	int				val_1;
	int				val_2;
	unsigned char	*tmp;

	val_1 = proc->ins->tab[0].val_type;
	val_2 = proc->ins->tab[1].val_type;
	tmp = ft_oob(proc->init, proc->curseur + (val_1 + val_2));
	if (proc->ins->fail == 0 && proc->ins->tab[0].type != 0 &&
			proc->ins->tab[1].type != 0 && proc->ins->tab[2].type == 1)
	{
		proc->reg[ins->param[2]] = ft_get_int(proc->init,
			ft_oob(proc->init, tmp), REG_SIZE);
		if (proc->reg[ins->param[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	if (corewar->visu_on == 0 && corewar->verb == 1)
		ft_print_ldi(proc);
	proc->curseur = ft_oob(proc->init, proc->curseur + ins->size + 1);
}
