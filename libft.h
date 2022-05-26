/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/05/26 18:36:35 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

// ========================================================================== //
//                                   Math                                     //
// ========================================================================== //

typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef long long			t_llong;
typedef unsigned long long	t_ullong;

int8_t		ft_int8_min(int8_t a, int8_t b);
int16_t		ft_int16_min(int16_t a, int16_t b);
int32_t		ft_int32_min(int32_t a, int32_t b);
int64_t		ft_int64_min(int64_t a, int64_t b);
char		ft_char_min(char a, char b);
short		ft_short_min(short a, short b);
int			ft_int_min(int a, int b);
long		ft_long_min(long a, long b);
t_llong		ft_llong_min(t_llong a, t_llong b);

int8_t		ft_int8_max(int8_t a, int8_t b);
int16_t		ft_int16_max(int16_t a, int16_t b);
int32_t		ft_int32_max(int32_t a, int32_t b);
int64_t		ft_int64_max(int64_t a, int64_t b);
char		ft_char_max(char a, char b);
short		ft_short_max(short a, short b);
int			ft_int_max(int a, int b);
long		ft_long_max(long a, long b);
t_llong		ft_llong_max(t_llong a, t_llong b);

uint8_t		ft_uint8_max(uint8_t a, uint8_t b);
uint16_t	ft_uint16_max(uint16_t a, uint16_t b);
uint32_t	ft_uint32_max(uint32_t a, uint32_t b);
uint64_t	ft_uint64_max(uint64_t a, uint64_t b);
t_uchar		ft_uchar_max(t_uchar a, t_uchar b);
t_ushort	ft_ushort_max(t_ushort a, t_ushort b);
t_uint		ft_uint_max(t_uint a, t_uint b);
t_ulong		ft_ulong_max(t_ulong a, t_ulong b);
t_ullong	ft_ullong_max(t_ullong a, t_ullong b);

uint8_t		ft_uint8_min(uint8_t a, uint8_t b);
uint16_t	ft_uint16_min(uint16_t a, uint16_t b);
uint32_t	ft_uint32_min(uint32_t a, uint32_t b);
uint64_t	ft_uint64_min(uint64_t a, uint64_t b);
t_uchar		ft_uchar_min(t_uchar a, t_uchar b);
t_ushort	ft_ushort_min(t_ushort a, t_ushort b);
t_uint		ft_uint_min(t_uint a, t_uint b);
t_ulong		ft_ulong_min(t_ulong a, t_ulong b);
t_ullong	ft_ullong_min(t_ullong a, t_ullong b);

int8_t		ft_int8_abs(int8_t a);
int16_t		ft_int16_abs(int16_t a);
int32_t		ft_int32_abs(int32_t a);
int64_t		ft_int64_abs(int64_t a);
char		ft_char_abs(char a);
short		ft_short_abs(short a);
int			ft_int_abs(int a);
long		ft_long_abs(long a);
t_llong		ft_llong_abs(t_llong a);

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

/// Compares `a` and `b`.
//
// If `a` comes befores `b`, a negative value is returned. If it comes after, a
// positive value is returned. If they are equal, `0` is returned.
int			ft_str_cmp(const char *a, const char *b);

// Returns a pointer to the first character `c` within `s`. If the character
// is not in `s`, `NULL` is returned.
const char	*ft_str_find(const char *s, char c);

// Returns a pointer to the first character `c`, starting from the end of `s`.
// If the character isn't found, `NULL` is returned.
const char	*ft_str_rfind(const char *s, char c);

// Determines whether `needle` can be found at the start of `s`.
bool		ft_str_starts_with(const char *s, const char *needle);

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

// The following function all have the same behaviour:
//
// They convert the begining of the string they are provided into a specific
// integer type (specified in their name).
//
// On error (overflow), those functions return `NULL`. On success, a pointer to
// the first non-parsed character is returned.

const char	*ft_str_to_uint8(const char *s, uint8_t *result);
const char	*ft_str_to_int8(const char *s, int8_t *result);
const char	*ft_str_to_uint16(const char *s, uint16_t *result);
const char	*ft_str_to_int16(const char *s, int16_t *result);
const char	*ft_str_to_uint32(const char *s, uint32_t *result);
const char	*ft_str_to_int32(const char *s, int32_t *result);
const char	*ft_str_to_uint64(const char *s, uint64_t *result);
const char	*ft_str_to_int64(const char *s, int64_t *result);
const char	*ft_str_to_char(const char *s, char *result);
const char	*ft_str_to_uchar(const char *s, unsigned char *result);
const char	*ft_str_to_short(const char *s, short *result);
const char	*ft_str_to_ushort(const char *s, unsigned short *result);
const char	*ft_str_to_int(const char *s, int *result);
const char	*ft_str_to_uint(const char *s, unsigned int *result);
const char	*ft_str_to_long(const char *s, long *result);
const char	*ft_str_to_ulong(const char *s, unsigned long *result);
const char	*ft_str_to_llong(const char *s, long long *result);
const char	*ft_str_to_ullong(const char *s, unsigned long long *result);

