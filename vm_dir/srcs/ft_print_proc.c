/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:36:10 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/21 17:45:56 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void	ft_print_proc(t_proc *proc)
{
	ft_printf("P%5d | %s", proc->id, proc->ins->name);
	ft_printf(" %d %d %d\n", proc->ins->param[0],
			proc->ins->param[1], proc->ins->param[2]);
}
