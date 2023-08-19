#include "main.h"
/**
  * _printf - prints everything
  * @fmt: specifier
  * Return: number of bytes printed
  */



int _printf(const char *fmt, ...)
{
	int bytes = 0;
	va_list args;

	if (fmt == NULL)
	{
		return (0);
	}

	va_start(args, fmt);
	_putchar(-2);
	while (fmt && *fmt)
	{
		if (*fmt == '%')
		{
			bytes += switch_separator(*(fmt + 1), args);
			fmt++;
		}
		else
			bytes += _putchar(*fmt);
		fmt++;
	}
	va_end(args);
	_putchar(-1);
	return (bytes);
}
