#include <stdio.h>
#include <iostream>
struct ListNode
{
    int data;
    struct ListNode *next;
};
int ListLength(ListNode *head);
void InsertAt(ListNode **head, int position, int element);
void DeleteAt(ListNode **head, int position);
void PrintSinglyLinkedList(ListNode *head);
int main()
{
    using std::cout;
    using std::endl;
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->data = 2;

    cout << "Count = " << ListLength(head) << endl;
    PrintSinglyLinkedList(head);

    InsertAt(&head, 1, 21);
    InsertAt(&head, 2, 22);
    InsertAt(&head, 3, 23);
    InsertAt(&head, 4, 24);

    InsertAt(&head, 1, 11);
    InsertAt(&head, 2, 12);
    InsertAt(&head, 3, 13);
    InsertAt(&head, 4, 14);

    cout << "Count = " << ListLength(head) << endl;
    PrintSinglyLinkedList(head);

    DeleteAt(&head, 1);
    cout << "Count After Delete 1= " << ListLength(head) << endl;
    PrintSinglyLinkedList(head);
    DeleteAt(&head, 3);
    cout << "Count After Delete 3= " << ListLength(head) << endl;
    PrintSinglyLinkedList(head);
    DeleteAt(&head, 2);
    cout << "Count After Delete 2= " << ListLength(head) << endl;
    PrintSinglyLinkedList(head);
    DeleteAt(&head, 4);
    cout << "Count After Delete 4= " << ListLength(head) << endl;
    PrintSinglyLinkedList(head);
}

int ListLength(ListNode *head)
{
    int count = 0;
    ListNode *current = head;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}
void InsertAt(ListNode **head, int position, int element)
{
    int k = 1;
    ListNode *p, *q, *newNode;

    newNode = (ListNode *)malloc(sizeof(ListNode));
    if (!newNode)
    {
        printf("Memory error");
        return;
    }
    newNode->data = element;
    p = *head;
    if (position == 1)
    {
        newNode->next = p;
        *head = newNode;
    }
    else
    {
        while (k < position)
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
    return;
}
void DeleteAt(ListNode **head, int position)
{
    ListNode *p, *q;
    int k = 1;

    p = *head;
    if (position == 1)
    {
        *head = p->next;
        free(p);
    }
    else
    {
        while (p != NULL && k < position)
        {
            k++;
            q = p;
            p = p->next;
        }

        if (p == NULL)
            printf("Position does not exist");
        else
        {
            q->next = p->next;
            free(p);
        }
    }
}

void PrintSinglyLinkedList(ListNode *head)
{
    ListNode *p;
    p = head;
    int k = 1;
    printf("Singly Linked List:\n");
    while (p != NULL)
    {
        printf("%d: %d\n", k++, p->data);
        p = p->next;
    }
}