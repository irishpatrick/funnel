#include "handle.h"
#include <stdlib.h>
#include <string.h>

static count = 0;

FUNNEL* funnel_open(const char* fn)
{
    FUNNEL* out = (FUNNEL*)malloc(sizeof(FUNNEL));
    if (out == NULL)
    {
        return NULL;
    }
    out->front = (char*)malloc(FUNNEL_BUFFER_SIZE);
    if (out->front == NULL)
    {
        return NULL;
    }
    out->fp = fopen(fn, "wb");
    if (out->fp == NULL)
    {
        free(out->front);
        free(out);
        return NULL;
    }

    out->front[0] = '\0';

    return out;
}

void funnel_write(FUNNEL* handle, const char* str)
{
    if (strlen(str) > FUNNEL_BUFFER_SIZE - 1)
    {
        //printf("INFO\tsplit write\n");
        char tmp[FUNNEL_BUFFER_SIZE];
        strncpy(tmp, str, FUNNEL_BUFFER_SIZE - 1);
        funnel_write(handle, tmp);
        funnel_write(handle, str + FUNNEL_BUFFER_SIZE);
        return;
    }
    else if (strlen(handle->front) + strlen(str) > FUNNEL_BUFFER_SIZE - 1)
    {
        //printf("INFO\tpre flush %d\n", ++count);
        funnel_flush(handle);
    }

    //printf("INFO\tstrcat call\n");
    
    strcat(handle->front, str);
}

void funnel_flush(FUNNEL* handle)
{
    fwrite(handle->front, 1, strlen(handle->front), handle->fp);
    handle->front[0] = '\0';
}

void funnel_close(FUNNEL* handle)
{
    funnel_flush(handle);
    fclose(handle->fp);
    free(handle->front);
    free(handle);
}