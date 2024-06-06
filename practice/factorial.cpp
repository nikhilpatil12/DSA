#include <stdio.h>
int main()
{
    int n = 20;
    double factorial = 1;
    while (n > 0)
    {
        factorial = n * factorial;
        n -= 1;
    }
    printf("%f", factorial);
    return 1;
}