#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "string_lib.h"

const int NEW_STRING_SIZE = 20;

typedef struct _str_attrs {
	size_t length;	/* Describes the current length in characters of the string. */
	size_t size;	/* Describes the current number of bytes (characters) allocated to the string at this time. */
	char str[1];	/* The actual location of the string data. */
} _STR_ATTRS;

#define $STR_ATTR(s) \
	((_STR_ATTRS *)((s) - (((_STR_ATTRS *)(s))->str - (char *)((_STR_ATTRS *)(s)))))

/*
 * Private Function Declarations
 */

static int _str_ensure(STRING *, int);
static size_t _nextpow2(int);

/*
 * Public Function Definitions
 */

STRING str_new()
{
	return str_nnew(NEW_STRING_SIZE);
}

STRING str_nnew(size_t size)
{
	_STR_ATTRS *ptr = malloc(sizeof(_STR_ATTRS) + sizeof(char) * (size-1));
	STRING str = NULL;
	if (ptr != NULL)
	{
		str = ptr->str;

		ptr->length = 0;
		ptr->size = size;
		memset(ptr->str, '\0', size);
	}

	return str;
}

void str_destroy(STRING str)
{
	memset($STR_ATTR(str)->str, '\0', str_size(str));
	free($STR_ATTR(str));
}

size_t str_length(STRING str)
{
	return $STR_ATTR(str)->length;
}

size_t str_size(STRING str)
{
	return $STR_ATTR(str)->size;
}

int str_printf(STRING *str, const char *format, ...)
{
	va_list args;
	int count = -1;

	va_start(args, format);

	count = str_vprintf(str, format, args);

	va_end(args);

	return count;
}

int str_vprintf(STRING *str, const char *format, va_list args)
{
	int count = -1;
	_STR_ATTRS *ptr;
	va_list local_args;

	va_copy(local_args, args);
	count = vsnprintf(NULL, 0, format, local_args);

	_str_ensure(str, count);
	ptr = $STR_ATTR(*str);

	ptr->length = vsnprintf(ptr->str, ptr->size, format, args);

	return count;
}

STRING str_create(const char *c_str)
{
	size_t len = strlen(c_str);
	STRING str = str_nnew(len + 1);
	memcpy($STR_ATTR(str)->str, c_str, len);
	$STR_ATTR(str)->length = len;
	return str;
}

STRING str_dup(STRING str)
{
	STRING str2 = str_nnew(str_length(str) + 1);
	memcpy($STR_ATTR(str2)->str, str, str_length(str));
	$STR_ATTR(str2)->length = str_length(str);
	return str2;
}

void str_clear(STRING str1)
{
	memset($STR_ATTR(str1)->str, '\0', str_length(str1));
	$STR_ATTR(str1)->length = 0;
}

void str_copy(STRING *dest, STRING src)
{
	str_nccopy(dest, src, str_length(src));
}

void str_ccopy(STRING *dest, const char *src)
{
	str_nccopy(dest, src, strlen(src));
}

void str_nccopy(STRING *dest, const char *src, size_t len)
{
	_str_ensure(dest, len + 1);
	memcpy($STR_ATTR(*dest)->str, src, len);
	memset($STR_ATTR(*dest)->str + len, '\0', str_size(*dest) - len);
	$STR_ATTR(*dest)->length = len;
}

void str_cat(STRING *str1, STRING str2)
{
	str_nccat(str1, str2, str_length(str2));
}

void str_ccat(STRING *str1, const char *str2)
{
	str_nccat(str1, str2, strlen(str2));
}

void str_nccat(STRING *str1, const char *str2, size_t len)
{
	_str_ensure(str1, str_length(*str1) + len + 1);
	memcpy($STR_ATTR(*str1)->str + str_length(*str1), str2, len);
	$STR_ATTR(*str1)->length += len;
}

void str_trim(STRING str)
{
	str_rtrim(str);
	str_ltrim(str);
}

void str_ltrim(STRING str)
{
	int i;
	for (i = 0; i < str_length(str) && isspace(str[i]); ++i)
		/* nothing */;

	if (i < str_length(str))
		memmove($STR_ATTR(str)->str, $STR_ATTR(str)->str + i, str_length(str) - i);	
	if (i > 0)
		memset($STR_ATTR(str)->str + str_length(str) - i, '\0', i);
}

void str_rtrim(STRING str)
{
	int i;
	for (i = str_length(str) - 1; i >= 0 && isspace(str[i]); --i)
	{
		$STR_ATTR(str)->str[i] = '\0';
		$STR_ATTR(str)->length--;
	}
}

/*
 * Private Function Definitions
 */

static int _str_ensure(STRING *str, int count)
{
	_STR_ATTRS *ptr = $STR_ATTR(*str);
	if (ptr->size < count + 1)
	{
		size_t new_size = ptr->size * (_nextpow2((count + 1) / ptr->size) + 1);
		_STR_ATTRS *new_ptr;

		new_ptr = realloc(ptr, sizeof(_STR_ATTRS) + new_size - 1);
		if (new_ptr != NULL)
		{
			memset(new_ptr->str + new_ptr->size, '\0', new_size - new_ptr->size);
			new_ptr->size = new_size;
			*str = new_ptr->str;
			return 1;
		}

		return 0;
	}

	return 1;
}

static size_t _nextpow2(int x)
{
	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return ++x;
}
