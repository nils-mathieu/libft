/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:32:16 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/24 19:33:59 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vec_append(t_vec *vec, const void *data, size_t n, size_t es)
{
	ft_vec_reserve(vec, n, es);
	ft_mem_copy(vec->data, data, n * es);
	vec->len += n;
}
