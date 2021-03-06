#pragma once

#include <stdint.h>
#include "../ft2_audio.h"

#define CUBIC_WIDTH 4 /* number of taps */
#define CUBIC_WIDTH_BITS 2

#if defined __amd64__ || defined _WIN64

// 15-bit precision, 4096 phases
#define CUBIC_PHASES 4096
#define CUBIC_PHASES_BITS 12

#else

// for non-x86_64 CPUs: 15-bit precision, 1024 phases (less hard on the CPU cache)
#define CUBIC_PHASES 1024
#define CUBIC_PHASES_BITS 10

#endif

#define CUBIC_FSHIFT (MIXER_FRAC_BITS-(CUBIC_PHASES_BITS+CUBIC_WIDTH_BITS))
#define CUBIC_FMASK ((CUBIC_WIDTH*CUBIC_PHASES)-CUBIC_WIDTH)
#define CUBIC_QUANTSHIFT 15

extern const int16_t cubicSplineTable[CUBIC_WIDTH * CUBIC_PHASES];
