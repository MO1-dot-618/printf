#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>

int print_unsigned(unsigned int);
int print_rev(char *s);
int _printf(const char *format, ...);
int _puts(char *str);
int _atoi(char *s);
int _putchar(int c);
char *rot13(char *s);
int print_number(int n);
int switch_separator(char c, va_list args);
#endif
