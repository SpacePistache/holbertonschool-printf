#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
typedef struct specifier {
    char *format;
    int (*handler)(va_list);
} specifier_t;
int _printf(const char *format, ...) {
    specifier_t specifiers[] = {
        {"c", print_char},
        {"s", print_string},
        {"%", print_percent},
        {NULL, NULL}
    };
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