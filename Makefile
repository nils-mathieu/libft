# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/07/10 16:51:47 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

define SRCS :=
	ft_size_minmax.c

	ft_utf8_decode.c
	ft_str_len.c
	ft_str_nlen.c
	ft_str_cmp.c
	ft_str_find.c
	ft_str_rfind.c
	ft_str_starts_with.c
	ft_str_dup.c

	ft_mem_find.c
	ft_mem_find_inf.c
	ft_mem_find2.c
	ft_mem_find2_inf.c
	ft_mem_copy.c
	ft_mem_set.c

	ft_open.c
	ft_write_all.c
	ft_reader_init.c
	ft_reader_refill.c
	ft_reader_consume.c
	ft_reader_reserve.c
	ft_reader_str.c

	__ft_fmt_parse_format.c
	__ft_fmt_handle_char2.c
	__ft_fmt_handle_string.c
	__ft_fmt_handle_bool.c
	__ft_fmt_handle_str.c
	__ft_fmt_escape.c
	ft_fmt_write.c
	ft_fmt.c
	ft_sfmt.c

	ft_unwind.c
	ft_unwind_panic.c

	ft_alloc_array.c
	ft_alloc.c
	ft_vec_free.c
	ft_vec_realloc.c
	ft_vec_reserve.c

	ft_assert.c
	ft_dbg.c
endef

define GEN :=
	ft_str_to_int8.c
	ft_str_to_int16.c
	ft_str_to_int32.c
	ft_str_to_int64.c
	ft_str_to_int.c
	ft_str_to_long.c
	ft_str_to_llong.c
	ft_str_to_short.c
	ft_str_to_char.c

	ft_int8_to_str.c
	ft_int16_to_str.c
	ft_int32_to_str.c
	ft_int64_to_str.c
	ft_char_to_str.c
	ft_short_to_str.c
	ft_int_to_str.c
	ft_long_to_str.c
	ft_llong_to_str.c
	ft_str_to_char.c

	__ft_fmt_handle_int8.c
	__ft_fmt_handle_int16.c
	__ft_fmt_handle_int32.c
	__ft_fmt_handle_int64.c
	__ft_fmt_handle_char.c
	__ft_fmt_handle_short.c
	__ft_fmt_handle_int.c
	__ft_fmt_handle_long.c
	__ft_fmt_handle_llong.c

	ft_int8_abs.c
	ft_int16_abs.c
	ft_int32_abs.c
	ft_int64_abs.c
	ft_char_abs.c
	ft_short_abs.c
	ft_int_abs.c
	ft_long_abs.c
	ft_llong_abs.c

	ft_int8_minmax.c
	ft_int16_minmax.c
	ft_int32_minmax.c
	ft_int64_minmax.c
	ft_char_minmax.c
	ft_short_minmax.c
	ft_int_minmax.c
	ft_long_minmax.c
	ft_llong_minmax.c
endef

GENERATORS_DIR := generators
SRCS_DIR := srcs
OBJS_DIR := inter/objs
GEN_DIR := inter/gen

HEADER := libft.h __libft_internal.h

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS) $(GEN))
GEN_FILES := $(addprefix $(GEN_DIR)/,$(GEN))

CFLAGS := -Wall -Wextra

ifdef DEBUG
	CFLAGS := $(CFLAGS) -g3 -D DEBUG
else
	CFLAGS := $(CFLAGS) -Werror
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

define TPLT_int8 :=
	-e "s/{INT}/int8/g"
	-e "s/{INT_T}/int8_t/g"
	-e "s/{UINT}/uint8/g"
	-e "s/{UINT_T}/uint8_t/g"
	-e "s/{INT_MIN}/INT8_MIN/g"
	-e "s/{UINT_MAX}/UINT8_MAX/g"
	-e "s/{INT_MIN_STR}/-128/g"
	-e "s/{MAX_LEN}/3/g"
	-e "s/{SMAX_LEN}/4/g"
	-e "s/{VA_UINT}/unsigned int/g"
	-e "s/{VA_INT}/int/g"
endef
TPLT_int8 := $(strip $(TPLT_int8))

define TPLT_int16 :=
	-e "s/{INT}/int16/g"
	-e "s/{INT_T}/int16_t/g"
	-e "s/{UINT}/uint16/g"
	-e "s/{UINT_T}/uint16_t/g"
	-e "s/{INT_MIN}/INT16_MIN/g"
	-e "s/{UINT_MAX}/UINT16_MAX/g"
	-e "s/{INT_MIN_STR}/-32768/g"
	-e "s/{MAX_LEN}/5/g"
	-e "s/{SMAX_LEN}/6/g"
	-e "s/{VA_UINT}/unsigned int/g"
	-e "s/{VA_INT}/int/g"
endef
TPLT_int16 := $(strip $(TPLT_int16))

define TPLT_int32 :=
	-e "s/{INT}/int32/g"
	-e "s/{INT_T}/int32_t/g"
	-e "s/{UINT}/uint32/g"
	-e "s/{UINT_T}/uint32_t/g"
	-e "s/{INT_MIN}/INT32_MIN/g"
	-e "s/{UINT_MAX}/UINT32_MAX/g"
	-e "s/{INT_MIN_STR}/-2147483648/g"
	-e "s/{MAX_LEN}/10/g"
	-e "s/{SMAX_LEN}/11/g"
	-e "s/{VA_UINT}/uint32_t/g"
	-e "s/{VA_INT}/int32_t/g"
