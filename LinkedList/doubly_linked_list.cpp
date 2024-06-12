#include <stdio.h>
#include <iostream>
struct ListNode
{
    ListNode *prev;
    int data;
    ListNode *next;
};

int GetLength(ListNode *head);
void PrintDLL(ListNode **head);

int InsertDLLNode(ListNode **head, int position, int data);
void DeleteDLLNode(ListNode **head, int position);

int main()
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 2;

    // ListNode l1 = ListNode();
    // ListNode l2 = ListNode();
    // head->next = &l1;
    // l1.data = 3;
    // l1.prev = head;
    // l1.next = &l2;
    // l2.prev = &l1;

    printf("Length of LinkedList: %d \n", GetLength(head));

    InsertDLLNode(&head, 1, 10);
    printf("Length of LinkedList after insertion: %d \n", GetLength(head));
    InsertDLLNode(&head, 2, 11);
    printf("Length of LinkedList after insertion: %d \n", GetLength(head));
    InsertDLLNode(&head, 3, 12);
    printf("Length of LinkedList after insertion: %d \n", GetLength(head));
    PrintDLL(&head);

    DeleteDLLNode(&head, 5);
    DeleteDLLNode(&head, 1);
    DeleteDLLNode(&head, 4);
    printf("Length of LinkedList after deletion: %d \n", GetLength(head));
    DeleteDLLNode(&head, 1);
    printf("Length of LinkedList after deletion: %d \n", GetLength(head));
    return 1;
}

int GetLength(ListNode *head)
{
    if (!head)
    {
        printf("Empty DLL \n");
        return 0;
    }
    int k = 1;
    while (head->next != NULL)
    {
        k++;
        head = head->next;
    }
    return k;
}

int InsertDLLNode(ListNode **head, int position, int data)
{
    int k = 1;
    ListNode *p;
    p = *head;
    ListNode *el = (ListNode *)malloc(sizeof(ListNode));
    if (!el)
    {
        printf("Memory error");
    }
    el->data = data;
    if (position == 1)
    {
        el->next = *head;
        el->prev = NULL;
        if (*head)
        {
            (*head)->prev = el;
        }
        *head = el;

        printf("Inserted %d \n", data);
        return 1;
    }
    while ((k < position) && (p->next != NULL))
    {
        p = p->next;
        k++;
    }
    if (k != position)
    {
        printf("Position does not exist: %d \n", position);
        return 0;
    }
    el->next = p->next;
    el->prev = p;
    if (p->next)
        p->next->prev = el;
    p->next = el;
    printf("Inserted %d \n", data);
    return 1;
}
void DeleteDLLNode(ListNode **head, int position)
{
    ListNode *p;
    p = *head;
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position == 1)
    {
        if ((*head)->next)
        {
            *head = (*head)->next;
            (*head)->prev = NULL;
            free(p);
        }
        else
        {
            *head = NULL;
            free(*head);
        }
        return;
    }
    int k = 1;
    while ((k < position) && (p->next != NULL))
    {
        k++;
        p = p->next;
    }
    if (k != position)
    {
        printf("Position does not exist \n");
        return;
    }
    if (p->next)
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    else
    {
        p->prev->next = NULL;
    }
    free(p);
}
void PrintDLL(ListNode **head)
{
    ListNode *p;
    p = *head;
    while (p != NULL)
    {
        printf("prev: %d \n", p->prev);
        printf("data: %d \n", p->data);
        printf("next: %d \n\n", p->next);
        p = p->next;
    }
}