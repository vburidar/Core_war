/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:12:08 by rthys             #+#    #+#             */
/*   Updated: 2018/03/21 17:11:02 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

static void			check_magic(unsigned char *buff, char *filename)
{
	if ((buff[0] != (unsigned char)(COREWAR_EXEC_MAGIC >> 24)) || \
	(buff[1] != (unsigned char)((COREWAR_EXEC_MAGIC & 16711680) >> 16)) || \
	(buff[2] != (unsigned char)((COREWAR_EXEC_MAGIC & 65280) >> 8)) || \
	(buff[3] != (unsigned char)((COREWAR_EXEC_MAGIC & 255))))
		error_end("Wrong magic number", 6, filename);
}

static unsigned int	champ_size(int fd, unsigned char *buff, char *filename)
{
	int				ret;
	int				i;
	unsigned int	size;

	i = 0;
	size = 0;
	read(fd, buff, 3);
	ret = read(fd, buff, 4);
	while (i < 4)
	{
		size <<= 8;
		size += buff[i];
		i++;
	}
	if (size > CHAMP_MAX_SIZE + 1)
		error_end("Champion's size is too big", 9, filename);
	return (size);
}

static void			actual_size(int fd, char *filename, unsigned int size)
{
	off_t a_size;
	off_t cur_pos;

	lseek(fd, 3, SEEK_CUR);
	cur_pos = lseek(fd, 0, SEEK_CUR);
	a_size = (lseek(fd, 0, SEEK_END)) - cur_pos;
	if (a_size != size)
		error_end("Size indicated in header is not accurate", 10, filename);
	else if (a_size == 0)
		error_end("No code in champion", 11, filename);
}

void				ft_valid_champ(int fd, char *filename)
{
	unsigned char	buff[MEM_SIZE];
	unsigned int	size;
	int				i;

	i = 0;
	read(fd, buff, 4);
	check_magic(buff, filename);
	lseek(fd, PROG_NAME_LENGTH + 1, SEEK_CUR);
	size = champ_size(fd, buff, filename);
	lseek(fd, COMMENT_LENGTH + 1, SEEK_CUR);
	actual_size(fd, filename, size);
	lseek(fd, 0, SEEK_SET);
}
