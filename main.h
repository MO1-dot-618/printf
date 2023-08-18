#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>

void print_rev(char *s);
int _printf(const char *format, ...);
void _puts(char *str);
int _atoi(char *s);
int _putchar(char c);
char *rot13(char *s);
void print_number(int n);

#endif
