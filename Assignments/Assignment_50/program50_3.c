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
//  Function Name   :   CheckSorted
//  Description     :   Checks whether list is sorted or not
//  Input           :   PNODE
//  Output          :   Bool
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

bool CheckSorted(PNODE head)
{
    bool bFlag = false;
    int iCurr = 0;
    int iNext = 0;

    PNODE temp = NULL;

    temp = head;

    while(temp->next->next != NULL)
    {
        iCurr = temp->data;
        iNext = temp->next->data;

        if(iCurr <= iNext)
        {
            bFlag = true;
        }
        else
        {
            bFlag = false;
        }

        temp = temp->next;
    }

    return bFlag;
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

    // InsertLast(&head, 11);
    // InsertLast(&head, 21);
    // InsertLast(&head, 51);
    // InsertLast(&head, 111);
    // InsertLast(&head, 121);

    InsertLast(&head, 11);
    InsertLast(&head, 21);
    InsertLast(&head, 51);
    InsertLast(&head, 5);
    InsertLast(&head, 121);

    printf("Linked list : \n");
    Display(head);

    bRet = CheckSorted(head);

    if(bRet == true)
    {
        printf("Linked list is sorted\n");
    }
    else
    {
        printf("Linked list is not sorted\n");
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   Linked list : 
//              | 11 | -> | 21 | -> | 51 | -> | 111 | -> | 121 | -> NULL
//              Linked list is sorted
// 
//  Input   :   Linked list : 
//              | 11 | -> | 21 | -> | 51 | -> | 5 | -> | 121 | -> NULL
//              Linked list is not sorted
// 
///////////////////////////////////////////////////////////////////////////////////////////////