/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_uint32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:34:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/07 09:55:26 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_str_to_uint32(const char *s, uint32_t *result)
{
	*result = 0;
	while ('0' <= *s && *s <= '9')
	{
		if (!ft_uint32_mul(*result, 10, result)
			|| !ft_uint32_add(*result, *s - '0', result))
			return (NULL);
		s++;
	}
	return (s);
}
