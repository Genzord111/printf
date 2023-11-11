#include <stdarg.h>
#include <unistd.h>
#ifndef MAIN_H
#define MAIN_H
ssize_t write(int fd, const void *buf, size_t count);
int _putchar(char c);
int _printf(const char *format, ...);
int format_s(va_list args, char c, int count);
int print_number(int n, int count);
int print_string(char *str);
int print_char(char c);
#endif
