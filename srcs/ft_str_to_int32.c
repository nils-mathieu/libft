/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 11:07:12 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/18 21:20:09 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_str_to_int32(const char *s, int32_t *result)
{
	bool		neg;
	const char	*ret;

	neg = false;
	if (*s == '-')
		neg = (s++, true);
	else if (*s == '+')
		s++;
	ret = ft_str_to_uint32(s, (uint32_t *)result);
	if (!ret || (uint32_t)*result > (uint32_t)INT32_MIN)
		return (NULL);
	if (neg)
		*result = -*result;
	return (ret);
}
