#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int format_s(va_list args, char c, int count);
int print_number(int n, int count);
int print_string(char *str);
char *print_binary(int num);
int print_char(char c);
#endif
