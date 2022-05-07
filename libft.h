/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/07 17:29:42 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>

// ========================================================================== //
//                                   Math                                     //
// ========================================================================== //

// Returns the absolute value of `i`.
//
// If `i` is `UINT_MIN`, it is itself returned.
int			ft_uint_abs(int i);

// Returns the max of `a` and `b`.
size_t		ft_size_max(size_t a, size_t b);

// Returns the min of `a` and `b`.
size_t		ft_size_min(size_t a, size_t b);

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

// Returns the length of the provided string (not including the terminating null
// character).
//
// Only up to `n` characters are checked. The return value of this function is
// min(len(s), n).
size_t		ft_str_nlen(const char *s, size_t n);

// Returns a pointer to the first character `c` within `s`. If the character
// is not in `s`, `NULL` is returned.
const char	*ft_str_find(const char *s, char c);

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

// Converts the begining of the provided string into an `uint32_t`.
//
// On success, this function returns a pointer to the first character that
// wasn't parsed. On overflow, `NULL` is returned and `result` is left
// unspecified.
const char	*ft_str_to_uint32(const char *s, uint32_t *result);

// Converts the begining of the provided string into an `int32_t`.
//
// This function accepts a leading `+` or `-` to indicate the sign of the
// output number.
//
// On success, this function returns a pointer to the first character that
// wasn't parsed. On overflow, `NULL` is returned and `result` is left
// unspecified.
const char	*ft_str_to_int32(const char *s, int32_t *result);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_uint32_to_str(uint32_t i, t_str base, char *buf_end);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_size_to_str(size_t i, t_str base, char *buf_end);

// Writes `i` in the provided base. The number is written from the end of the
// `buf_end` pointer. A pointer to the first character is returned.
char		*ft_uint_to_str(unsigned int i, t_str base, char *buf_end);

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

// Copies `n` bytes from `src` to `dst`. Areas must not overlap.
void		ft_mem_copy(void *dst, const void *src, size_t n);

// Fills `dst` with the provided `byte`.
void		ft_mem_set(void *dst, uint8_t byte, size_t n);

// ========================================================================== //
//                               Input/Output                                 //
// ========================================================================== //

// A partially uninitialized buffer.
typedef struct s_buffer
{
	void	*data;
	size_t	init;
	size_t	cap;
}	t_buffer;

// Writes `data` to the provided file descriptor. Returns whether no error
// occured.
bool		ft_write_all(int fd, const void *data, size_t to_write);

// Writes bytes into `buf`, writting everything to the provided file descriptor
// once it is full.
//
// Returns whether the operation is successful.
bool		ft_write_buffered(int fd, t_buffer *buf, const void *p, size_t n);

// Writes `n` times the bytes pointed by `data` to the provided file
// descriptor.
//
// Returns whether the operation was successful.
bool		ft_write_repeat(int fd, const void *data, size_t len, size_t n);

// Writes the provided byte `n` times. Returns whether the operation is
// successful.
bool		ft_write_repeat_one(int fd, uint8_t b, size_t n);

// ========================================================================== //
//                                   System                                   //
// ========================================================================== //

/// Allocates `count * size` bytes. This function fails on overflow.
void		*ft_alloc_array(size_t count, size_t size);

#endif
