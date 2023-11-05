// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i, source_len;

	source_len = strlen(source);

	for (i = 0; i <= source_len; i++)
	{
		destination[i] = source[i];
	}

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int i, j, source_len, desttination_len;

	desttination_len = strlen(destination);
	source_len = strlen(source);
	j = len;

	for (i = 0; i <= source_len && i <= desttination_len && j > 0; i++, j--)
	{
		destination[i] = source[i];
	}

	if (source_len <= desttination_len)
		destination[len] = '\0';
	else
		destination[desttination_len] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i, src_len, dest_len, j;

	src_len = strlen(source);
	dest_len = strlen(destination);

	i = dest_len;

	for (j = 0; i <= dest_len + src_len && j <= src_len; i++, j++)
	{
		destination[i] = source[j];
	}

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t i, j, dest_len, src_len;

	dest_len = strlen(destination);
	src_len = strlen(source);

	i = dest_len;
	j = len;

	for (j = 0; i <= dest_len + src_len && j <= len; i++, j++)
	{
		destination[i] = source[j];
	}

	destination[dest_len + len] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0, j = 0;

	while (str1[i] != 0 && str2[i] != 0 && str1[i] == str2[j])
	{
		i++;
		j++;
	}

	if (str1[i] == 0 && str2[i] == 0)
		return 0;
	if (str1[i] == 0 || str1[i] < str2[j])
		return -1;
	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	// Source: https://elixir.bootlin.com/musl/latest/source/src/string/strncmp.c
	int i = 0, j = 0;

	if (!len--)
		return 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[j] && len)
	{
		i++;
		j++;
		len--;
	}

	return str1[i] - str2[j];
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	const char *aux;

	aux = str;

	while (*aux != c && *aux)
	{
		aux++;
	}

	if (*aux)
		return (char *)aux;

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i = 0, ok = 0;
	char chr = (char)c;
	const char *rez;

	while (str[i] != '\0')
	{
		if (str[i] == chr)
		{
			rez = str + i;
			ok = 1;
		}
		i++;
	}
	if (ok)
		return (char *)rez;

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int i, haystach_len, needle_len, ok = 0;
	const char *aux;

	haystach_len = strlen(haystack);
	needle_len = strlen(needle);

	for (i = 0; i < haystach_len - needle_len && !ok; i++)
	{
		if (strncmp(haystack + i, needle, needle_len) == 0)
		{
			aux = haystack + i;
			ok = 1;
		}
	}

	if (ok)
		return (char *)aux;
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int i, haystach_len, needle_len, ok = 0;
	const char *aux;

	haystach_len = strlen(haystack);
	needle_len = strlen(needle);

	for (i = 0; i < haystach_len - needle_len; i++)
	{
		if (strncmp(haystack + i, needle, needle_len) == 0)
		{
			aux = haystack + i;
			ok = 1;
		}
	}

	if (ok)
		return (char *)aux;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	unsigned char *d = (unsigned char *)destination;
	const unsigned char *s = (const unsigned char *)source;
	size_t i;

	for (i = 0; i < num; i++)
	{
		d[i] = s[i];
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	// source: https://aticleworld.com/memmove-function-implementation-in-c/
	unsigned char *d = (unsigned char *)destination;
	const unsigned char *s = (const unsigned char *)source;
	size_t i;

	if (d < s)
	{
		for (i = 0; i < num; i++)
		{
			d[i] = s[i];
		}
	} else if (d > s) {
		for (i = num; i > 0; i--)
		{
			d[i - 1] = s[i - 1];
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	// Source: https://elixir.bootlin.com/musl/latest/source/src/string/memcmp.c
	const unsigned char *l = (const unsigned char *)ptr1;
	const unsigned char *r = (const unsigned char *)ptr2;
	int n = num;

	while (n > 0 && *l == *r)
	{
		n--;
		l++;
		r++;
	}

	if (n)
		return *l - *r;
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *s = (unsigned char *)source;
	unsigned char v = (unsigned char)value;
	size_t i;

	for (i = 0; i < num; i++)
	{
		s[i] = v;
	}

	return source;
}
