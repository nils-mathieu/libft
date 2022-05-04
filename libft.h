/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/04 17:36:54 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

// ========================================================================== //
//                                Operations                                  //
// ========================================================================== //

// Tries to put the result of `a + b` into `result`. The function returns
// whether overflow did not occur.
bool		ft_uint32_add(uint32_t a, uint32_t b, uint32_t *result);

// Tries to put the result of `a * b` into `result`. The function returns
// whether overflow did not occur.
bool		ft_uint32_mul(uint32_t a, uint32_t b, uint32_t *result);

// ========================================================================== //
//                                 Strings                                    //
// ========================================================================== //

// A string that knows its length.
//
// Note that the `data` pointer may or may not be null termiated.
typedef struct s_str
{
	const char	*data;
	size_t		len;
}	t_str;

// Returns the length of the provided string (not including the terminating null
// character.
size_t		ft_str_len(const char *s);

// Returns a pointer to the first character `c` within `s`. If the character
// is not in `s`, `NULL` is returned.
const char	*ft_str_find(const char *s, char c);

// Converts the begining of the provided string into an `uint32_t`.
//
// On success, this function returns a pointer to the first character that
// wasn't parsed. On failure, `NULL` is returned.
//
// This function saturates on overflow.
const char	*ft_str_to_uint32_base(const char *s, t_str base, uint32_t *result);

// Converts the begining of the provided string into an `uint32_t`.
//
// On success, this function returns a pointer to the first character that
// wasn't parsed. On failure, `NULL` is returned.
//
// This function saturates on overflow.
const char	*ft_str_to_uint32(const char *s, uint32_t *result);

// ========================================================================== //
//                                 Memory                                     //
// ========================================================================== //

// Returns a pointer to the first byte `b` within `p`. If the byte is not in
// `p`, `NULL` is returned.
const void	*ft_mem_find(const void *p, uint8_t b, size_t max);

// Returns a pointer to the first byte `b` within `p`.
const void	*ft_mem_find_inf(const void *p, uint8_t b);

// Returns a pointer to the first byte `b0` or `b1` within `p`. If none of those
// bytes are found in `p`, `NULL` is returned.
const void	*ft_mem_find2(const void *p, uint8_t c0, uint8_t c1, size_t max);

// Returns a pointer to the first byte `b0` or `b1` within `p`.
const void	*ft_mem_find2_inf(const void *p, uint8_t b);

#endif
