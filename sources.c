#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print (ASCII code)
 *
 * Return: number of bytes printed.
 */
int _putchar(int c)
{
	static int count;
	int cc;
	static char buffer[1024];

	/**
	  * c == -2 means we are at the beginning of the function,
	  * so we initialize count to 0 to start the index of the buffer
	  * with 0.
	  * c == -1 means we are at the end of the function
	  * so we print whatever is left in the buffer
	  */
	if (c == -2)
	{
		count = 0;
		return (0);
	}
	else if (count == 1024)
	{
		write(1, buffer, 1024);
		count = 0;
		return (1024);
	}
	else if (c == -1)
	{
		write(1, buffer, count);
		cc = count;
		count = 0;
		return (cc);
	}
	else
	{
		buffer[count] = c;
		count++;
		return (0);
	}
}
/**
 * _puts - prints a string, followed by a new line.
 * @str: input string.
 * @byte: keeps count
 * Return: no return.
 */
int _puts(char *str)
{
	int count = 0;
	int byte = 0;

	while (str[count] != '\0')
	{
		byte = byte + _putchar(str[count]);
		count++;
	}
}
/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
/**
 * print_number - prints an integer.
 * @n: input integer.
 * Return: no return.
 */
void print_number(int n)
{
	unsigned int m, d, count;

	if (n < 0)
	{
		_putchar(45);
		m = n * -1;
	}
	else
	{
		m = n;
	}

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10)
	{
		_putchar(((m / count) % 10) + 48);
	}
}
/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s: input string.
 * Return: no return.
 */
void print_rev(char *s)
{
	int count = 0;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}

	for (count--; count >= 0; count--)
		_putchar(s[count]);
	_putchar('\n');
}
