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

void cleanup(va_list args, buffer_t *output);
int run_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * cleanup - Start clean up for printf
 * @args: Specifies lists of  arguments
 * @output: Returns a buffer struct (Ends)
 */
void cleanup(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * run_printf - Start format string
 * @format: Specifies character string to print
 * @output: Returns a buffer struct
 * @args: Specifies a list of arguments
 * Return: The number of characters (Ends)
 */
int run_printf(const char *format, va_list args, buffer_t *output)
{
	int i, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		len = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(format + i + 1, &tmp);
			wid = handle_width(args, format + i + tmp + 1, &tmp);
			prec = handle_precision(args, format + i + tmp + 1,
					&tmp);
			len = handle_length(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(args, output);
	return (ret);
}

/**
 * _printf - Displays a formatted string
 * @format: Specifies character string to print
 * Return: The number of characters printed (Ends)
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = run_printf(format, args, output);

	return (ret);
}
