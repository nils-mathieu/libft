/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_minmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:49:54 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/22 08:52:52 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	ft_size_max(size_t a, size_t b)
{
	if (a < b)
		return (b);
	else
		return (a);
}
