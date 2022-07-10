/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_refill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:09:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:51:37 by nmathieu         ###   ########.fr       */
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
