#include "format.h"
#include <string.h>

#define SCRATCH_BUFFER_SIZE 30

void funnel_push_int(HANDLE* handle, long value)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;
    sprintf(tmp, "%ld,", value);
    funnel_write(handle, tmp);
}

void funnel_push_int_row(HANDLE* handle, int num, ...)
{
    char tmp[SCRATCH_BUFFER_SIZE];
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

void funnel_push_uint(HANDLE* handle, unsigned long value)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;
    sprintf(tmp, "%lu,", value);
    funnel_write(handle, tmp);
}

void funnel_push_uint_row(HANDLE* handle, int num, ...)
{

}

void funnel_push_float(HANDLE* handle, double value)
{
    char tmp[SCRATCH_BUFFER_SIZE];
    tmp[0] = 0;
    sprintf(tmp, "%lf,", value);
    funnel_write(handle, tmp);
}

void funnel_push_float_row(HANDLE* handle, double value)
{

}
