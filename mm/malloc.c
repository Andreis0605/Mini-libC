// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	void *rez = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (rez == MAP_FAILED)
	{
		return NULL;
	}
	if (mem_list_add(rez, size) == 0)
		return rez;

	return MAP_FAILED;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t lenght = nmemb * size;

	void *rez = mmap(NULL, lenght, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (rez == MAP_FAILED)
	{
		return NULL;
	}

	memset(rez, 0, lenght);
	mem_list_add(rez, size);

	return rez;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	size_t len = mem_list_find(ptr)->len;
	mem_list_del(ptr);
	munmap(ptr, len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	struct mem_list *old = mem_list_find(ptr);

	void *new = mremap(ptr, old->len, size, 0);

	if (new == MAP_FAILED)
	{
		return NULL;
	}

	old->start = new;
	old->len = size;

	return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	// Source: https://github.com/nesbox/giflib/blob/master/openbsd-reallocarray.c

	size_t lenght = nmemb * size;

	void *aux = realloc(ptr, lenght);
	if (aux != NULL)
		return aux;
	return NULL;
}
