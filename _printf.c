#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>

int format_s(va_list args, char c, int count)
{
	int num_var;
	char *str_var;
	char char_var;


        switch (c)
        {
                case 'd':
                        num_var = va_arg(args, int);
                        count = print_number(num_var, count);
                        break;
                case 's':
                        str_var = va_arg(args, char *);
                        count += print_string(str_var);
                        break;
                case 'c':
                        char_var = va_arg(args, int);
                        count += print_char(char_var);
                        break;
                case 'b':
                        num_var = va_arg(args, int);
                        str_var = print_binary(num_var);
			count += strlen(str_var);
			print_string(str_var);
                        break;


                default:
                        _putchar(c);
                        count += 1;
        }


        return count;
}

int print_number(int n, int count)
{
        unsigned int num;
        num = n;

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


        return count + 1;
}

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
                return i;
        }
        return 0;
}

int print_char(char c)
{
        _putchar(c);

        return 1;
}

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
                        count = format_s(args, format[i+1], count);
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

        return count;
}