// The following function will all have the same behaviour:
//
// They convert an integer into a collection of characters. Characters are
// written from the `buf_end` pointer in reverse (not included, so the first
// character is actually written to `buf_end - 1`).
//
// A pointer to the first character of the generated text is returned. Note that
// no null-terminating character is added.
//
// The number is written in the given base.

char		*ft_uint8_to_str(uint8_t nb, t_str base, char *buf_end);
char		*ft_uint16_to_str(uint16_t nb, t_str base, char *buf_end);
char		*ft_uint32_to_str(uint32_t nb, t_str base, char *buf_end);
char		*ft_uint64_to_str(uint64_t nb, t_str base, char *buf_end);
char		*ft_uchar_to_str(unsigned char nb, t_str base, char *buf_end);
char		*ft_ushort_to_str(unsigned short nb, t_str base, char *buf_end);
char		*ft_uint_to_str(unsigned int nb, t_str base, char *buf_end);
char		*ft_ulong_to_str(unsigned long nb, t_str base, char *buf_end);
char		*ft_ullong_to_str(unsigned long long nb, t_str base, char *buf_end);

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

// The result type of most read operations.
//
// `FT_RDRES_INCOMPLETE` - The operation is a success but there is still more
// data to be flushed.
//
// `FT_RDRSLT_DONE` - There is no more data to flush.
//
// `FT_RDRSLT_READ_ERROR` - An error occured whislt reading.
typedef enum e_read_result
{
	FT_RDRES_INCOMPLETE = 1,
	FT_RDRES_DONE = 0,
	FT_RDRES_ERROR = -1,
}	t_rdres;

// A buffered reader.
typedef struct s_reader
{
	int			fd;
	t_buffer	buf;
	size_t		cur;
}	t_reader;

// Refills the internal buffer of a `reader` regardless of its current state.
t_rdres		ft_reader_refill(t_reader *reader);

// Reads a single byte from the provided `reader_t` instance.
t_rdres		ft_read_byte(t_reader *reader, uint8_t *byte);

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

// A function that may be used to write the first `count` bytes referenced
// by `to_write`.
typedef bool				(*t_writer_fn)(void *s, void *w, size_t l);

// Describes a way to write data somewhere.
typedef struct s_writer
{
	void		*self;
	t_writer_fn	write;
}	t_writer;

// Formats the provided string and writes it using the provided `t_writer`
// instance.
bool		ft_fmt_write_va(t_writer writer, const char *format, va_list args);

// Formats the provided string and writes it using the provided `t_writer`
// instance.
bool		ft_fmt_write(t_writer writer, const char *format, ...);

// Formats the provided string and writes it to the provided file descriptor.
bool		ft_fmt_fd(int fd, const char *format, ...);

// Formats the provided string and writes it to provided file descriptor.
bool		ft_fmt_fd_va(int fd, const char *format, va_list args);

// Formats the provided string and writes to the standard output.
bool		ft_fmt(const char *format, ...);

// Formats the provided string and writes to the standard error.
bool		ft_fmt_err(const char *format, ...);

/// Writes something on the standard error (only on `DEBUG` builds).
bool		ft_dbg(const char *format, ...);

// ========================================================================== //
//                             Stack Unwinding                                //
// ========================================================================== //

// A function that is responsible for freeing some datastructure.
typedef void				(*t_free_fn)(void *data);

// Registers a new value for unwinding.
//
// This function returns an integer that can be used to unwind the stack up to
// this call.
size_t		ft_unwind(void *data, t_free_fn destructor);

// Unwinds the stack up to the provided index.
void		ft_unwind_to(size_t to);

// Unwinds the stack, prints an error message and exits with `1`.
void		ft_unwind_panic(const char *msg, ...);

// ========================================================================== //
//                                Allocations                                 //
// ========================================================================== //

// Allocates `count` bytes.
//
// If the allocation fails, the function panics and unwinds the stack.
void		*ft_alloc(size_t count);

// Allocates `count * size` bytes.
//
// On overflow, or if the allocation fails, the function panics and unwinds
// the stack.
void		*ft_alloc_array(size_t count, size_t size);

// ========================================================================== //
// 								     Debug                                    //
// ========================================================================== //

// Makes an assertion. Aborts the process if it is false.
void		ft_assert(bool assertion, const char *msg, ...);

#endif
