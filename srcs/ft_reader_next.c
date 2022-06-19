/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:09:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/06/19 15:15:30 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <unistd.h>

static bool	ft_reader_refill(t_reader *reader)
{
	ssize_t	count;

	count = read(reader->fd, reader->buf, READER_BUF_SIZE);
	if (count < 0)
		ft_unwind_panic("failed to read from fd `{int}`", reader->fd);
	reader->init = count;
	reader->consumed = 0;
	return (count != 0);
}

bool	ft_reader_next(t_reader *reader, uint8_t *byte)
{
	if (reader->consumed == reader->init && !ft_reader_refill(reader))
		return (false);
	*byte = reader->buf[reader->consumed];
	reader->consumed++;
	return (true);
}
