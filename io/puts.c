#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const void *src)
{
    int len, rez;
    len = strlen(src);

    rez = write(1, src, len);
    if (rez != len || rez < 0)
        return -1;

    write(1, "\n", 1);

    return rez;
}
