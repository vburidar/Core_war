/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:56:03 by vburidar          #+#    #+#             */
/*   Updated: 2018/03/22 02:34:39 by rthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include "../includes/op.h"

uint32_t		swap_int32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

t_header		ft_get_header(int fd)
{
	t_header		header;
	unsigned int	test;

	test = 0;
	read(fd, &(header), sizeof(t_header));
	header.magic = swap_int32(header.magic);
	header.prog_size = swap_int32(header.prog_size);
	return (header);
}

void			ft_ncpy(unsigned char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (src[i] < 0)
			dest[i] = src[i] + 256;
		else
			dest[i] = src[i];
		i++;
	}
}

t_champ			ft_get_champ(char *filename, t_corewar *corewar)
{
	int		fd;
	t_champ	champ;
	char	code[CHAMP_MAX_SIZE];
	int		val_read;

	ft_bzero(&champ, sizeof(t_champ));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_end("No such file", 6, filename);
	else if ((ft_strlen(filename) < 5) || \
	(!ft_strequ(&filename[ft_strlen(filename) - 4], ".cor")))
		error_end("Not a .cor file", 2, filename);
	ft_valid_champ(fd, filename);
	champ.header = ft_get_header(fd);
	val_read = read(fd, &code, champ.header.prog_size);
	if (corewar->select == 1)
		champ.rank = corewar->n_rank;
	else
		champ.rank = corewar->a_rank++;
	corewar->select = 0;
	if (!(champ.code = pr_malloc(champ.header.prog_size * sizeof(char))))
		exit(1);
	ft_ncpy(champ.code, code, champ.header.prog_size);
	return (champ);
}
