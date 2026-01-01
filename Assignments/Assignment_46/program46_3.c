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
//  Function Name   :   IsEmpty
//  Description     :   Checks if linked list is empty
//  Input           :   PNODE
//  Output          :   Bool
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

bool IsEmpty(PNODE first)
{
    if(first == NULL)
    {
        return true;
    }

    return false;
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

    // InsertFirst(&head, 89);
    // InsertFirst(&head, 105);
    // InsertFirst(&head, 50);
    // InsertFirst(&head, 51);
    // InsertFirst(&head, 20);
    // InsertFirst(&head, 11);
    // InsertFirst(&head, 51);
    // InsertFirst(&head, 55);
    // InsertFirst(&head, 89);

    bRet = IsEmpty(head);

    if(bRet == true)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Linked list is not empty\n");
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Output  :   Linked list is empty
// 
////////////////////////////////////////////////////////////////////////////////////