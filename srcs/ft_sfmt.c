/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:30:21 by nmathieu          #+#    #+#             */
/*   Updated: 2022/08/02 09:09:29 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static bool	my_write(void *self, const void *data, size_t len)
{
	t_vec *const	vec = (t_vec *)self;

	ft_vec_append(vec, data, len, sizeof(char));
	return (true);
}

static void	my_va_end(va_list *args)
{
	va_end(*args);
}

char	*ft_sfmt_va(const char *format, va_list args)
{
	t_unwind	unwind_index;
	t_vec		vec;

	ft_mem_set(&vec, 0x00, sizeof(t_vec));
	unwind_index = ft_unwind(&vec, ft_vec_free_simple);
	ft_fmt_write_va((t_writer){&vec, my_write}, format, args);
	ft_unwind_defuse(unwind_index);
	ft_vec_reserve(&vec, 1, sizeof(char));
	((char *)vec.data)[vec.len++] = '\0';
	return (vec.data);
}

char	*ft_sfmt(const char *format, ...)
{
	t_unwind	unwind_index;
	va_list		args;
	char		*result;

	va_start(args, format);
	unwind_index = ft_unwind(&args, my_va_end);
	result = ft_sfmt_va(format, args);
	return (ft_unwind_to(unwind_index), result);
}
