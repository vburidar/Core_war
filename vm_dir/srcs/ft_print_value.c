/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:26:26 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/20 17:28:08 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_value(int type, int val_type, t_proc *proc, int size)
{
	if (type == 1)
		ft_printf("%d", proc->reg[val_type]);
	else if (type == 2)
		ft_printf("%d", val_type);
	else
		ft_printf("%d", ft_get_int(proc->init,
			ft_oob(proc->init, proc->curseur + val_type), size));
}
