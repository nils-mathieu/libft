/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_uint32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:34:52 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/07 18:17:58 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_str_to_uint32(const char *s, uint32_t *result)
{
	*result = 0;
	while ('0' <= *s && *s <= '9')
	{
		if (*result > UINT32_MAX / 10)
			return (NULL);
		*result *= 10;
		if (*result > UINT32_MAX - (*s - '0'))
			return (NULL);
		*result += *s - '0';
		s++;
	}
	return (s);
}