#include <unistd.h>
#include "main.h"
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
