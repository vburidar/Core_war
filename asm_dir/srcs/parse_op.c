/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	save_bytes(t_header *header, char *champion, void *temp, int i)
{
	if (header->prog_size + i <= CHAMP_MAX_SIZE)
		ft_memcpy(champion + header->prog_size, temp, i);
	else
		print_error(ERR_CHAMPION_SIZE);
	header->prog_size += i;
}

int		parse_op(char **op_arr, t_header *header, char *champion)
{
	int		o;

	o = 0;
	if (op_arr[0] && op_arr[0][ft_strlen(op_arr[0]) - 1] == LABEL_CHAR)
	{
		op_arr[0][ft_strlen(op_arr[0]) - 1] = 0;
		add_label(champion, op_arr[o++], (int[3]){header->prog_size, 0,
			header->prog_size}, -1);
		if (!op_arr[1])
		{
			pr_free_char_arr(op_arr);
			return (0);
		}
	}
	parse_params(op_arr, header, o, champion);
	pr_free_char_arr(op_arr);
	return (0);
}
