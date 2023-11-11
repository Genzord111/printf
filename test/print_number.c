#include "main.h"

/**
 * print_number - writes an integer to stdout
 * @n: integer parameter to be printed
 * @count: tracks number of int printed
 * Return: count
 */

int print_number(int n, int count)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar(45);
		num = -num;
		count += 1;
	}
	if ((num / 10) != 0)
	{
		count = print_number((num / 10), count);
	}
	_putchar((num % 10) + '0');
	return (count + 1);
}
