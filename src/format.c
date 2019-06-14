#include "format.h"
#include <string.h>

void funnel_push_int(FUNNEL* handle, int value)
{
    char tmp[100];
    tmp[0] = 0;
    sprintf(tmp, "%d,", value);
    strcat(handle->front, tmp);
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
        int value = va_arg(list, int);
        sprintf(tmp, "%d,", value);
        strcat(handle->front, tmp);
        tmp[0] = '\0';
    }
    strcat(handle->front, "\n");

    va_end(list);
}
