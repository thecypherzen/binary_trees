#ifndef _UTILITY_FUNCS_H
#define _UTILITY_FUNCS_H

#include <stdarg.h>
#include <limits.h>

/**
 * _int_max - a function that returns the maximum between integers
 *
 * It's variadic and takes in as many ints as desired
 *
 * @n: number of expected arguments
 *
 * Return: the max of @n integers
 */
int _int_max(int n,...)
{
    int max = INT_MIN, i, next;

    if (n)
    {
        va_list numbers;

        va_start(numbers, n);
        for (i = 0; i < n; i++)
        {
            next = va_arg(numbers, int);
            if (next > max)
                max = next;
			printf("comparing: %d & %d\n", max, next);
        }
        va_end(numbers);
    }
    return (max);
}

#endif /* UTILITY_FUNCS_H */
