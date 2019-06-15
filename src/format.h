#pragma once

#include <stdio.h>
#include <stdarg.h>
#include "handle.h"

void funnel_push_int(HANDLE*, long);
void funnel_push_int_row(HANDLE*, int, ...);

void funnel_push_uint(HANDLE*, unsigned long);
void funnel_push_uint_row(HANDLE*, int, ...);

void funnel_push_float(HANDLE*, double);
void funnel_push_float_row(HANDLE*, double);