#include "main.h"
/**
 * handle_specifier - Gestion des spécificateurs dans _print
 * @spec: Spécificateur actue
 * @args: Liste d'arguments
 * @specifiers: Tableau des spécificateur
 * Return: Nombre de caractères imprim�
 */
int handle_specifier(char spec, va_list args, specifier_t *specifiers)
{
int j = 0;
while (specifiers[j].spec != 0)
{
if (spec == specifiers[j].spec)
{
return (specifiers[j].func(args));
}
j++;
}
_putchar('%');
_putchar(spec);
return (2);
}
