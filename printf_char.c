#include "main.h"

/**
 * printf_char - Starts to print a binary number
 * @args: Specifies the arguements to use
 * @printed: Specifies the printed characters
 * Return: The printed charcaters (Ends)
 */

int printf_char(va_list args, int printed)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (printed + 1);
}
