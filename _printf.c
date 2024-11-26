#include <stdarg.h>
#include <unistd.h>
#include "main.h"
int print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0;
    if (str == NULL)
        str = "(null)";
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}
int print_percent(va_list args)
{
    (void)args;
    write(1, "%", 1);
    return (1);
}
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    int j;
    specifier_t specifiers[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {0, NULL}
    };
    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            j = 0;
            while (specifiers[j].spec != 0)
            {
                if (format[i] == specifiers[j].spec)
                {
                    count += specifiers[j].func(args);
                    break;
                }
                j++;
            }
            if (specifiers[j].spec == 0)
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}