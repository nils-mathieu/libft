/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_reader_refill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:12:34 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:12:30 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

t_rdres	__ft_reader_refill(t_reader *reader)
{
	ssize_t	count;

	count = read(reader->fd, reader->buf.data, reader->buf.cap);
	if (count < 0)
		return (FT_RDRES_READ_ERROR);
	if (count == 0)
		return (FT_RDRES_DONE);
	reader->buf.init = (size_t)count;
	reader->cur = 0;
	return (FT_RDRES_CONTINUE);
}
