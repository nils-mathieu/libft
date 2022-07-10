/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:49:31 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:05:36 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "__libft_internal.h"

bool	__ft_fmt_handle_str(t_writer w, va_list args)
{
	t_str	s;

	s = va_arg(args, t_str);
	return (w.write(w.self, (void *)s.data, s.len));
}

static size_t	next_escaped(t_str s, t_str *escaped)
{
	uint32_t	state;
	uint32_t	codep;
	size_t		i;

	state = 0;
	i = 0;
	while (i < s.len)
	{
		state = ft_utf8_decode(state, &codep, s.data[i]);
		if (state == 1)
		{
			*escaped = (t_str){"\ufffd", 3};
			break ;
		}
		if (state == 0)
		{
			*escaped = __ft_fmt_escape_codep(codep);
			if (escaped->len != 0)
				break ;
		}
		i++;
	}
	return (i);
}

bool	__ft_fmt_handle_debug_str(t_writer w, va_list args)
{
	t_str		s;
	size_t		count;
	t_str		escaped;

	s = va_arg(args, t_str);
	while (true)
	{
		count = next_escaped(s, &escaped);
		if (count == s.len)
			break ;
		if (!w.write(w.self, s.data, count)
			|| !w.write(w.self, escaped.data, escaped.len))
			return (false);
		s.data += count;
		s.len -= count;
	}
	return (w.write(w.self, s.data, s.len));
}
