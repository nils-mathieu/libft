/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:36:46 by nmathieu          #+#    #+#             */
/*   Updated: 2022/06/19 15:00:01 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"
#include <stdlib.h>

void	*ft_alloc(size_t count)
{
	void	*result;

	result = malloc(count);
	if (!result)
		ft_unwind_panic(FT_ERR_OUT_OF_MEMORY);
	return (result);
}
