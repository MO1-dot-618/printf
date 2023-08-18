#include "main.h"
/**
  * _printf - prints everything with zab
  * @format: specifier
  * Return: 0
  */



int _printf(const char *format, ...)
{
	int bytes = 0;
	char *str;
	const char *fmt = format;
	va_list args;

	va_start(args, format);
	_putchar(-2);
	while (fmt && *fmt)
	{
		if (*fmt == '%')
		{
			switch (*(fmt + 1))
			{
				case 'c':
					_putchar(va_arg(args, int));
					break;

				case 'd':
				case 'i':
					print_number(va_arg(args, int));
					break;

				case 's':
				{
					str = va_arg(args, char*);
					if (str != NULL)
						_puts(str);
					break;
				}
				case '%':
					_putchar('%');
					break;
			}
			fmt++;
		}
		else
			_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	_putchar(-1);
	return (0);
}
