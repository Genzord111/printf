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
	else if (c == '%')
	{
		_putchar(37);
		count += 1;
	}
	else
	{
		_putchar(c);
		count += 1;
	}
	return (count);
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
		else if (format[i] == '\\')
		{
			if (format[i + 1] == '\\')
			{
				_putchar(92);
				count += 1;
				i = i + 2;
			}
			else
			{
				count = _escapechar(format[i + 1]);
				i++;
			}
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
