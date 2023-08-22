#include "main.h"

/**
  * print_custom_s - print a custom string
  * @str: string
  * Return: number of char
  */

int print_custom_s(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			_putchar(92);
			_putchar('x');
			number_conversion(str[i], 'X');
		}
		else
			_putchar(str[i]);
	}
	return (i);
}

/**
  * pointer_conversion - converts to desired base
  * @p: pointer
  * Return: number of char
  */

int pointer_conversion(intptr_t p)
{
	int i = 0;
	int num;
	int digit;
	int zeros = 1;

	num = sizeof(p) * 2;

	_puts("0x");

	for (i = num - 1; i >= 0; i--)
	{
		digit = (p >> (4 * i)) & 0xF;
		if (digit != 0 || !zeros)
		{
			zeros = 0;
			number_conversion(digit, 'x');
		}
	}
	return (num);
}
/**
  * flag_checker - checks for flags and prints accordingly
  * @s: string
  * @args: va_list
  * Return: number of bytes printed
  */

int flag_checker(const char *s, va_list args)
{
	int num, bytes = 0;

	switch (*s)
	{
		case '+':
		case ' ':
			num = va_arg(args, int);
			if (num >= 0 && *(s + 1) == 'd')
				bytes += _putchar(*s);
			bytes += number_conversion(num, *(s + 1));
			break;
		case 'l':
			bytes += number_conversion(va_arg(args, long int), 'd');
			break;
		case 'h':
			bytes += number_conversion(va_arg(args, int), 'h');
			break;
	}
	return (bytes);
}
