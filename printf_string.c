#include "main.h"

/**
 * printf_string - Starts to print a string
 * @args: Specifies the number of arguments
 * @printed: Specifies the printed characters
 * Return: The printed charcaters (Ends)
 */

int printf_string(va_list args, int printed)
{
	char *string = va_arg(args, char *);

	while (*string != '\0')
	{
		_putchar(*string);
		printed++;
		string++;
	}
	return (printed);
}
