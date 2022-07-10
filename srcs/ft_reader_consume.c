/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_consume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:54:08 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 13:57:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reader_consume(t_reader *reader, size_t count)
{
	ft_assert(
		reader->con + count <= reader->cur,
		"tried to consume more bytes than possible");
	reader->con += count;
	if (reader->con < reader->init)
		return ;
	reader->init = 0;
	reader->cur = 0;
	reader->con = 0;
}
