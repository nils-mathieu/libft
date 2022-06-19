/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:10:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/06/19 16:24:15 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_internal.h"
#include "libft.h"

bool	__ft_fmt_handle_string(t_writer w, va_list args)
{
	const char	*s;

	s = va_arg(args, const char *);
	return (w.write(w.self, (void *)s, ft_str_len(s)));
}

static const char	*next_escaped(const char *s, t_str *escaped)
{
	uint32_t	state;
	uint32_t	codep;

	state = 0;
	while (true)
	{
		state = ft_utf8_decode(state, &codep, *s);
		if (state == 1)
		{
			*escaped = (t_str){"\ufffd", 3};
			return (s);
		}
		if (state == 0)
		{
			*escaped = __ft_fmt_escape_codep(codep);
			if (escaped->len != 0)
				return (s);
		}
		if (*s == '\0')
			return (s);
		s++;
	}
}

bool	__ft_fmt_handle_debug_string(t_writer w, va_list args)
{
	const char	*s;
	const char	*t;
	t_str		escaped;

	s = va_arg(args, const char *);
	while (true)
	{
		t = next_escaped(s, &escaped);
		if (!*t)
			break ;
		if (!w.write(w.self, s, t - s)
			|| !w.write(w.self, escaped.data, escaped.len))
			return (false);
		s = t;
	}
	return (w.write(w.self, s, t - s));
}
