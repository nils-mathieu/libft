/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:40:01 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 16:39:23 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uint_to_str(unsigned int i, t_str base, char *buf_end)
{
	while (i)
	{
		buf_end--;
		*buf_end = base.data[i % base.len];
		i /= base.len;
	}
	return (buf_end);
}
