/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/05 20:41:10 by nmathieu         ###   ########.fr       */
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

// Tries to put the result of `a + b` into `result`. The function returns
// whether overflow did not occur.
bool		ft_size_add(size_t a, size_t b, size_t *result);

// Tries to put the result of `a * b` into `result`. The function returns
// whether overflow did not occur.
bool		ft_size_mul(size_t a, size_t b, size_t *result);

// ========================================================================== //
//                                   Math                                     //
// ========================================================================== //

int			ft_uint_abs(int i);

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

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

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

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_uint32_to_str(uint32_t i, t_str base, char *buf_end);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_size_to_str(size_t i, t_str base, char *buf_end);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_uint_to_str(unsigned int i, t_str base, char *buf_end);

// Returns the number of bytes required to print `i` in a base of the provided
// length.
size_t		ft_uint_len(unsigned int i, size_t base_len);

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
const void	*ft_mem_find2_inf(const void *p, uint8_t b0, uint8_t b1);

// ========================================================================== //
//                               Input/Output                                 //
// ========================================================================== //

// Writes `data` to the provided file descriptor. Returns whether no error
// occured.
bool		ft_write_all(int fd, const void *data, size_t to_write);

#endif
