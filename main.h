#ifndef MAIN_H
#define MAIN_H
int _printf(const char *format, ...);
typedef struct specifier {
    char spec;
    int (*func)(va_list args);
} specifier_t;
#endif
