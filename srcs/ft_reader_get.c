/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:09:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/24 19:29:40 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <unistd.h>

bool	ft_reader_refill(t_reader *r, size_t min_read_size)
{
	ssize_t	ret;

	ft_reader_reserve(r, min_read_size);
	ret = read(r->fd, r->data + r->init, r->cap - r->init);
	if (ret < -1)
		ft_unwind_panic("failed to read data from fd `{int}`", r->fd);
	if (ret == 0)
		return (false);
	r->init += ret;
	return (true);
}

bool	ft_reader_get(t_reader *reader, size_t index, uint8_t *byte)
{
	const size_t	i = index + reader->con;

	ft_assert(i <= reader->init, "index {ulong} is out of bound", index);
	if (i == reader->init && !ft_reader_refill(reader, 1024))
		return (false);
	*byte = reader->data[i];
	return (true);
}

uint8_t	ft_reader_aget(t_reader *reader, size_t index)
{
	uint8_t	byte;

	if (!ft_reader_get(reader, index, &byte))
		ft_unwind_panic("unexpected end of file");
	return (byte);
}
