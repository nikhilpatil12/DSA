#include <stdio.h>
int main()
{
    int a = 0;
    int b = 1;
    int c;
    int n = 10;
    printf("%d \n", a);
    printf("%d \n", b);
    while (n - 2 > 0)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%d \n", c);
        n--;
    }
    return 0;
}