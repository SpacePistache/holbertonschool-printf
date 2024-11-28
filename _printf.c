#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Formats and prints a string
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
specifier_t specifiers[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'d', print_int},
{'i', print_int},
{0, NULL}
};
if (format == NULL)
{
return (-1);  /* Return -1 if format is NULL */
}
va_start(args, format);
while (format && format[i] != '\0')
{
if (format[i] == '%')
{
i++;
count += handle_specifier(format[i], args, specifiers);
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
