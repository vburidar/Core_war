/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	get_ocp(char **op_arr, int o)
{
	char	ocp;
	int		a;
	char	t;

	a = 0;
	ocp = 0;
	while (op_arr[o])
	{
		if (op_arr[o][0] == 'r')
			t = 1;
		else if (op_arr[o][0] == DIRECT_CHAR)
			t = 2;
		else
			t = 3;
		ocp += t << (6 - 2 * a);
		a++;
		o++;
	}
	return (ocp);
}
