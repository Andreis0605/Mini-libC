// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	long rez = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (rez < 0)
	{
		errno = -rez;
		return MAP_FAILED;
	}

	return (void *)rez;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */

	long rez = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (rez < 0)
	{
		errno = -rez;
		return MAP_FAILED;
	}

	return (void *)rez;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */

	int rez = syscall(__NR_munmap, addr, length);

	if (rez < 0)
	{
		errno = -rez;
		return -1;
	}
	return 0;
}
