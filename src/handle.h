#pragma once

#include "defines.h"
#include <stdio.h>

typedef struct _FUNNEL
{
    FILE* fp;
    char* front;
} FUNNEL;

FUNNEL* funnel_open(const char*);
void funnel_push_str(FUNNEL*, const char*);
void funnel_flush(FUNNEL*);
void funnel_close(FUNNEL*);