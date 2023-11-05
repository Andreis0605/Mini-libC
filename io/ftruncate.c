// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>


int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */

	int rez = syscall(__NR_ftruncate, fd, length);

	if(rez < 0)
	{
		errno = -rez;
		return -1;
	}
	return rez;
}
