/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_fmt_handle_i32.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:25:39 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/13 23:26:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__libft_fmt.h"

bool	__ft_fmt_handle_i32(t_writer w, va_list args)
{
	char	buf[11];
	char	*start;

	start = ft_iint32_to_str(
			va_arg(args, uint32_t),
			(t_str){"0123456789", 10}, buf + 11);
	return (w.write(w.self, start, 11 - (start - buf)));
}
