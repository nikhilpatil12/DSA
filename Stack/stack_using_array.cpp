#include <stdio.h>
#include <iostream>
#define MAXSIZE 10;
struct ArrayStack
{
    int capacity;
    int top;
    int *array;
};
int SizeOfStack(ArrayStack *S);
int Push(ArrayStack *S, int data);
int Pop(ArrayStack *S);
int IsEmpty(ArrayStack *S);
int IsFull(ArrayStack *S);
void DeleteStack(ArrayStack *S);
int main()
{
    ArrayStack *S = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (!S)
    {
        printf("Memory error \n");
        return 0;
    }
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = (int *)malloc(sizeof(S->capacity * sizeof(int)));

    printf("IsEmpty: %d \n", IsEmpty(S));
    printf("IsFull: %d \n", IsFull(S));
    printf("Size of Stack: %d \n", SizeOfStack(S));
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    printf("IsFull: %d \n", IsFull(S));
    printf("IsEmpty: %d \n", IsEmpty(S));
    printf("Size of Stack: %d \n", SizeOfStack(S));

    printf("Popped: %d \n", Pop(S));
    // printf("Popped: %d \n", Pop(S));
    // printf("Popped: %d \n", Pop(S));
    // printf("Popped: %d \n", Pop(S));
    printf("IsFull: %d \n", IsFull(S));
    printf("IsEmpty: %d \n", IsEmpty(S));
    printf("Size of Stack: %d \n", SizeOfStack(S));
    DeleteStack(S);

    return 1;
}
int SizeOfStack(ArrayStack *S)
{
    if (S == NULL)
        return 0;
    return S->top + 1;
}
int Push(ArrayStack *S, int data)
{
    if (S->array == NULL)
    {
        printf("Memory error\n");
        return 0;
    }
    if (S->top + 1 >= S->capacity)
    {
        printf("Stack is full \n");
        return 0;
    }
    else
    {
        S->top++;
        (S->array[S->top]) = data;
    }
    return 1;
}
int Pop(ArrayStack *S)
{
    if (S->array == NULL)
    {
        printf("Memory Error\n");
        return -99999;
    }
    if (S->top == -1)
    {
        printf("Empty Stack \n");
        return -99999;
    }
    int popped = S->array[S->top--];
    printf("%d\n\n", popped);
    // S->top--;
    return popped;
}
int IsEmpty(ArrayStack *S)
{
    if (!S)
        return -9999;
    return S->top == -1;
}
int IsFull(ArrayStack *S)
{
    if (!S)
        return -9999;
    return S->top == S->capacity - 1;
}
void DeleteStack(ArrayStack *S)
{
    if (S)
    {
        if (S->array)
            free(S->array);
        S->top = -1;
        free(S);
        printf("Freed \n");
    }
}