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
//  Function Name   :   Frequency
//  Description     :   Counts how many times a number appears in the linked list
//  Input           :   PNODE, Int
//  Output          :   Int
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int Frequency(PNODE first, int no)
{
    int iCount = 0;

    while(first != NULL)
    {
        if(first->data == no)
        {
            iCount++;
        }
        first = first->next;
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
    int iValue = 0;

    printf("Enter value : \n");
    scanf("%d", &iValue);

    InsertFirst(&head, 51);
    InsertFirst(&head, 1114);
    InsertFirst(&head, 51);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 10);

    iRet = Frequency(head, iValue);

    printf("Number of odd values is : %d\n", iRet);    // 4

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   51      Output  :   3
//  Input   :   21      Output  :   1
//  Input   :   11      Output  :   0
// 
////////////////////////////////////////////////////////////////////////////////////