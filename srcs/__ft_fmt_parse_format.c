/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_parse_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:22:08 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:09:58 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_internal.h"
#include <stdio.h>

#define FORMAT_HANDLER_COUNT 25

static const t_fmt_handler	g_handlers[FORMAT_HANDLER_COUNT] = {
	(t_fmt_handler){(t_str){"ullong", 6}, __ft_fmt_handle_ullong},
	(t_fmt_handler){(t_str){"ushort", 6}, __ft_fmt_handle_ushort},
	(t_fmt_handler){(t_str){"sbyte", 5}, __ft_fmt_handle_char},
	(t_fmt_handler){(t_str){"short", 5}, __ft_fmt_handle_short},
	(t_fmt_handler){(t_str){"llong", 5}, __ft_fmt_handle_llong},
	(t_fmt_handler){(t_str){"ulong", 5}, __ft_fmt_handle_ulong},
	(t_fmt_handler){(t_str){"long", 4}, __ft_fmt_handle_long},
	(t_fmt_handler){(t_str){"byte", 4}, __ft_fmt_handle_uchar},
	(t_fmt_handler){(t_str){"uint", 4}, __ft_fmt_handle_uint},
	(t_fmt_handler){(t_str){"str?", 4}, __ft_fmt_handle_debug_str},
	(t_fmt_handler){(t_str){"str", 3}, __ft_fmt_handle_str},
	(t_fmt_handler){(t_str){"u16", 3}, __ft_fmt_handle_uint16},
	(t_fmt_handler){(t_str){"i16", 3}, __ft_fmt_handle_int16},
	(t_fmt_handler){(t_str){"u32", 3}, __ft_fmt_handle_uint32},
	(t_fmt_handler){(t_str){"i32", 3}, __ft_fmt_handle_int32},
	(t_fmt_handler){(t_str){"u64", 3}, __ft_fmt_handle_uint64},
	(t_fmt_handler){(t_str){"i64", 3}, __ft_fmt_handle_int64},
	(t_fmt_handler){(t_str){"int", 3}, __ft_fmt_handle_int},
	(t_fmt_handler){(t_str){"i8", 2}, __ft_fmt_handle_int8},
	(t_fmt_handler){(t_str){"u8", 2}, __ft_fmt_handle_uint8},
	(t_fmt_handler){(t_str){"s?", 2}, __ft_fmt_handle_debug_string},
	(t_fmt_handler){(t_str){"c?", 2}, __ft_fmt_handle_debug_char},
	(t_fmt_handler){(t_str){"s", 1}, __ft_fmt_handle_string},
	(t_fmt_handler){(t_str){"c", 1}, __ft_fmt_handle_char2},
	(t_fmt_handler){(t_str){"b", 1}, __ft_fmt_handle_bool},
};

static bool	handle_format(t_writer w, const char **f, va_list args)
{
	size_t	i;

	i = 0;
	while (i < FORMAT_HANDLER_COUNT
		&& !ft_str_starts_with(*f, g_handlers[i].id.data))
		i++;
	if (i == FORMAT_HANDLER_COUNT)
		return (false);
	*f += g_handlers[i].id.len;
	if (**f != '}')
		return (false);
	(*f)++;
	return (g_handlers[i].format(w, args));
}

bool	__ft_fmt_parse_format(t_writer w, const char **f, va_list args)
{
	const char	*start;

	if (**f == '{')
	{
		(*f)++;
		if (**f == '{')
			return ((*f)++, w.write(w.self, "{", 1));
		return (handle_format(w, f, args));
	}
	start = *f;
	*f = ft_mem_find2_inf(*f, '\0', '{');
	return (w.write(w.self, start, *f - start));
}
