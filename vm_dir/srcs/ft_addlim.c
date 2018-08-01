/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:37:31 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/12 18:59:40 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		ft_addlim(int decal)
{
	int ret;

	ret = decal % MEM_SIZE;
	if (ft_abs(ret) > IDX_MOD && ft_abs(MEM_SIZE - ret) > IDX_MOD)
		ret = decal % IDX_MOD;
	if (ft_abs(MEM_SIZE - ret) < IDX_MOD)
		return (ret - MEM_SIZE);
	else
		return (ret);
}
