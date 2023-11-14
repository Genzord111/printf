#include "main.h"

/**
 * printf_binary - Start to print a binary number
 * @num: Specifies the number of arguements
 * @printed: Specifies the printed characters
 * Return: The printed charcaters (Ends)
 */

int printf_binary(unsigned int num, int printed)
{
	int binary[32] = {0};
	int i = 0;

	if (num == 0)
	{
		_putchar('0');
		printed++;
		return (printed);
	}

	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}

	while (i > 0)
	{
		i--;
		_putchar('0' + binary[i]);
		printed++;
	}

	return (printed);
}
