#ifndef __STRING_LIB_H__
#define __STRING_LIB_H__

#include <string.h>
#include <stdarg.h>

typedef const char * STRING;

#define $STR(str) str_create(str)

STRING str_new();

STRING str_nnew(size_t);

void str_destroy(STRING);

size_t str_length(STRING);

size_t str_size(STRING);

int str_printf(STRING *, const char *, ...);

int str_vprintf(STRING *, const char *, va_list);

STRING str_create(const char *);

STRING str_dup(STRING);

void str_copy(STRING *, STRING);

void str_ccopy(STRING *, const char *);

void str_nccopy(STRING *, const char *, size_t);

void str_cat(STRING *, STRING);

void str_ccat(STRING *, const char *);

void str_nccat(STRING *, const char *, size_t);

void str_trim(STRING);

void str_ltrim(STRING);

void str_rtrim(STRING);

#endif
