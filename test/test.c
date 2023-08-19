#include "../main.h"
#include <stdio.h>
int main(void)
{
	int i = 8;
	void* ptr = &i;
	_printf("number 59 in octal : %o, binary : %b, hexa: %x %X\n", 59,59,59,59);
	_printf("memory address of pointer is : %p \n", ptr);
	printf("original : %p \n", ptr);
	_putchar(-2);
	print_custom_s("bob is \n");
	_putchar(-1);
	return (0);
}
