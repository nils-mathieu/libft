/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:11:37 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 14:13:49 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_reader_init(t_reader *reader, int fd)
{
	ft_mem_set(reader, 0x00, sizeof(t_reader));
	reader->fd = fd;
}

void	ft_reader_deinit(t_reader *reader)
{
	if (reader->cap)
		free(reader->data);
}
