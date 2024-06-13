#include <stdio.h>
#include <iostream>
struct ListNode
{
    int data;
    ListNode *next;
};
void InsertAtFrontCLL(ListNode **head, int data);
void InsertAtBackCLL(ListNode **head, int data);

void DeleteFromFrontCLL(ListNode **head);
void DeleteFromBackCLL(ListNode **head);
int CountCLL(ListNode *head);
void PrintCLL(ListNode *head);

int main()
{
    ListNode *head = NULL;
    // head = (ListNode *)malloc(sizeof(ListNode));
    // head->next = head;

    // ListNode l1 = ListNode();
    // ListNode l2 = ListNode();
    // head->next = &l1;
    // l1.data = 2;
    // l1.next = &l2;
    // l2.data = 3;
    // l2.next = head;

    printf("Length is: %d \n", CountCLL(head));
    PrintCLL(head);

    InsertAtFrontCLL(&head, 11);
    InsertAtBackCLL(&head, 101);
    printf("Length after insertion at b n f is: %d \n", CountCLL(head));
    PrintCLL(head);

    InsertAtFrontCLL(&head, 10);
    InsertAtBackCLL(&head, 102);
    printf("Length after insertion at back is: %d \n", CountCLL(head));
    PrintCLL(head);

    DeleteFromFrontCLL(&head);
    DeleteFromBackCLL(&head);
    DeleteFromBackCLL(&head);
    DeleteFromBackCLL(&head);
    printf("Length after deletion from front is: %d \n", CountCLL(head));
    PrintCLL(head);
    return 1;
}

int CountCLL(ListNode *head)
{
    ListNode *current = head;
    int k = 0;
    if (head == NULL)
        return k;
    do
    {
        k++;
        current = current->next;
    } while (current != head);
    return k;
}
void PrintCLL(ListNode *head)
{
    ListNode *current = head;
    int k = 0;
    printf("Printing CLL: \n");
    if (head == NULL)
    {
        printf("Empty CLL \n");
        return;
    }
    do
    {
        k++;
        printf("data at %d: %d \n", k, current->data);
        current = current->next;
    } while (current != head);
    return;
}
void InsertAtFrontCLL(ListNode **head, int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode)
    {
        printf("Memmory error");
        return;
    }
    newNode->data = data;
    newNode->next = newNode;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    ListNode *current = *head;
    while (current->next != *head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void InsertAtBackCLL(ListNode **head, int data)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode)
    {
        printf("Memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = newNode;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    ListNode *current = *head;
    while (current->next != *head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head;
}

void DeleteFromFrontCLL(ListNode **head)
{
    if (head == NULL)
    {
        printf("Empty CLL \n");
        return;
    }
    ListNode *current = *head, *temp = *head;
    if ((*head)->next == *head)
    {
        *head = NULL;
        return;
    }
    while (current->next != *head)
    {
        current = current->next;
    }
    current->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
    return;
}
void DeleteFromBackCLL(ListNode **head)
{
    if (head == NULL)
    {
        printf("Empty CLL \n");
        return;
    }
    ListNode *current = *head, *prev;
    if ((*head)->next == *head)
    {
        *head = NULL;
        return;
    }
    while (current->next != *head)
    {
        prev = current;
        current = current->next;
    }
    prev->next = *head;
    free(current);
    return;
}