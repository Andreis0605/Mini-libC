// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int rez = syscall(__NR_lseek, fd, offset, whence);

	if (rez < 0)
	{
		errno = -rez;
		return -1;
	}

	return rez;
}
