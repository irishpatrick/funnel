#pragma once

#include "defines.h"
#include <stdio.h>

typedef struct _HANDLE
{
    FILE* fp;
    char* front;
} HANDLE;

HANDLE* funnel_open(const char*);
void funnel_write(HANDLE*, const char*);
void funnel_flush(HANDLE*);
void funnel_close(HANDLE*);