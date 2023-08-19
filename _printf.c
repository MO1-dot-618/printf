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

	va_start(args, fmt);
	_putchar(-2);
	while (fmt && *fmt)
	{
		if (*fmt == '%')
		{
			switch (*(fmt + 1))
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
			}
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
