#include "main.h"

/**
 * printf_reverse - Starts to print a binary number
 * @args: Specifies the number of arguments
 * @printed: Specifies the printed characters
 * Return: The printed charcaters (Ends)
 */

int printf_reverse(va_list args, int printed)
{
	char *str = va_arg(args, char *);
	int len = 0, i;

	while (str[len])
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		printed++;
	}

	return (printed);
}
