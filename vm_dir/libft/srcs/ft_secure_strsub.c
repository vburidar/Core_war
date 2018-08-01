/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_strsub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:17:21 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/19 13:03:45 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_secure_strsub(char *s, int start, int compteur)
{
	char *del;

	del = s;
	s = ft_strsub(s, start, compteur);
	free(del);
	return (s);
}
