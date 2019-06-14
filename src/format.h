#pragma once

#include <stdio.h>
#include <stdarg.h>
#include "handle.h"

void funnel_push_int(FUNNEL*, int);
void funnel_push_int_row(FUNNEL*, int, ...);