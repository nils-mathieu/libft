/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:33:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 20:35:25 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uint_len(unsigned int i, size_t base_len)
{
	size_t	len;

	if (i == 0)
		return (1);
	len = 0;
	while (i)
	{
		len++;
		i /= base_len;
	}
	return (len);
}
