#include "header.h"
extern void pslow(const char *str, int delay)
{
    while(*str)
    {
        printf("%c", *str);
        fflush(stdout);     // force print immediately
        usleep(delay);      // delay in microseconds
        str++;
    }
}
