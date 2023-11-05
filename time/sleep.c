#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    // source: inspirat de la "https://elixir.bootlin.com/musl/latest/source/src/unistd/sleep.c#L4"

    struct timespec aux;

    aux.tv_sec = seconds;
    aux.tv_nsec = 0;

    if (nanosleep(&aux, &aux))
        return aux.tv_sec;
    return 0;
}
