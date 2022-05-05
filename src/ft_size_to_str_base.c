/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_to_str_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:51:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 11:51:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_size_to_str_base(size_t i, t_str base, char *buf_end)
{
	while (i)
	{
		buf_end--;
		*buf_end = base.data[i % base.len];
		i /= base.len;
	}
	return (buf_end);
}
