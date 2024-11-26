#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0, j;
    if (!format) 
        return (-1);
    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++; 
            for (j = 0; specifiers[j].format != NULL; j++) {
                if (*(specifiers[j].format) == format[i]) { 
                    count += specifiers[j].handler(args);
                    break;
                }
            }
            if (specifiers[j].format == NULL) { 
                putchar('%');
                putchar(format[i]);
                count += 2;
            }
        } else {
            putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(args);
    return count;
}
int print_char(va_list args) {
    char c = va_arg(args, int);
    putchar(c);
    return (1);
}
int print_string(va_list args) {
    char *str = va_arg(args, char *);
    int i = 0;
    if (!str) 
        str = "(null)";
    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
    return (i);
}
int print_percent(va_list args) {
    (void)args; 
    putchar('%');
    return (1);
}