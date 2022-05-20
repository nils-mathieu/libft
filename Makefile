# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/20 13:53:38 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS :=									\
	ft_int_abs.c						\
	ft_size_max.c						\
	ft_size_min.c						\
										\
	ft_str_len.c						\
	ft_str_nlen.c						\
	ft_str_cmp.c						\
	ft_str_find.c						\
	ft_str_rfind.c						\
	ft_str_starts_with.c				\
										\
	ft_mem_find.c						\
	ft_mem_find_inf.c					\
	ft_mem_find2.c						\
	ft_mem_find2_inf.c					\
	ft_mem_copy.c						\
	ft_mem_set.c						\
										\
	ft_write_all.c						\
	ft_write_buffered.c					\
	ft_write_repeat.c					\
	ft_write_repeat_one.c				\
	ft_reader_refill.c					\
	ft_read_byte.c						\
										\
	__ft_fmt_parse_format.c				\
	__ft_fmt_handle_char.c				\
	__ft_fmt_handle_string.c			\
	__ft_fmt_handle_bool.c				\
	ft_fmt_write.c						\
	ft_fmt.c							\
	ft_dbg.c							\
										\
	ft_alloc_array.c					\
										\
	ft_assert.c

GEN :=									\
	ft_str_to_int8.c					\
	ft_str_to_int16.c					\
	ft_str_to_int32.c					\
	ft_str_to_int64.c					\
	ft_str_to_int.c						\
	ft_str_to_long.c					\
	ft_str_to_llong.c					\
	ft_str_to_short.c					\
	ft_str_to_char.c					\
										\
	ft_int8_to_str.c					\
	ft_int16_to_str.c					\
	ft_int32_to_str.c					\
	ft_int64_to_str.c					\
	ft_char_to_str.c					\
	ft_short_to_str.c					\
	ft_int_to_str.c						\
	ft_long_to_str.c					\
	ft_llong_to_str.c					\
	ft_str_to_char.c					\
										\
	__ft_fmt_handle_int8.c				\
	__ft_fmt_handle_int16.c				\
	__ft_fmt_handle_int32.c				\
	__ft_fmt_handle_int64.c				\
	__ft_fmt_handle_char.c				\
	__ft_fmt_handle_short.c				\
	__ft_fmt_handle_int.c				\
	__ft_fmt_handle_long.c				\
	__ft_fmt_handle_llong.c				\

GENERATORS_DIR := generators
SRCS_DIR := srcs
OBJS_DIR := inter/objs
GEN_DIR := inter/gen

HEADER := libft.h __libft_internal.h

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS) $(GEN))
GEN_FILES := $(addprefix $(GEN_DIR)/,$(GEN))

CFLAGS := -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -g3 -D DEBUG
else
	CFLAGS += -O3
endif

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@rm -vf $(OBJ_FILES)
	@rm -vf $(GEN_FILES)

.PHONY: fclean
fclean: clean
	@rm -vf $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -vp $(dir $@)
	clang $(CFLAGS) -I. -c $< -o $@

$(OBJS_DIR)/%.o: $(GEN_DIR)/%.c $(HEADER)
	@mkdir -vp $(dir $@)
	clang $(CFLAGS) -I. -c $< -o $@

TPLT_int8 :=								\
	-e "s/{INT}/int8/g"						\
	-e "s/{INT_T}/int8_t/g"					\
	-e "s/{UINT}/uint8/g"					\
	-e "s/{UINT_T}/uint8_t/g"				\
	-e "s/{INT_MIN}/INT8_MIN/g"				\
	-e "s/{UINT_MAX}/UINT8_MAX/g"			\
	-e "s/{INT_MIN_STR}/-128/g"				\
	-e "s/{MAX_LEN}/3/g"					\
	-e "s/{SMAX_LEN}/4/g"					\
	-e "s/{VA_UINT}/unsigned int/g"			\
	-e "s/{VA_INT}/int/g"

TPLT_int16 :=								\
	-e "s/{INT}/int16/g"					\
	-e "s/{INT_T}/int16_t/g"				\
	-e "s/{UINT}/uint16/g"					\
	-e "s/{UINT_T}/uint16_t/g"				\
	-e "s/{INT_MIN}/INT16_MIN/g"			\
	-e "s/{UINT_MAX}/UINT16_MAX/g"			\
	-e "s/{INT_MIN_STR}/-32768/g"			\
	-e "s/{MAX_LEN}/5/g"					\
	-e "s/{SMAX_LEN}/6/g"					\
	-e "s/{VA_UINT}/unsigned int/g"			\
	-e "s/{VA_INT}/int/g"

TPLT_int32 :=								\
	-e "s/{INT}/int32/g"					\
	-e "s/{INT_T}/int32_t/g"				\
	-e "s/{UINT}/uint32/g"					\
	-e "s/{UINT_T}/uint32_t/g"				\
	-e "s/{INT_MIN}/INT32_MIN/g"			\
	-e "s/{UINT_MAX}/UINT32_MAX/g"			\
	-e "s/{INT_MIN_STR}/-2147483648/g"		\
	-e "s/{MAX_LEN}/10/g"					\
	-e "s/{SMAX_LEN}/11/g"					\
	-e "s/{VA_UINT}/uint32_t/g"				\
	-e "s/{VA_INT}/int32_t/g"

