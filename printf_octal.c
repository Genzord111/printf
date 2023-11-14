#include "main.h"

/**
 * printf_octal - Starts to print a binary number
 * @num: Specifies the number of arguements
 * @printed: Specifies the printed characters
 * Return: The printed charcaters (Ends)
 */

int printf_octal(unsigned int num, int printed)
{
	int oct[100], i = 0, j;

	while (num != 0)
	{
		int remainder = num % 8;

		oct[i] = 48 + remainder;
		i++;
		num /= 8;
	}

	if (i == 0)
	{
		_putchar('0');
		printed++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(oct[j]);
			printed++;
		}
	}
	return (printed);
}
