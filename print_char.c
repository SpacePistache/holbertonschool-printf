#include <stdarg.h>
#include "main.h"
/**
 * print_char - Affiche un caractèr
 * @args: Liste des arguments contenant le caractère à affich
 *
 * Return: Nombre de caractères imprimés (1)
 */
int print_char(va_list args)
{
char c = va_arg(args, int);
_putchar(c);
return 1;
}