TPLT_int64 :=								\
	-e "s/{INT}/int64/g"					\
	-e "s/{INT_T}/int64_t/g"				\
	-e "s/{UINT}/uint64/g"					\
	-e "s/{UINT_T}/uint64_t/g"				\
	-e "s/{INT_MIN}/INT64_MIN/g"			\
	-e "s/{UINT_MAX}/UINT64_MAX/g"			\
	-e "s/{INT_MIN_STR}/-9223372036854775808/g"	\
	-e "s/{MAX_LEN}/20/g"					\
	-e "s/{SMAX_LEN}/20/g"					\
	-e "s/{VA_UINT}/uint64_t/g"				\
	-e "s/{VA_INT}/int64_t/g"

TPLT_char :=								\
	-e "s/{INT}/char/g"						\
	-e "s/{INT_T}/char/g"					\
	-e "s/{UINT}/uchar/g"					\
	-e "s/{UINT_T}/unsigned char/g"			\
	-e "s/{INT_MIN}/CHAR_MIN/g"				\
	-e "s/{UINT_MAX}/UCHAR_MAX/g"			\
	-e "s/{INT_MIN_STR}/-128/g"				\
	-e "s/{MAX_LEN}/3/g"					\
	-e "s/{SMAX_LEN}/4/g"					\
	-e "s/{VA_UINT}/unsigned int/g"			\
	-e "s/{VA_INT}/int/g"

TPLT_short :=								\
	-e "s/{INT}/short/g"					\
	-e "s/{INT_T}/short/g"					\
	-e "s/{UINT}/ushort/g"					\
	-e "s/{UINT_T}/unsigned short/g"		\
	-e "s/{INT_MIN}/SHRT_MIN/g"				\
	-e "s/{UINT_MAX}/USHRT_MAX/g"			\
	-e "s/{INT_MIN_STR}/-32768/g"			\
	-e "s/{MAX_LEN}/5/g"					\
	-e "s/{SMAX_LEN}/6/g"					\
	-e "s/{VA_UINT}/unsigned int/g"			\
	-e "s/{VA_INT}/int/g"

TPLT_int :=									\
	-e "s/{INT}/int/g"						\
	-e "s/{INT_T}/int/g"					\
	-e "s/{UINT}/uint/g"					\
	-e "s/{UINT_T}/unsigned int/g"			\
	-e "s/{INT_MIN}/INT_MIN/g"				\
	-e "s/{UINT_MAX}/UINT_MAX/g"			\
	-e "s/{INT_MIN_STR}/-2147483648/g"		\
	-e "s/{MAX_LEN}/10/g"					\
	-e "s/{SMAX_LEN}/11/g"					\
	-e "s/{VA_UINT}/unsigned int/g"			\
	-e "s/{VA_INT}/int/g"

# Note: the `INT_MIN_STR` won't work on 32-bit targets.
TPLT_long :=								\
	-e "s/{INT}/long/g"						\
	-e "s/{INT_T}/long/g"					\
	-e "s/{UINT}/ulong/g"					\
	-e "s/{UINT_T}/unsigned long/g"			\
	-e "s/{INT_MIN}/LONG_MIN/g"				\
	-e "s/{UINT_MAX}/ULONG_MAX/g"			\
	-e "s/{INT_MIN_STR}/-9223372036854775808/g"	\
	-e "s/{MAX_LEN}/20/g"					\
	-e "s/{SMAX_LEN}/20/g"					\
	-e "s/{VA_UINT}/unsigned long/g"		\
	-e "s/{VA_INT}/long/g"

TPLT_llong :=								\
	-e "s/{INT}/llong/g"					\
	-e "s/{INT_T}/long long/g"				\
	-e "s/{UINT}/ullong/g"					\
	-e "s/{UINT_T}/unsigned long long/g"	\
	-e "s/{INT_MIN}/LLONG_MIN/g"			\
	-e "s/{UINT_MAX}/ULLONG_MAX/g"			\
	-e "s/{INT_MIN_STR}/-9223372036854775808/g"	\
	-e "s/{MAX_LEN}/20/g"					\
	-e "s/{SMAX_LEN}/20/g"					\
	-e "s/{VA_UINT}/unsigned long long/g"	\
	-e "s/{VA_INT}/long long/g"

$(foreach i,int8 int16 int32 int64 char short int long llong, $(eval	\
	$(GEN_DIR)/ft_str_to_$(i).c: $(GENERATORS_DIR)/ft_str_to_INT.gen   ;\
		@ echo "generating $$@"										   ;\
		mkdir -vp $$(dir $$@)										   ;\
		sed $$(TPLT_$(i)) $$< > $$@										\
))

$(foreach i,int8 int16 int32 int64 char short int long llong, $(eval	\
	$(GEN_DIR)/ft_$(i)_to_str.c: $(GENERATORS_DIR)/ft_INT_to_str.gen   ;\
		@ echo "generating $$@"										   ;\
		mkdir -vp $$(dir $$@)										   ;\
		sed $$(TPLT_$(i)) $$< > $$@										\
))

$(foreach i,int8 int16 int32 int64 char short int long llong, $(eval	\
	$(GEN_DIR)/__ft_fmt_handle_$(i).c: $(GENERATORS_DIR)/__ft_fmt_handle_INT.gen ;\
		@ echo "generating $$@"										   ;\
		mkdir -vp $$(dir $$@)										   ;\
		sed $$(TPLT_$(i)) $$< > $$@										\
))
