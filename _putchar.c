#include "main.h"

/**
* _putchar - writes the character c to stdout
* @c: character to be printed
* Return: 1 oon success
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
