#include "../main.h"
#include <stdio.h>
int print_octal(int n, unsigned int base, char cac)
{
	unsigned int m, d, count, p, c = 0;

	if (n < 0)
	{
		_putchar(45);
		m = n * -1;
		c++;
	}
	else
	{
		m = n;
	}

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
		else if (cac == 'u')
			_putchar(p + 7);
		else if (cac == 'l')
			_putchar(p + 39);
	}
	return (c + 1);
}	
int main(void)
{
	_putchar(-2);
	print_octal(59, 16, 'u');
	print_octal(59, 16, 'l');
	print_octal(59, 10, 'u');
	print_octal(59, 8, 'u');
	print_octal(59, 2, 'u');
	_putchar(-1);
	return (0);
}
