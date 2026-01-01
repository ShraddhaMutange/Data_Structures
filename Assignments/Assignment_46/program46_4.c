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
//  Function Name   :   IsEmpty
//  Description     :   Checks if linked list is empty
//  Input           :   PNODE
//  Output          :   Bool
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void ReplaceNegative(PPNODE first)
{
    PNODE temp = NULL;

    temp = *first;
    while(temp != NULL)
    {
        if(temp->data < 0)
        {
            temp->data = 0;
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Display
//  Description     :   Displays elements present in linked list
//  Input           :   PPNODE
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
//  Entry point function for the application
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    bool bRet = false;

    InsertFirst(&head, -111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, -21);
    InsertFirst(&head, 11);

    printf("Before replacing : \n");
    Display(head);

    ReplaceNegative(&head);

    printf("After replacing : \n");
    Display(head);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Output  :   Before replacing : 
//              | 11 | -> | -21 | -> | 51 | -> | 101 | -> | -111 | -> NULL
//              After replacing : 
//              | 11 | -> | 0 | -> | 51 | -> | 101 | -> | 0 | -> NULL
// 
////////////////////////////////////////////////////////////////////////////////////