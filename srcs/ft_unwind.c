/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unwind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:04:45 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 18:48:00 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"
#include <stdlib.h>

static t_unwind_stack	g_stack;

static bool	grow_stack(void)
{
	t_unwind_destructor	*new_buf;

	if (g_stack.cap > SIZE_MAX / 2 / sizeof(t_unwind_destructor) - 2)
		return (false);
	new_buf = malloc((g_stack.cap + 2) * 2 * sizeof(t_unwind_destructor));
	if (!new_buf)
		return (false);
	if (g_stack.cap != 0)
	{
		ft_mem_copy(
			new_buf,
			g_stack.buf,
			g_stack.len * sizeof(t_unwind_destructor));
		free(g_stack.buf);
	}
	g_stack.buf = new_buf;
	g_stack.cap = (g_stack.cap + 2) * 2;
	return (true);
}

size_t	ft_unwind(void *data, t_free_fn destructor)
{
	if (g_stack.len == g_stack.cap && !grow_stack())
	{
		(*destructor)(data);
		ft_unwind_panic("the system is out of memory\n");
	}
	g_stack.buf[g_stack.len].data = data;
	g_stack.buf[g_stack.len].destructor = destructor;
	return (g_stack.len++);
}

void	ft_unwind_to(size_t to)
{
	while (g_stack.len > to)
	{
		g_stack.len--;
		(*g_stack.buf[g_stack.len].destructor)(g_stack.buf[g_stack.len].data);
	}
	if (g_stack.len == 0 && g_stack.cap != 0)
	{
		g_stack.cap = 0;
		free(g_stack.buf);
	}
}
