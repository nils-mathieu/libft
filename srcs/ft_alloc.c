/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:36:46 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 22:10:15 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"
#include <stdlib.h>

void	*ft_alloc(size_t count)
{
	void	*result;

	ft_assert(count, "cowardly refusing to allocate a zero sized block");
	result = malloc(count);
	if (!result)
		ft_unwind_panic("the system is out of memory");
	return (result);
}
