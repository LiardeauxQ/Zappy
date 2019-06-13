/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** Utils for the handlers
*/

#include <stdint.h>
#include <time.h>

#include "ai/handlers/utils.h"

int is_time_limit_passed(const clock_t start, const uint16_t limit_cycles,
        const unsigned int f)
{
    clock_t end = clock();
    clock_t total = (double) (end - start) / CLOCKS_PER_SEC;

    return (total > limit_cycles / f);
}
