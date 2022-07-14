/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_escape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:45:51 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/14 12:50:31 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_str	g_escapes[32] = {
{"\\0", 2}, {0}, {0}, {0}, {0}, {0}, {0}, {"\\a", 2}, {"\\b", 2},
{"\\t", 2}, {"\\n", 2}, {"\\v", 2}, {"\\f", 2}, {"\\r", 2}, {0}, {0}, {0},
{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0},
};

t_str	__ft_fmt_escape_codep(uint32_t codep)
{
	if (codep < 32)
	{
		if (g_escapes[codep].len == 0)
			return ((t_str){"\ufffd", 3});
		else
			return (g_escapes[codep]);
	}
	else
	{
		return ((t_str){NULL, 0});
	}
}

t_str	__ft_fmt_escape_ascii(char c)
{
	if (c < 0)
	{
		return ((t_str){"\ufffd", 3});
	}
	else if (c < 32)
	{
		if (g_escapes[(unsigned char)c].len == 0)
			return ((t_str){"\ufffd", 3});
		else
			return (g_escapes[(unsigned char)c]);
	}
	else if (c == '\\')
		return ((t_str){"\\\\", 2});
	else
		return ((t_str){NULL, 0});
}
