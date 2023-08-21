#include "../main.h"
#include <stdio.h>
int main(void)
{
	int i = 8;
	void* ptr = &i;
	_printf("number 59 in octal : %o, binary : %b, hexa: %x %X\n", 59,59,59,59);
	_printf("memory address of pointer is : %p \n", ptr);
	printf("original : %p \n", ptr);
	_printf("hello in rot13: %R, reversed: %r \n", "hello", "hello");
	_printf("so plus is %+d or what\n", 43);

	return (0);
}
