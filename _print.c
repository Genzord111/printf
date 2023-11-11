#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * format_s - checks the type of format specifier
 * @args: list of infinite variables
 * @c: character to be checked
 * @count: tracks number of char printed
 * Return: count
 */

int format_s(va_list args, char c, int count)
{
	int num_var;
	char *str_var;
	char char_var;

	if (c == 'd')
	{
		num_var = va_arg(args, int);
		count = print_number(num_var, count);
	}
	else if (c == 's')
	{
		str_var = va_arg(args, char *);
		count += print_string(str_var);
	}
	else if (c == 'c')
	{
		char_var = va_arg(args, int);
		count += print_char(char_var);
	}
	else
	{
		_putchar(c);
		count += 1;
	}
	return (count);
}

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

/**
 * print_string - writes a string to stdout
 * @str: string parameter to be printed
 * Return: count
 */

int print_string(char *str)
{
	int i = 0;

	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
		return (i);
	}
	return (0);
}

/**
 * print_char - writes a character to stdout
 * @c: char parameter to be printed
 * Return: count
 */

int print_char(char c)
{
	if (c != NULL)
	{
		_putchar(c);
		return (1);
	}
	return 0;
}
/**
 * _printf - produces output according to a format similar to printf.
 * @format: string parameter to be printed
 * Return: count
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list args;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count = format_s(args, format[i + 1], count);
			i++;
		}
		else
		{
			_putchar(format[i]);
			count += 1;
		}
		i++;
	}

	va_end(args);
	return (count);
}
