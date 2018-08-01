/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:54:36 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/23 15:45:34 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/op.h"

t_op	*ft_get_op_tab(void)
{
	static t_op op_tab[17] = {{"live", 1, 10, 0, 4, ft_live},
	{"ld", 2, 5, 1, 0, ft_ld},
	{"st", 2, 5, 1, 0, ft_st},
	{"add", 3, 10, 1, 0, ft_add},
	{"sub", 3, 10, 1, 0, ft_sub},
	{"and", 3, 6, 1, 0, ft_and},
	{"or", 3, 6, 1, 0, ft_or},
	{"xor", 3, 6, 1, 0, ft_xor},
	{"zjmp", 1, 20, 0, 2, ft_zjmp},
	{"ldi", 3, 25, 1, 0, ft_ldi},
	{"sti", 3, 25, 1, 0, ft_sti},
	{"fork", 1, 800, 0, 2, ft_fork},
	{"lld", 2, 10, 1, 0, ft_lld},
	{"lldi", 3, 50, 1, 0, ft_lldi},
	{"lfork", 1, 1000, 0, 2, ft_lfork},
	{"aff", 1, 2, 1, 0, ft_aff},
	{0, 0, 0, 0, 0, 0}};

	return (op_tab);
}

int		ft_is_instruc(char c)
{
	if (c < 17 && c > 0)
		return (1);
	return (0);
}

void	ft_get_var(t_proc *proc, unsigned char *code_champ, unsigned char *init)
{
	if (proc->ins->ocp < 0)
		proc->ins->ocp = 256 + proc->ins->ocp;
	if ((proc->ins->ocp & 0x80) && (proc->ins->ocp & 0x40))
		code_champ = ft_get_ind(proc->ins, code_champ, 0, init);
	else if (proc->ins->ocp & 0x80)
		code_champ = ft_get_dir(proc->ins, code_champ, 0, init);
	else if (proc->ins->ocp & 0x40)
		code_champ = ft_get_reg(proc, code_champ, 0, init);
	if (proc->ins->ocp & 0x20 && proc->ins->ocp & 0x10)
		code_champ = ft_get_ind(proc->ins, code_champ, 1, init);
	else if (proc->ins->ocp & 0x20)
		code_champ = ft_get_dir(proc->ins, code_champ, 1, init);
	else if (proc->ins->ocp & 0x10)
		code_champ = ft_get_reg(proc, code_champ, 1, init);
	if (proc->ins->ocp & 8 && proc->ins->ocp & 4)
		code_champ = ft_get_ind(proc->ins, code_champ, 2, init);
	else if (proc->ins->ocp & 8)
		code_champ = ft_get_dir(proc->ins, code_champ, 2, init);
	else if (proc->ins->ocp & 4)
		code_champ = ft_get_reg(proc, code_champ, 2, init);
	else if ((proc->ins->ocp & 1 || proc->ins->ocp & 2))
		proc->ins->fail = 1;
}

t_ins	*ft_get_instru(unsigned char *code_champ, unsigned char *init,
	void *old)
{
	t_op	*op_tab;
	t_ins	*ins;

	pr_free(old);
	ins = NULL;
	op_tab = ft_get_op_tab();
	if (ft_is_instruc(*code_champ))
	{
		ins = pr_malloc(sizeof(t_ins));
		ft_bzero(ins, sizeof(t_ins));
		ins->name = op_tab[(int)*(code_champ) - 1].name;
		ins->fun = op_tab[(int)*(code_champ) - 1].fun;
		ins->cycle = op_tab[(int)*(code_champ) - 1].length;
		if (op_tab[(int)*(code_champ) - 1].ocp == 1)
		{
			ins->size = ins->size + 1;
			init++;
		}
		else
		{
			ins->size = op_tab[(int)*(code_champ) - 1].size_no_ocp;
			ins->param[0] = ft_get_int(init, code_champ + 1, ins->size);
		}
	}
	return (ins);
}
