#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * _putchar - Écrit un caractère sur la sortie standard
 * @c: Le caractère à écrire
 *
 * Return: 1 si succès, -1 si erreur
 */
int _putchar(char c)
{
return write(1, &c, 1);
}
/**
 * print_char - Prints a character
 * @args: Argument list containing the character to print
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
_putchar(c);
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
_putchar(str[i]);
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
_putchar('%');
return (1);
}
/**
 * print_int - Affiche un entier
 * @args: Liste des arguments contenant l'entier à affiche
 *
 * Return: Le nombre de caractères affich�
 */
int print_int(va_list args)
{
int n = va_arg(args, int);
char buffer[12];
int len = 0;
int i = 0;
int j;
if (n < 0)
{
_putchar('-');
n = -n;
len++;
}
if (n == 0)
{
buffer[i++] = '0';
}
else
{
while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n = n / 10;
}
}
for (j = i - 1; j >= 0; j--)
{
_putchar(buffer[j]);
len++;
}
return len;
}
/**
 * _printf - Affiche une chaîne forma
 * @format: Chaîne de format avec des spécificat
 *
 * Traite la chaîne de format et affiche les ar selon les s
 * Prend en charge %c, %s, %d, %i et %%.
 *
 * Return: Nombre de caractères affich
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0, j;
specifier_t specifiers[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'d', print_int}, {'i', print_int}, {0, NULL}
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
_putchar('%');
_putchar(format[i]);
count += 2;
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
