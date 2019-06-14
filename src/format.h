#pragma once

#include <stdio.h>
#include <stdarg.h>
#include "handle.h"

void funnel_push_int(FUNNEL*, long);
void funnel_push_int_row(FUNNEL*, int, ...);
void funnel_push_uint(FUNNEL*, unsigned long);
void funnel_push_float(FUNNEL*, double);