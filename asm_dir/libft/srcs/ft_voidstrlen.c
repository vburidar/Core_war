/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidstrlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 03:03:47 by obenazzo          #+#    #+#             */
/*   Updated: 2016/09/07 03:04:11 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_voidstrlen(const void *str)
{
	int i;

	i = 0;
	while (((char *)str)[i] != '\0')
		i++;
	return (i);
}
