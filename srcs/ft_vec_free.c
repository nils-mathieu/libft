/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:18:10 by nmathieu          #+#    #+#             */
/*   Updated: 2022/06/11 14:19:35 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ms_vec_free(t_vec *vec, void (*free_el)(void *), size_t elem_size)
{
	if (vec->cap == 0)
		return ;
	while (vec->len--)
		free_el(vec->data + vec->len * elem_size);
	free(vec->data);
}
