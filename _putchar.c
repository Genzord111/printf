#include "main.h"

/**
 * _putchar - Start to print character
 * @character: Specifies the character to print
 * Return: 1 when successful or  -1 if otherwise (Ends)
 */

int _putchar(char character)
{
	return (write(1, &character, 1));
}
