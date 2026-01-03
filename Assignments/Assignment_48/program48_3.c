////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Structure name  :   node
//  Description     :   Represents a node of Singly linear Linked List
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertLast
//  Description     :   Inserts a new node at the end of the linked list
//  Input           :   PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
} 

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Display
//  Description     :   Displays elements present in linked list
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   MultiplyByTwo
//  Description     :   Multiplies each element by 2
//  Input           :   PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void MultiplyByTwo(PPNODE head)
{
    PNODE temp = NULL;

    temp = *head;

    while(temp != NULL)
    {
        temp->data = temp->data * 2;
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    InsertLast(&head, 10);
    InsertLast(&head, 11);
    InsertLast(&head, 12);
    InsertLast(&head, 13);
    InsertLast(&head, 14);
    InsertLast(&head, 15);
    InsertLast(&head, 16);

    printf("Linked list : \n");
    Display(head);

    printf("Linked list after multiplying each number by 2 : \n");
    MultiplyByTwo(&head);
    Display(head);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Output  :   Linked list : 
//              | 10 | -> | 11 | -> | 12 | -> | 13 | -> | 14 | -> | 15 | -> | 16 | -> NULL
//              Linked list after multiplying each number by 2 : 
//              | 20 | -> | 22 | -> | 24 | -> | 26 | -> | 28 | -> | 30 | -> | 32 | -> NULL
// 
////////////////////////////////////////////////////////////////////////////////////