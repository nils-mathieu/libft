/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint32_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:26:41 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 16:51:48 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_uint32_mul(uint32_t a, uint32_t b, uint32_t *result)
{
	if (a == 0 || b == 0)
		return (*result = 0, true);
	*result = a * b;
	return (*result / a == b);
}
