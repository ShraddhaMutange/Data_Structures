////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

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
//  Function Name   :   DisplayGreater
//  Description     :   Displays number greater than X in the linked list
//  Input           :   PNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DisplayGreater(PNODE first, int no)
{
    while(first != NULL)
    {
        if(first->data > no)
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

    int iValue = 0;

    printf("Enter value : \n");
    scanf("%d", &iValue);

    InsertFirst(&head, 89);
    InsertFirst(&head, 105);
    InsertFirst(&head, 50);
    InsertFirst(&head, 51);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);
    InsertFirst(&head, 51);
    InsertFirst(&head, 55);
    InsertFirst(&head, 89);

    printf("Numbers greater than %d are : \n", iValue);
    DisplayGreater(head, iValue);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   50      Output  :   89	55	51	51	105	89
//  Input   :   51      Output  :   89	55	105	89
//  Input   :   100     Output  :   105
// 
////////////////////////////////////////////////////////////////////////////////////