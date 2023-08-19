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
			number_conversion(str[i], 16, 'u');
		}
		else
			_putchar(str[i]);
	}
	return (i);
}
