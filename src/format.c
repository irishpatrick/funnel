#include "format.h"
#include <string.h>

void funnel_push_int(FUNNEL* handle, long value)
{
    char tmp[100];
    tmp[0] = 0;
    sprintf(tmp, "%ld,", value);
    funnel_write(handle, tmp);
}

void funnel_push_int_row(FUNNEL* handle, int num, ...)
{
    char tmp[100];
    tmp[0] = 0;

    va_list list;
    int i;

    va_start(list, num);
    for (i = 0; i < num; ++i)
    {
        long value = va_arg(list, long);
        sprintf(tmp, "%ld,", value);
        funnel_write(handle, tmp);
        tmp[0] = '\0';
    }

    funnel_write(handle, "\n");

    va_end(list);
}

void funnel_push_uint(FUNNEL* handle, unsigned long value)
{
    char tmp[100];
    tmp[0] = 0;
    sprintf(tmp, "%lu,", value);
    funnel_write(handle, tmp);
}

void funnel_push_float(FUNNEL* handle, double value)
{
    char tmp[100];
    tmp[0] = 0;
    sprintf(tmp, "%lf,", value);
    funnel_write(handle, tmp);
}