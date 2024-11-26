#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
#include <stdarg.h>
#include <stddef.h>
int _putchar(char c);
typedef struct specifier {
    char spec;
    int (*func)(va_list args);
} specifier_t;
#endif
