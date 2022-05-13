/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:09:57 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 15:11:39 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rdres	ft_read_count(t_reader *r, char c, size_t *count)
{
	t_rdres	res;
	uint8_t	byte;

	*count = 0;
	while (1)
	{
		res = ft_read_byte(r, &byte);
		if (res == FT_RDRES_READ_ERROR)
			return (FT_RDRES_READ_ERROR);
		if (res == FT_RDRES_DONE)
			return (FT_RDRES_CONTINUE);
	}
	return (FT_RDRES_CONTINUE);
}
