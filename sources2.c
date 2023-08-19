#include "main.h"
#include <stdlib.h>

/**
 * rot13 - encodes a string using rot13
 * @s: input string.
 * Return: the pointer to dest.
 */

char *rot13(char *s)
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
				*(s + count) = rot13[i];
				break;
			}
		}
		count++;
	}

	return (s);
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

	switch (c)
	{
		case 'c':
			bytes += _putchar(va_arg(args, int));
			break;

		case 'd':
		case 'i':
			bytes += print_number(va_arg(args, int));
			break;

		case 's':
			bytes += _puts(va_arg(args, char*));
			break;
		case '%':
			bytes += _putchar('%');
			break;
		case 'b':
			bytes += binary(va_arg(args, int));
			break;
		case 'u':
			bytes += print_unsigned(va_arg(args, unsigned int));
			break;
	}
	return (bytes);
}

<<<<<<< HEAD
=======
/**
 * print_unsigned - prints an unsigned integer.
 * @m: input unsigned integer.
 * Return: number of digits
 */

int print_unsigned(unsigned int m)
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
>>>>>>> e74997d6acb6648dd8bc07a209a199c587555117
