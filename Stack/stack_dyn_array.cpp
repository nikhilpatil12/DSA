#include <stdio.h>
#include <iostream>
struct DynArrayStack
{
    int capacity;
    int top;
    int *array;
};
int SizeOfStack(DynArrayStack *S);
void Push(DynArrayStack *S, int data);
int Pop(DynArrayStack *S);
int Top(DynArrayStack *S);
int IsEmpty(DynArrayStack *S);
int IsFull(DynArrayStack *S);
void DeleteStack(DynArrayStack *S);
int main()
{
    DynArrayStack *S = (DynArrayStack *)malloc(sizeof(DynArrayStack));
    if (!S)
    {
        printf("Memory error \n");
        return 0;
    }
    S->capacity = 1;
    S->top = -1;
    S->array = (int *)malloc(sizeof(S->capacity * sizeof(int)));

    printf("IsEmpty: %d \n", IsEmpty(S));
    printf("IsFull: %d \n", IsFull(S));
    printf("Size of Stack: %d \n", SizeOfStack(S));
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    printf("IsFull: %d \n", IsFull(S));
    printf("IsEmpty: %d \n", IsEmpty(S));
    printf("Size of Stack: %d \n", SizeOfStack(S));

    printf("Popped: %d \n", Pop(S));
    // printf("Popped: %d \n", Pop(S));
    // printf("Popped: %d \n", Pop(S));
    // printf("Popped: %d \n", Pop(S));
    printf("IsFull: %d \n", IsFull(S));
    printf("IsEmpty: %d \n", IsEmpty(S));

    printf("top: %d \n", Top(S));
    printf("Size of Stack: %d \n", SizeOfStack(S));
    DeleteStack(S);

    return 1;
}
int SizeOfStack(DynArrayStack *S)
{
    if (S == NULL)
        return 0;
    return S->top + 1;
}
void DoubleStackArray(DynArrayStack *S)
{
    S->capacity *= 2;
    S->array = (int *)realloc(S->array, S->capacity * sizeof(int));
}
void Push(DynArrayStack *S, int data)
{
    if (IsFull(S))
    {
        DoubleStackArray(S);
    }
    (S->array[++(S->top)]) = data;
    return;
}
int Pop(DynArrayStack *S)
{
    if (IsEmpty(S))
    {
        printf("Empty Stack \n");
        return -99999;
    }
    return S->array[S->top--];
}
int Top(DynArrayStack *S)
{
    if (IsEmpty(S))
    {
        printf("Empty Stack \n");
        return -99999;
    }
    return S->array[S->top];
}
int IsEmpty(DynArrayStack *S)
{
    if (!S)
        return -9999;
    return S->top == -1;
}
int IsFull(DynArrayStack *S)
{
    if (!S)
        return -9999;
    return S->top == S->capacity - 1;
}
void DeleteStack(DynArrayStack *S)
{
    if (S)
    {
        if (S->array)
            free(S->array);
        free(S);
        printf("Freed \n");
    }
}