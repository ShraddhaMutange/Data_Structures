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
//  Function Name   :   Count
//  Description     :   Counts elements present in linked list
//  Input           :   PNODE
//  Output          :   Int
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DisplayAtNthPos
//  Description     :   Displays alternate nodes
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DisplayAtNthPos(PNODE head, int pos)
{
    int iCnt = 0;
    int iSize = 0;

    PNODE temp = NULL;

    iSize = Count(head);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid Position\n");
        return;
    }

    temp = head;

    for(iCnt = 1; iCnt <= pos-1; iCnt++)
    {
        temp = temp->next;
    }

    printf("Value at %dth position is : %d\n", pos, temp->data);
    
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

    printf("Enter position : \n");
    scanf("%d", &iValue);

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

    DisplayAtNthPos(head, iValue);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Output  :   Enter position : 
//              2
//              Linked list : 
//              | 11 | -> | 21 | -> | 51 | -> | 5 | -> | 121 | -> NULL
//              Value at 2th position is : 21
// 
//  Output  :   Enter position : 
//              -1
//              Linked list : 
//              | 11 | -> | 21 | -> | 51 | -> | 5 | -> | 121 | -> NULL
//              Invalid Position
// 
//  Output  :   Enter position : 
//              6
//              Linked list : 
//              | 11 | -> | 21 | -> | 51 | -> | 5 | -> | 121 | -> NULL
//              Invalid Position
// 
//  Output  :   Enter position : 
//              4
//              Linked list : 
//              | 11 | -> | 21 | -> | 51 | -> | 5 | -> | 121 | -> NULL
//              Value at 4th position is : 5
// 
///////////////////////////////////////////////////////////////////////////////////////////////