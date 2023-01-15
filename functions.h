#pragma once

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"


void init();
void call_core_first();
void call_core_second();