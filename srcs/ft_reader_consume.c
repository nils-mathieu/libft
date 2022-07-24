/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_consume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:54:08 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/24 19:28:16 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_reader_consume(t_reader *reader, size_t count)
{
	if (reader->con + count <= reader->init)
	{
		reader->con += count;
		if (reader->con != reader->init)
			return (true);
		reader->init = 0;
		reader->con = 0;
		return (true);
	}
	else
	{
		count -= reader->init - reader->con;
		reader->con = 0;
		reader->init = 0;
		if (!ft_reader_refill(reader, count))
			return (false);
		if (reader->init == count)
		{
			reader->init = 0;
			return (true);
		}
		reader->con = count;
		return (true);
	}
}