endef
TPLT_int32 := $(strip $(TPLT_int32))

define TPLT_int64 :=
	-e "s/{INT}/int64/g"
	-e "s/{INT_T}/int64_t/g"
	-e "s/{UINT}/uint64/g"
	-e "s/{UINT_T}/uint64_t/g"
	-e "s/{INT_MIN}/INT64_MIN/g"
	-e "s/{UINT_MAX}/UINT64_MAX/g"
	-e "s/{INT_MIN_STR}/-9223372036854775808/g"
	-e "s/{MAX_LEN}/20/g"
	-e "s/{SMAX_LEN}/20/g"
	-e "s/{VA_UINT}/uint64_t/g"
	-e "s/{VA_INT}/int64_t/g"
endef
TPLT_int64 := $(strip $(TPLT_int64))

define TPLT_char :=
	-e "s/{INT}/char/g"
	-e "s/{INT_T}/char/g"
	-e "s/{UINT}/uchar/g"
	-e "s/{UINT_T}/unsigned char/g"
	-e "s/{INT_MIN}/CHAR_MIN/g"
	-e "s/{UINT_MAX}/UCHAR_MAX/g"
	-e "s/{INT_MIN_STR}/-128/g"
	-e "s/{MAX_LEN}/3/g"
	-e "s/{SMAX_LEN}/4/g"
	-e "s/{VA_UINT}/unsigned int/g"
	-e "s/{VA_INT}/int/g"
endef
TPLT_char := $(strip $(TPLT_char))

define TPLT_short :=
	-e "s/{INT}/short/g"
	-e "s/{INT_T}/short/g"
	-e "s/{UINT}/ushort/g"
	-e "s/{UINT_T}/unsigned short/g"
	-e "s/{INT_MIN}/SHRT_MIN/g"
	-e "s/{UINT_MAX}/USHRT_MAX/g"
	-e "s/{INT_MIN_STR}/-32768/g"
	-e "s/{MAX_LEN}/5/g"
	-e "s/{SMAX_LEN}/6/g"
	-e "s/{VA_UINT}/unsigned int/g"
	-e "s/{VA_INT}/int/g"
endef
TPLT_short := $(strip $(TPLT_short))

define TPLT_int :=
	-e "s/{INT}/int/g"
	-e "s/{INT_T}/int/g"
	-e "s/{UINT}/uint/g"
	-e "s/{UINT_T}/unsigned int/g"
	-e "s/{INT_MIN}/INT_MIN/g"
	-e "s/{UINT_MAX}/UINT_MAX/g"
	-e "s/{INT_MIN_STR}/-2147483648/g"
	-e "s/{MAX_LEN}/10/g"
	-e "s/{SMAX_LEN}/11/g"
	-e "s/{VA_UINT}/unsigned int/g"
	-e "s/{VA_INT}/int/g"
endef
TPLT_int := $(strip $(TPLT_int))

# Note: the `INT_MIN_STR` won't work on 32-bit targets.
define TPLT_long :=
	-e "s/{INT}/long/g"
	-e "s/{INT_T}/long/g"
	-e "s/{UINT}/ulong/g"
	-e "s/{UINT_T}/unsigned long/g"
	-e "s/{INT_MIN}/LONG_MIN/g"
	-e "s/{UINT_MAX}/ULONG_MAX/g"
	-e "s/{INT_MIN_STR}/-9223372036854775808/g"
	-e "s/{MAX_LEN}/20/g"
	-e "s/{SMAX_LEN}/20/g"
	-e "s/{VA_UINT}/unsigned long/g"
	-e "s/{VA_INT}/long/g"
endef
TPLT_long := $(strip $(TPLT_long))

define TPLT_llong :=
	-e "s/{INT}/llong/g"
	-e "s/{INT_T}/long long/g"
	-e "s/{UINT}/ullong/g"
	-e "s/{UINT_T}/unsigned long long/g"
	-e "s/{INT_MIN}/LLONG_MIN/g"
	-e "s/{UINT_MAX}/ULLONG_MAX/g"
	-e "s/{INT_MIN_STR}/-9223372036854775808/g"
	-e "s/{MAX_LEN}/20/g"
	-e "s/{SMAX_LEN}/20/g"
	-e "s/{VA_UINT}/unsigned long long/g"
	-e "s/{VA_INT}/long long/g"
endef
TPLT_llong := $(strip $(TPLT_llong))

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

$(foreach i,int8 int16 int32 int64 char short int long llong, $(eval	\
	$(GEN_DIR)/ft_$(i)_abs.c: $(GENERATORS_DIR)/ft_INT_abs.gen		   ;\
		@ echo "generating $$@"										   ;\
		mkdir -vp $$(dir $$@)										   ;\
		sed $$(TPLT_$(i)) $$< > $$@										\
))

$(foreach i,int8 int16 int32 int64 char short int long llong, $(eval	\
	$(GEN_DIR)/ft_$(i)_minmax.c: $(GENERATORS_DIR)/ft_INT_minmax.gen   ;\
		@ echo "generating $$@"										   ;\
		mkdir -vp $$(dir $$@)										   ;\
		sed $$(TPLT_$(i)) $$< > $$@										\
))
