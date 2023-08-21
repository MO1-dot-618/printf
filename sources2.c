#include "main.h"
#include <stdlib.h>

/**
 * rot13 - encodes a string using rot13
 * @s: input string.
 * Return: the pointer to dest.
 */

int rot13(char *s)
{
	int count = 0, i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (*(s + count) != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (*(s + count) == alphabet[i])
			{
				_putchar(rot13[i]);
				break;
			}
		}
		count++;
	}

	return (count);
}

/**
  * binary - converts to binary
  * @num: number to convert
  * Return: num of characters
  */

int binary(int num)
{
	int j = 0;
	int *arr;
	int size = 0;
	int i = 0;
	int temp = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	temp = num;
	while (temp > 0)
	{
		temp /= 2;
		size++;
	}

	arr = malloc((size) * sizeof(int));

	while (num > 0)
	{
		arr[i++] = num % 2;
		num /= 2;
	}
	for (j = i - 1; j >= 0; j--)
		print_number(arr[j]);
	free(arr);
	return (size);
}

/**
 * switch_separator - switch through operators
 * @c: specifier
 * @args: argument in question
 * Return: number of bytes
*/
int switch_separator(char c, va_list args)
{
	int bytes = 0;
	int flag_i;
	int flag;

	switch (c)
	{
		case 'c':
			bytes += _putchar(va_arg(args, int));
			break;
		case 'd':
		case 'i':
		case 'b':
		case 'o':
		case 'x':
		case 'X':
			bytes += number_conversion(va_arg(args, int), c, flags);
			break;
		case 's':
			bytes += _puts(va_arg(args, char*));
			break;
		case '%':
			bytes += _putchar('%');
			break;
		case 'u':
			bytes += print_unsign(va_arg(args, unsigned int));
			break;
		case 'p':
			bytes += pointer_conversion((intptr_t) va_arg(args, void*));
			break;
		case 'S':
			bytes += print_custom_s(va_arg(args, char*));
			break;
		case 'R':
			bytes += rot13(va_arg(args, char*));
			break;
		case 'r':
			bytes += print_rev(va_arg(args, char*));
			break;
		case '+':
		case ' ':
			flag_i = 0;
			 while (flagtype[flag_i].chara != 0)
			 {
				  if (flagtype[flag_i].chara == c)
				  {
					  break;
				  }
				  flag_i++;
			 }
			 if (flagtype[flag_i].chara != 0)
			 {
				 flag = flagtype[flag_i].flag;
				  bytes += number_conversion(va_arg(args, int), c, flag);
			 }
			 break;
	}
	return (bytes);
}


/**
 * print_unsign - prints an unsigned integer.
 * @m: input unsigned integer.
 * Return: number of digits
 */

int print_unsign(unsigned int m)
{
	unsigned int d, count, c = 0;

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
		c++;
	}

	for (; count >= 1; count /= 10)
	{
		_putchar(((m / count) % 10) + 48);
	}
	return (c + 1);
}

/*
  * number_conversion - converts to desired base
  * @specifier: char
  * @n: number
  * Return: number of char
  */
int number_conversion(long int n, char specifier, int flags)
{
	unsigned int m, d, base, count, p, c = 0;

	if (specifier == 'd' || specifier == 'i')
		base = 10;
	else if (specifier == 'x' || specifier == 'X')
		base = 16;
	else if (specifier == 'o')
		base = 8;
	else if (specifier == 'b')
		base = 2;
	if (n < 0)
	{
		_putchar(45);
		m = n * -1;
		c++;
	}
	if (n >= 0 && (flags & FLAG_PLUS))
	{
		 _putchar('+');
		 c++;
	}
	else if (n >= 0 && (flags & FLAG_SPACE))
	{
		 _putchar(' ');
		 c++;
	}

	else
		m = n;
	d = m;
	count = 1;
	while (d > (base - 1))
	{
		d /= base;
		count *= base;
		c++;
	}
	for (; count >= 1; count /= base)
	{
		p = ((m / count) % base) + 48;
		if (p <= 57)
			_putchar(p);
		else if (specifier == 'X')
			_putchar(p + 7);
		else if (specifier == 'x')
			_putchar(p + 39);
	}
	return (c + 1);
}
