/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_char2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:30:43 by nmathieu          #+#    #+#             */
/*   Updated: 2022/06/21 01:50:42 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_internal.h"
#include <stdio.h>

bool	__ft_fmt_handle_char2(t_writer w, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (w.write(w.self, &c, 1));
}

bool	__ft_fmt_handle_debug_char(t_writer w, va_list args)
{
	const char	c = (char)va_arg(args, int);
	const t_str	escaped = __ft_fmt_escape_ascii((unsigned char)c);

	if (escaped.len == 0)
		return (w.write(w.self, &c, 1));
	else
		return (w.write(w.self, escaped.data, escaped.len));
}
