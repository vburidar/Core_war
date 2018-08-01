/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 13:47:23 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/23 15:07:43 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

unsigned char	reverse(unsigned char b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return (b);
}

void			ft_print_ocp_suite(t_proc *proc, t_mask mask,
		int param, int type)
{
	if (proc->ins->ocp & mask.b && proc->ins->ocp & mask.a
			&& type)
		ft_printf(" %d", proc->ins->tab[param].val_type);
	else if (proc->ins->ocp & mask.b && !type)
		ft_printf(" %d", proc->ins->param[param]);
	else if (proc->ins->ocp & mask.b)
		ft_printf(" %d", proc->ins->tab[param].val_type, proc);
	else if (proc->ins->ocp & mask.a && type)
		ft_printf(" %d", proc->ins->tab[param].val_type);
	else if (proc->ins->ocp & mask.a)
		ft_printf(" r%d", proc->ins->param[param]);
}

void			ft_print_ocp(t_proc *proc, int param1, int param2, int param3)
{
	t_mask	mask;

	mask.a = 0x40;
	mask.b = 0x80;
	ft_print_ocp_suite(proc, mask, 0, param1);
	mask.a = 0x10;
	mask.b = 0x20;
	ft_print_ocp_suite(proc, mask, 1, param2);
	mask.a = 0x4;
	mask.b = 0x8;
	ft_print_ocp_suite(proc, mask, 2, param3);
}
