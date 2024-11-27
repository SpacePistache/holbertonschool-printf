#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * print_char - Prints a character
 * @args: Argument list containing the character to print
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
write(1, &c, 1);
return (1);
}
/**
 * print_string - Prints a string
 * @args: Argument list containing the string to print
 * Return: Number of characters printed
 */
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
/**
 * print_percent - Prints a percent sign
 * @args: Argument list (unused)
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
(void)args;
write(1, "%", 1);
return (1);
}
/**
 * _printf - Produces output according to a format
 * @format: A string containing the desired characters and specifiers
 * Return: Total number of characters printed
 */
/**
 * print_i - Prints an integer
 * @args: Argument list containing the integer to print
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
int n = va_arg(args, int);
char buffer[12];
int len = 0;
if (n < 0)
{
write(1, "-", 1);
n = -n;
len++;
}
len += sprintf(buffer, "%d", n);
write(1, buffer, len);
return (len);
}
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0, j;
specifier_t specifiers[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'d', print_int},
{'i', print_int},
{0, NULL}
};
va_start(args, format);
while (format && format[i] != '\0')
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
