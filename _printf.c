#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 * Return: 1 (success)
 */
int _putchar(char c)
{
    return (write(1, &c, 1));  /* Write a character to stdout */
}

/**
 * print_char - Prints a character
 * @args: Argument list containing the character to print
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));  /* Use _putchar instead of write */
}

/**
 * print_string - Prints a string
 * @args: Argument list containing the string to print
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";  /* Handle null string */
    while (*str)
    {
        _putchar(*str++);  /* Use _putchar to print each character */
        count++;
    }
    return (count);
}

/**
 * print_percent - Prints a percent sign
 * @args: Argument list (unused)
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
    (void)args;  /* No need to use args here */
    return (_putchar('%'));  /* Print the percent sign using _putchar */
}

/**
 * print_int - Prints an integer
 * @args: Argument list containing the integer to print
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int len = 0;

    if (n == 0)
        return (_putchar('0'));  /* Special case for 0 */

    if (n < 0)
    {
        len += _putchar('-');  /* Print the negative sign */
        n = -n;  /* Make the number positive */
    }

    if (n / 10)
        len += print_int((va_list) &n / 10);  /* Recurse to print digits */

    len += _putchar((n % 10) + '0');  /* Print the last digit */
    return (len);
}

/**
 * _printf - A simple printf function that handles the format specifiers
 * @format: The format string
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0, j;

    va_start(args, format);
    if (format == NULL)
        return (-1);  /* Handle null format string */

    /* Array of format specifiers and their respective functions */
    specifier_t specifiers[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {0, NULL}  /* End marker */
    };

    while (format[i])
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
            if (specifiers[j].spec == 0)  /* If no matching specifier */
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;  /* Count for '%' and the character */
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
