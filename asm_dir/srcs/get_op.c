/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op	*find_op(t_op op_tab[], char *name)
{
	int i;

	i = 0;
	while (op_tab[i].name)
	{
		if (!ft_strcmp(op_tab[i].name, name))
			return (&(op_tab[i]));
		i++;
	}
	print_error(ERR_UNKNOWN_OPERATION);
	return (0);
}

t_op	*get_op(char *name)
{
	static t_op	op_tab[17] = {
		{"live", 1, {T_D}, 1, -1, 0, 0},
		{"ld", 2, {T_D | T_I, T_R}, 2, -1, 1, 0},
		{"st", 2, {T_R, T_I | T_R}, 3, -1, 1, 0},
		{"add", 3, {T_R, T_R, T_R}, 4, -1, 1, 0},
		{"sub", 3, {T_R, T_R, T_R}, 5, -1, 1, 0},
		{"and", 3, {T_R | T_D | T_I, T_R | T_I | T_D, T_R}, 6, -1, 1, 0},
		{"or", 3, {T_R | T_I | T_D, T_R | T_I | T_D, T_R}, 7, -1, 1, 0},
		{"xor", 3, {T_R | T_I | T_D, T_R | T_I | T_D, T_R}, 8, -1, 1, 0},
		{"zjmp", 1, {T_D}, 9, -1, 0, 1},
		{"ldi", 3, {T_R | T_D | T_I, T_D | T_R, T_R}, 10, -1, 1, 1},
		{"sti", 3, {T_R, T_R | T_D | T_I, T_D | T_R}, 11, -1, 1, 1},
		{"fork", 1, {T_D}, 12, -1, 0, 1},
		{"lld", 2, {T_D | T_I, T_R}, 13, -1, 1, 0},
		{"lldi", 3, {T_R | T_D | T_I, T_D | T_R, T_R}, 14, -1, 1, 1},
		{"lfork", 1, {T_D}, 15, -1, 0, 1},
		{"aff", 1, {T_R}, 16, -1, 1, 0},
		{0, 0, {0}, 0, 0, 0, 0}
	};

	return (find_op(op_tab, name));
}
