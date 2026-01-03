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
//  Function Name   :   Display
//  Description     :   Displays elements present in linked list
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int CountDigits(int iNo)
{
    int iDigit = 0;

    while(iNo != 0)
    {
        iDigit++;
        iNo = iNo / 10;
    }

    return iDigit;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   CountTwoDigitNos
//  Description     :   Counts elements with 2 digits
//  Input           :   PNODE
//  Output          :   Int
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int CountTwoDigitNos(PNODE head)
{
    int iCount = 0;
    int iNo = 0;

    while(head != NULL)
    {
        iNo = head->data;

        if(CountDigits(iNo) == 2)
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
    InsertLast(&head, 111);
    InsertLast(&head, 12);
    InsertLast(&head, 113);
    InsertLast(&head, 14);

    printf("Linked list : \n");
    Display(head);

    iRet = CountTwoDigitNos(head);
    printf("Total 2-Digit numbers : %d\n", iRet);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   Linked list : 
//              | 10 | -> | 111 | -> | 12 | -> | 113 | -> | 14 | -> NULL
//  Output  :   Total 2-Digit numbers : 3
// 
///////////////////////////////////////////////////////////////////////////////////////////////