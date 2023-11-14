#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *print_binary(int num) {
    
    int bits = 0;
    int temp = num;
    char *binaryString;
    int index;

    while (temp > 0) {
        temp /= 2;
        bits++;
    }

    binaryString = (char *)malloc(bits + 1);
    if (binaryString == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }


    index = bits;
    binaryString[index] = '\0';  

    while (index > 0) {
        index--;
        binaryString[index] = num % 2 + '0';
        num /= 2;
    }

    return (binaryString);
}
