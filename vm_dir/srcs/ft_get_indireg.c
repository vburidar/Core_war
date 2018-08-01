/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_indireg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:54:24 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/25 18:42:55 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

unsigned char	*ft_get_ind(t_ins *ins, unsigned char *curseur, int n_param,
		unsigned char *init)
{
	unsigned char	*tmp;
	int				value;

	ins->tab[n_param].type = 3;
	ins->tab[n_param].val_type = 256 * *ft_oob(init, curseur)
		+ *ft_oob(init, curseur + 1);
	ins->param[n_param] = ins->tab[n_param].val_type;
	value = ins->param[n_param];
	if (value > 32768)
		value -= 65536;
	tmp = ft_oob(init, curseur + value % IDX_MOD - ins->size - 2 + 1);
	if (ft_strcmp(ins->name, "lld") == 0)
		ins->tab[n_param].val_type = ft_get_int(init,
		ft_oob(init, curseur + value - ins->size - 2 + 1), 2);
	else
		ins->tab[n_param].val_type = ft_get_int(init, tmp, 4);
	ins->size = ins->size + 2;
	return (ft_oob(init, curseur + 2));
}

unsigned char	*ft_get_dir(t_ins *ins, unsigned char *curseur, int n_param,
		unsigned char *init)
{
	ins->tab[n_param].type = 2;
	if (ft_strcmp(ins->name, "ldi") == 0 || ft_strcmp(ins->name, "sti")
			== 0 || ft_strcmp(ins->name, "lldi") == 0 || ft_strcmp(ins->name,
				" ") == 0 || ft_strcmp(ins->name, " ") == 0)
	{
		ins->size = ins->size + 2;
		ins->param[n_param] = 256 * *ft_oob(init, curseur)
			+ *ft_oob(init, curseur + 1);
		ins->tab[n_param].val_type = ins->param[n_param];
		if (ins->tab[n_param].val_type > 32768)
			ins->tab[n_param].val_type -= 65536;
		return (ft_oob(init, curseur + 2));
	}
	else
	{
		ins->param[n_param] = 256 * 256 * 256 * *ft_oob(init, curseur)
			+ 256 * 256 * *ft_oob(init, curseur + 1)
			+ 256 * *ft_oob(init, curseur + 2)
			+ *ft_oob(init, curseur + 3);
		ins->tab[n_param].val_type = ins->param[n_param];
		if (ins->tab[n_param].val_type > 2147483647)
			ins->tab[n_param].val_type -= 4294967295;
		ins->size = ins->size + 4;
		return (ft_oob(init, curseur + 4));
	}
}

unsigned char	*ft_get_reg(t_proc *proc, unsigned char *curseur, int n_param,
		unsigned char *init)
{
	proc->ins->param[n_param] = *ft_oob(init, curseur);
	if (proc->ins->param[n_param] < REG_NUMBER + 1
		&& proc->ins->param[n_param] > 0)
		proc->ins->tab[n_param].val_type = proc->reg[proc->ins->param[n_param]];
	else
		proc->ins->fail = 1;
	proc->ins->tab[n_param].type = 1;
	proc->ins->size = proc->ins->size + 1;
	return (ft_oob(init, curseur + 1));
}
