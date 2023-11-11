#include <stdio.h>
#include "main.h"

int main(void)
{
int count;
char *q = "chi";
int p = -200;
char x = 'p';
int y = 10;
char *j = "co";

count =_printf("Hello %d world %s",y, j);
printf("%d\n",count);

count =_printf("Hello %d world %s",p, q);
printf("%d\n",count);

count =_printf("Hello world %d",p);
printf("%d\n",count);

count =_printf("Hello world %s",q);
printf("%d\n",count);

count =_printf("Hello world %c",x);
printf("%d\n",count);

return 1;
}
