#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <internal/types.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int rez = syscall(__NR_nanosleep, req, rem);
    if (rez < 0)
    {
        errno = -rez;
        return -1;
    }

    return rez;
}
