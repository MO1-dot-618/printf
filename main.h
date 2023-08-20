#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

int pointer_conversion(intptr_t p);
int print_custom_s(char *str);
int print_unsigned(unsigned int);
int print_rev(char *s);
int _printf(const char *format, ...);
int _puts(char *str);
int _atoi(char *s);
int _putchar(int c);
int rot13(char *s);
int print_number(int n);
int switch_separator(char c, va_list args);
int number_conversion(long int n, unsigned int base, char cac);

#endif
