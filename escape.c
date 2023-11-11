#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * _escapechar - allows the use of escape characters
 * @n: character after backslash
 * Return: 1 if success
 */

int _escapechar(char n)
{
	if (n == 'n')
		_putchar('\n');
	else if (n == 't')
		_putchar('\t');
	else if (n == 'b')
		_putchar('\b');
	else if (n == '\'')
		_putchar('\'');
	else if (n == '?')
		_putchar('\?');
	else if (n == '\"')
		_putchar('\"');
	else
		_putchar(n);

	return (1);
}
