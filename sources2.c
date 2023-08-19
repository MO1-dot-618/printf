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
	for (j = i - 1; j >= 0; j—)
		print_number("%d", arr[j]);

    free(arr);
    return (size);
}
