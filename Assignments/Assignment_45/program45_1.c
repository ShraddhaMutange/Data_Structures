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
//  Function Name   :   InsertFirst
//  Description     :   Inserts a new node at the beginning of the linked list
//  Input           :   PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DisplayOdd
//  Description     :   Displays only odd numbers from the linked list
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DisplayOdd(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        if(first->data % 2 == 1)
        {
            printf("%d\t", first->data);
        }
        first = first->next;
    }

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    int iRet = 0;
    InsertFirst(&head, 67);
    InsertFirst(&head, 105);
    InsertFirst(&head, 50);
    InsertFirst(&head, 51);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);
    InsertFirst(&head, 22);
    InsertFirst(&head, 45);
    InsertFirst(&head, 89);

    DisplayOdd(head);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Output  :  89	45	11	51	105	67
// 
////////////////////////////////////////////////////////////////////////////////////