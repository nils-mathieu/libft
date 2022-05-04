/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_uint32_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:10:44 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/04 17:39:04 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

const char	*ft_str_to_uint32_base(const char *s, t_str base, uint32_t *result)
{
	const char	*index;

	*result = 0;
	while (true)
	{
		index = ft_mem_find(base.data, *s, base.len);
		if (!index)
			break ;
		if (!ft_uint32_mul(*result, base.len, result))
			*result = UINT32_MAX;
		if (!ft_uint32_add(*result, index - base.data, result))
			*result = UINT32_MAX;
		s++;
	}
	return (s);
}
