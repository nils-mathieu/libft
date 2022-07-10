/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_peek.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:09:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 13:53:44 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <unistd.h>

#define MIN_READ_SIZE 1024

static bool	ft_reader_refill(t_reader *r)
{
	ssize_t	ret;

	ft_reader_reserve(r, MIN_READ_SIZE);
	ret = read(r->fd, r->data + r->init, r->cap - r->init);
	if (ret < -1)
		ft_unwind_panic("failed to read data from fd `{int}`", r->fd);
	if (ret == 0)
		return (false);
	r->init += ret;
	return (true);
}

bool	ft_reader_peek(t_reader *reader, uint8_t *byte)
{
	if (reader->cur == reader->init && !ft_reader_refill(reader))
		return (false);
	*byte = reader->data[reader->cur];
	return (true);
}
