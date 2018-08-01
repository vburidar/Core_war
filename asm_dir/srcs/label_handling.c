/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*get_label(char *champion, char *name, int type)
{
	return (add_label(champion, name, (int[3]){-1, type, -1}, -1));
}

t_label		*new_label(char *name, int location, int spg, int d2)
{
	t_label	*temp;

	temp = pr_malloc(sizeof(t_label));
	temp->location = location;
	temp->spg = spg;
	temp->d2 = d2;
	temp->name = pr_malloc(ft_strlen(name) + 1);
	ft_strcpy(temp->name, name);
	return (temp);
}

t_label		*replace_labels(t_labels *labels, char *code)
{
	t_list			*rep;
	t_label			*sav;
	int				z;
	short			y;

	if (!(rep = labels->to_replace))
		return (0);
	while (rep)
	{
		if (!(sav = add_label(code, ((t_label *)(rep->content))->name,
		(int[3]){-1, 0, -1}, -1)))
			print_error("label not found\n");
		if (((t_label *)(rep->content))->d2)
		{
			y = endian_swap_16(sav->spg - ((t_label *)(rep->content))->spg);
			ft_memcpy(code + ((t_label *)(rep->DATA))->location, &y, SZ(short));
		}
		else
		{
			z = endian_swap_32(sav->spg - ((t_label *)(rep->content))->spg);
			ft_memcpy(code + ((t_label *)(rep->DATA))->location, &z, SZ(int));
		}
		rep = rep->next;
	}
	return (0);
}

t_label		*find_label(char *name, t_labels *labels, int loc_type_st[3])
{
	t_list	*temp;

	temp = (loc_type_st[1] ? (labels->to_replace) : (labels->saved));
	while (temp)
	{
		if (!ft_strcmp(name, ((t_label *)(temp->content))->name))
			return (temp->content);
		temp = temp->next;
	}
	return (0);
}

t_label		*add_label(char *champion, char *name, int loc_type_st[3], int d2)
{
	static t_labels	labels = {0, 0};
	t_list			*temp;
	t_label			*label;

	if (name == (char *)-1 && loc_type_st[0] == -1 && loc_type_st[1] == -1)
		return (replace_labels(&labels, champion));
	valid_label(name);
	if (loc_type_st[0] == -1)
		return (find_label(name, &labels, loc_type_st));
	else if (loc_type_st[1] || !add_label(champion, name,
		(int[3]){-1, loc_type_st[1], -1}, -1))
	{
		label = new_label(name, loc_type_st[0], loc_type_st[2], d2);
		temp = pr_malloc(sizeof(t_list));
		temp->content = label;
		temp->next = (loc_type_st[1] ? (labels.to_replace) : (labels.saved));
		loc_type_st[1] ? (labels.to_replace = temp)
		: (labels.saved = temp);
		return (temp->content);
	}
	return (0);
}
