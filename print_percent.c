#include <unistd.h>
#include "main.h"
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
