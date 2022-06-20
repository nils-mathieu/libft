/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:11:37 by nmathieu          #+#    #+#             */
/*   Updated: 2022/06/21 01:12:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reader_init(t_reader *reader, int fd)
{
	ft_mem_set(reader, 0x00, sizeof(t_reader));
	reader->fd = fd;
}
