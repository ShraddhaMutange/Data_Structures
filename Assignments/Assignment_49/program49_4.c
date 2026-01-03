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
//  Function Name   :   CountDivByFive
//  Description     :   Counts elements divisible by five
//  Input           :   PNODE
//  Output          :   Int
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int CountDivByFive(PNODE head)
{
    int iCount = 0;

    while(head != NULL)
    {
        if(head->data % 5 == 0)
        {
            iCount++;
        }

        head = head->next;
    }

    return iCount;
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

    InsertLast(&head, 10);
    InsertLast(&head, 11);
    InsertLast(&head, 12);
    InsertLast(&head, 13);
    InsertLast(&head, 14);
    InsertLast(&head, 15);
    InsertLast(&head, 16);

    printf("Linked list : \n");
    Display(head);

    iRet = CountDivByFive(head);
    printf("Number of elements divisible by 5 is : %d\n", iRet);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   Linked list : 
//              | 10 | -> | 11 | -> | 12 | -> | 13 | -> | 14 | -> | 15 | -> | 16 | -> NULL
//  Output  :   Number of elements divisible by 5 is : 2
// 
///////////////////////////////////////////////////////////////////////////////////////////////