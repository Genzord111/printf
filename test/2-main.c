#include <stdio.h>
#include "main.h"

int main(void)
{
    int count;

    count = _printf("Character: %c\n", 'A');
    printf("Count: %d\n\n", count);

    count = _printf("String: %s\n", "Hello, World!");
    printf("Count: %d\n\n", count);

    count = _printf("Percentage: %%\n");
    printf("Count: %d\n\n", count);

    count = _printf("Multiple Specifiers: %c %s %%\n", 'B', "Testing");
    printf("Count: %d\n\n", count);

    count = _printf("checking backslah \\ and \" and \'");
    printf("Count: %d\n\n", count);
    return 0;
}
