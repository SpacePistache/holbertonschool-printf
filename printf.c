#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int i, count = 0;

    va_list args;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != %)
        {
            _putchar(format[i]);
        }
        count += 1; 
    }
    return (count);
}