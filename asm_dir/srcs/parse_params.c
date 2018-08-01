/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	parse_register(t_header *header, char **arg_champ)
{
	char	r;

	if (ft_strlen(arg_champ[0]) > 3 || !(arg_champ[0][1]) ||
	!ft_isdigit(arg_champ[0][1])
	|| (arg_champ[0][2] && !ft_isdigit(arg_champ[0][2])))
		print_error(ERR_SYNTAX);
	r = pr_atoi(arg_champ[0] + 1);
	save_bytes(header, arg_champ[1], &r, 1);
}

void	parse_direct(t_header *header, t_op *op, char **arg_champ, int spg)
{
	short	r;
	int		n;

	r = 0;
	n = 0;
	if (!(op->d2))
	{
		if (arg_champ[0][1] == LABEL_CHAR)
			add_label(arg_champ[1], arg_champ[0] + 2,
				(int[3]){header->prog_size, 1, spg}, op->d2);
		if (arg_champ[0][1] != LABEL_CHAR)
			n = endian_swap_32(pr_atoi(arg_champ[0] + 1));
		save_bytes(header, arg_champ[1], &n, sizeof(int));
	}
	else if (arg_champ[0][1] == LABEL_CHAR)
	{
		add_label(arg_champ[1], arg_champ[0] + 2, (int[3]){header->prog_size, 1
			, spg}, op->d2);
		save_bytes(header, arg_champ[1], &r, sizeof(short));
	}
	else
	{
		r = endian_swap_16(pr_atos(arg_champ[0] + 1));
		save_bytes(header, arg_champ[1], &r, sizeof(short));
	}
}

void	parse_indirect(t_header *header, char **arg_champ, int spg)
{
	short	r;

	r = 0;
	if (arg_champ[0][0] == LABEL_CHAR)
		add_label(arg_champ[1], arg_champ[0] + 1, (int[3]){header->prog_size,
			1, spg}, 1);
	else
		r = endian_swap_16(pr_atos(arg_champ[0]));
	save_bytes(header, arg_champ[1], &r, sizeof(short));
}

void	parse_params(char **op_arr, t_header *header, int o, char *champion)
{
	int		a;
	int		spg;
	t_op	*op;

	spg = header->prog_size;
	a = 0;
	op = get_op(op_arr[o++]);
	(ft_arrstrlen(&(op_arr[o])) != op->arg_len) ?
	print_error(ERR_ARG_LEN) : (op->ocp = get_ocp(op_arr, o));
	save_bytes(header, champion, &(op->op_code), 1);
	(op->print_ocp) ? save_bytes(header, champion, &(op->ocp), 1) : 0;
	while (op_arr[o])
	{
		if (op_arr[o][0] == 'r')
			!(op->args_type[a] % 2) ? print_error(ERR_ARG_TYPE)
			: parse_register(header, (char *[2]){op_arr[o], champion});
		else if (op_arr[o][0] == DIRECT_CHAR)
			!((op->args_type[a] >> 1) % 2) ? print_error(ERR_ARG_TYPE)
			: parse_direct(header, op, (char *[2]){op_arr[o], champion}, spg);
		else
			!((op->args_type[a] >> 2) % 2) ? print_error(ERR_ARG_TYPE)
			: parse_indirect(header, (char *[2]){op_arr[o], champion}, spg);
		o++;
		a++;
	}
}
