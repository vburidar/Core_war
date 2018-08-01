/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:53:49 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/17 17:00:57 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

t_proc	*ft_del(t_proc *lst_proc)
{
	t_proc		*curseur;
	void		*workaround;

	lst_proc->corewar->nb_proc--;
	curseur = lst_proc;
	while (curseur->nxt->id != lst_proc->id)
		curseur = curseur->nxt;
	if (curseur == lst_proc)
	{
		pr_free(lst_proc->ins);
		pr_free(lst_proc);
		return (NULL);
	}
	workaround = lst_proc->nxt;
	if (curseur->nxt)
	{
		pr_free(curseur->nxt->ins);
		pr_free(curseur->nxt);
	}
	curseur->nxt = workaround;
	return (curseur->nxt);
}
