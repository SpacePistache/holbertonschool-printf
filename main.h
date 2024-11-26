#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

#include <stdarg.h>
#include <stddef.h>
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int _putchar(char c);

typedef struct specifier {
    char spec;
    int (*func)(va_list args);
} specifier_t;

#endif
