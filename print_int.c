#include <unistd.h>
#include "main.h"
/**
* print_int - Affiche un entier
* @args: Liste des arguments contenant l'entier à afficher
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
write(1, "-", 1);
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
write(1, &buffer[j], 1);
len++;
}
return (len);
}
