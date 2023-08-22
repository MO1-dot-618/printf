#ifndef MAIN_H
#define MAIN_H

#define FLAG_PLUS 0x01
#define FLAG_SPACE 0x02
#define FLAG_HASH 0x04
#define FLAG_ZERO 0x08
#define FLAG_NEG 0x10
typedef struct
{
	char chara;
	int type;
} flagtypes;

extern flagtypes flagtype[];

#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

int pointer_conversion(intptr_t p);
int print_custom_s(char *str);
int print_unsign(unsigned int);
int print_rev(char *s);
int _printf(const char *format, ...);
int _puts(char *str);
int _atoi(char *s);
int _putchar(int c);
int rot13(char *s);
int print_number(int n);
int switch_separator(char c, va_list args);
int number_conversion(long int n, char separator, int flags);

#endif
