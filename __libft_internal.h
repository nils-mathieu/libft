/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __libft_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:13:41 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/20 12:27:22 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_INTERNAL_H
# define __LIBFT_INTERNAL_H

# include "libft.h"

typedef bool	(*t_handle_format_fn)(t_writer w, va_list args);

// Describes a format handler. `id` is used to identify which function pointer
// will be called to handle the next argument.
typedef struct s_format_handler
{
	t_str				id;
	t_handle_format_fn	format;
}	t_fmt_handler;

bool	__ft_fmt_parse_format(t_writer w, const char **f, va_list args);

// The following function are responsible for handling type formatting
// using the `ft_fmt_*` functions.

bool	__ft_fmt_handle_uint8(t_writer w, va_list args);
bool	__ft_fmt_handle_int8(t_writer w, va_list args);
bool	__ft_fmt_handle_uint16(t_writer w, va_list args);
bool	__ft_fmt_handle_int16(t_writer w, va_list args);
bool	__ft_fmt_handle_uint32(t_writer w, va_list args);
bool	__ft_fmt_handle_int32(t_writer w, va_list args);
bool	__ft_fmt_handle_uint64(t_writer w, va_list args);
bool	__ft_fmt_handle_int64(t_writer w, va_list args);
bool	__ft_fmt_handle_byte(t_writer w, va_list args);
bool	__ft_fmt_handle_sbyte(t_writer w, va_list args);
bool	__ft_fmt_handle_short(t_writer w, va_list args);
bool	__ft_fmt_handle_ushort(t_writer w, va_list args);
bool	__ft_fmt_handle_int(t_writer w, va_list args);
bool	__ft_fmt_handle_uint(t_writer w, va_list args);
bool	__ft_fmt_handle_long(t_writer w, va_list args);
bool	__ft_fmt_handle_ulong(t_writer w, va_list args);
bool	__ft_fmt_handle_llong(t_writer w, va_list args);
bool	__ft_fmt_handle_ullong(t_writer w, va_list args);
bool	__ft_fmt_handle_char(t_writer w, va_list args);
bool	__ft_fmt_handle_debug_char(t_writer w, va_list args);
bool	__ft_fmt_handle_debug_string(t_writer w, va_list args);
bool	__ft_fmt_handle_string(t_writer w, va_list args);
bool	__ft_fmt_handle_bool(t_writer w, va_list args);

#endif
