#include <stdio.h>
#include <iostream>
int main()
{
    using std::cout;
    int a = 10;
    int b = 10;
    int *ptr = &a;
    cout << ptr << "\n";
    cout << *ptr << "\n";
    cout << &ptr << "\n\n";

    cout << a << "\n";
    cout << &a << "\n";
    return 0;
}