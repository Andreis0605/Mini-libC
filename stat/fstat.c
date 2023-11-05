// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */

	int rez = syscall(__NR_fstat, fd, st);

	if (rez < 0)
	{
		errno = -rez;
		return -1;
	}

	return rez;

	// return -1;
}
