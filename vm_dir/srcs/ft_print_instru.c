/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instru.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:26:58 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 17:46:30 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_instru(t_proc *proc)
{
	int		i;

	i = 0;
	ft_printf("ADV %d (0x%04x -> 0x%04x)", proc->ins->size + 1,
			proc->curseur - proc->init,
			proc->curseur - proc->init + proc->ins->size + 1);
	while (i <= proc->ins->size)
	{
		ft_printf(" %02x", *(ft_oob(proc->init, proc->curseur + i)));
		i++;
	}
	ft_printf(" \n");
}
