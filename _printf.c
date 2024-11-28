#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
* _printf - Affiche une chaîne formatée
* @format: Chaîne de format avec des spécificateurs
* Return: Nombre de caractères affichés
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;

specifier_t specifiers[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'d', print_int}, {'i', print_int}, {0, NULL} };

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
