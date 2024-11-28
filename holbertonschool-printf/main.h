#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_entier(va_list args);
int print_int(va_list args);

typedef struct specifier {
    char spec;
    int (*func)(va_list args);
} specifier_t;
extern specifier_t specifiers[];

#endif
