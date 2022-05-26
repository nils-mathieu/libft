/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:19:40 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 18:37:38 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_alloc_array(size_t count, size_t size)
{
	if (size != 0 && count > SIZE_MAX / size)
		ft_unwind_panic("the system is out of memory");
	return (ft_alloc(size * count));
}
