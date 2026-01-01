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
//  Function Name   :   Search
//  Description     :   Checks if an element is present in the linked list
//  Input           :   PNODE, Int
//  Output          :   Bool
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

bool Search(PNODE first, int iNo)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(first->data == iNo)
        {
            bFlag = true;
        }
        first = first->next;
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

    int iValue = 0;
    bool bRet = false;

    printf("Enter value to serach : \n");
    scanf("%d", &iValue);

    InsertFirst(&head, 121);
    InsertFirst(&head, 111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    bRet = Search(head, iValue);

    if(bRet == true)
    {
        printf("Element is present\n");
    }
    else
    {
        printf("Element is not present\n");
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   11      Output  :   Element is present
//  Input   :   121     Output  :   Element is present
//  Input   :   151     Output  :   Element is not present
// 
////////////////////////////////////////////////////////////////////////////////////