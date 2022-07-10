/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:00 by nmathieu          #+#    #+#             */
/*   Updated: 2022/07/10 16:52:14 by nmathieu         ###   ########.fr       */
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

// Decodes an additional UTF-8 byte.
//
// `0` indicates that the character could be parsed properly.
// `1` indicates that an error occured.
uint32_t	ft_utf8_decode(uint32_t state, uint32_t *codep, uint32_t byte);

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

// Returns a copy of the provided string, allocated using `malloc`.
//
// If the allocation fails, the function panics.
char		*ft_str_dup(const char *s);

// Returns a copy of the provided string, allocated using `malloc`.
//
// The string is trucated to be at most `n` characters (not including the
// terminating null character).
//
// If the allocation fails, the function panics.
char		*ft_str_ndup(const char *s, size_t n);

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

// Opens a file with the specified flags.
//
// If an error occurs, the function panics.
int			ft_open(const char *filename, int flags);

// Closes the provided file descriptor.
void		ft_close(int *fd);

// Writes `data` to the provided file descriptor. Returns whether no error
// occured.
bool		ft_write_all(int fd, const void *data, size_t to_write);

// Stores the state of a reader.
typedef struct s_reader
{
	uint8_t		*data;
	size_t		init;
	size_t		cap;
	size_t		con;
	int			fd;
}	t_reader;

// Initializes a `t_reader` instance.
void		ft_reader_init(t_reader *reader, int fd);

// Frees the resources that were allocated for `t_reader` instance.
void		ft_reader_deinit(t_reader *reader);

// Reads additional bytes into the reader. Calls to `read` will be of at least
// `min_read_size` bytes.
//
// If read error occurs, the function panics.
bool		ft_reader_refill(t_reader *r, size_t min_read_size);

// Makes sure that the reader can read at least `count` additional bytes
// continuously without reallocating.
//
// If the system is out of memory, the function panics.
void		ft_reader_reserve(t_reader *reader, size_t count);

// Notifies a `t_reader` instance that `count` bytes wont be needed anymore and
// can be overriden when needed. 
void		ft_reader_consume(t_reader *reader, size_t count);

// Returns a `t_str` over the bytes currently stored in this `t_reader`
// instance that were not consumed.
t_str		ft_reader_str(const t_reader *reader);

// ========================================================================== //
//                                   Format                                   //
// ========================================================================== //

// A function that may be used to write the first `count` bytes referenced
// by `to_write`.
typedef bool				(*t_writer_fn)(void *s, const void *w, size_t l);

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
bool		ft_efmt(const char *format, ...);

// Formats the provided string into a new string.
//
// If an allocation error occurs, the function panics.
char		*ft_sfmt_va(const char *format, va_list args);

// Formats the provided string into a new string.
//
// If an allocation error occurs, the function panics.
char		*ft_sfmt(const char *format, ...);

// ========================================================================== //
//                             Stack Unwinding                                //
// ========================================================================== //

// Stores an index that is suitable for stack unwinding.
typedef size_t				t_unwind;

// A function that is responsible for freeing some datastructure.
typedef void				(*t_free_fn)();

// Registers a new value for unwinding.
//
// This function returns an integer that can be used to unwind the stack up to
// this call.
t_unwind	ft_unwind(void *data, t_free_fn destructor);

// Unwinds the stack up to the provided index.
void		ft_unwind_to(t_unwind to);

// Unwinds the stack, prints an error message and exits with `1`.
void		ft_unwind_panic(const char *msg, ...);

// Defuses the destructor of the provided index.
void		ft_unwind_defuse(t_unwind index);

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

// A growable array allocated on the heap.
//
// `cap` is the number of elements allocated at `data`. Those elements may or
// may not be currently.
//
// `len` is the number of initialized elements.
typedef struct t_vec
{
	void	*data;
	size_t	len;
	size_t	cap;
}	t_vec;

// Reallocates the internal buffer of the provided vector.
//
// If the allocation fails, the function panics and unwinds the stack.
void		ft_vec_realloc(t_vec *vec, size_t new_cap, size_t elem_size);

// Reallocates the internal buffer of the provided vector if it is not large
// enough to store at least `additional` mode elements.
//
// To avoid frequente reallocations, more data may be allocated.
//
// If the allocation fails, the function panics and unwinds the stack.
void		ft_vec_reserve(t_vec *vec, size_t additional, size_t elem_size);

// Frees the provided vector, calling the `free_el` function on every element
// within the vector.
void		ft_vec_free(t_vec *vec, void (*free_el)(), size_t elem_size);

// ========================================================================== //
// 								     Debug                                    //
// ========================================================================== //

// Makes an assertion. Aborts the process if it is false.
void		ft_assert(bool assertion, const char *msg, ...);

/// Writes something on the standard error (only on `DEBUG` builds).
bool		ft_dbg(const char *format, ...);

#endif
