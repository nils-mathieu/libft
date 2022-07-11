/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:14:06 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/11 11:10:44 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vec_reserve(t_vec *vec, size_t additional, size_t elem_size)
{
	size_t	amortized;

	if (additional > SIZE_MAX - vec->len)
		ft_unwind_panic("the system is out of memory\n");
	additional += vec->len;
	if (additional <= vec->cap)
		return ;
	if (vec->cap > (SIZE_MAX - 4) / 2)
		amortized = SIZE_MAX;
	else
		amortized = vec->cap * 2 + 4;
	ft_vec_realloc(vec, ft_size_max(amortized, additional), elem_size);
}
