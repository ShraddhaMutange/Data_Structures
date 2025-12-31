///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Required header files
// 
///////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Structure name  :   node
//  Description     :   Represents a node of Doubly Circular Linked List
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertFirst
//  Description     :   Inserts a new node at the beginning of the doubly circular linked list
//  Input           :   PPNODE, PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(
                    PPNODE first,                   // Stores the address of head pointer
                    PPNODE last,                    // Stores the address of tail pointer
                    int no                          // Stores value to insert
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        newn->next->prev = newn;
        *first = newn;
    }
    
    (*last)->next = *first;
    (*first)->prev = *last;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertLast
//  Description     :   Inserts a new node at the end of the doubly circular linked list
//  Input           :   PPNODE, PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(
                    PPNODE first,                   // Stores the address of head pointer
                    PPNODE last,                    // Stores the address of tail pointer
                    int no                          // Stores value to insert
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)  // LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteFirst
//  Description     :   Deletes the first node from the doubly circular linked list
//  Input           :   PPNODE, PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(
                    PPNODE first,                   // Stores the address of head pointer
                    PPNODE last                     // Stores the address of tail pointer
                )
{
    if((*first == NULL) && (*last == NULL))         // Case 1 : LL is empty
    {
        return;
    }
    else if(*first == *last)                        // Case 2 : LL contains only one node
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else                                            // Case 3 : LL contains mode than one element
    {
        *first = (*first)->next;
        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteLast
//  Description     :   Deletes the last node from the doubly circular linked list
//  Input           :   PPNODE, PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(
                    PPNODE first,                    // Stores the address of head pointer
                    PPNODE last                     // Stores the address of tail pointer
                )
{
    PNODE temp = NULL;

    if(*first == NULL)                              // Case 1 : LL is empty
    {
        return;
    }
    else if((*first)->next == NULL)                 // Case 2 : LL contains only one node
    {
        free(*first);
        *first = NULL;
    }
    else                                            // Case 3 : LL contains mode than one element
    {
        *last = (*last)->prev;
        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Display
//  Description     :   Displays all elements of the doubly circular linked list
//  Input           :   PNODE, PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void Display(
                PNODE first,                         // Head pointer of linked list
                PNODE last                          // Stores the address of tail pointer
            )
{
    do
    {
        printf("| %d | <=> ", first->data);
        first = first->next;
    }
    while(first != last->next);
    
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Count
//  Description     :   Counts number of nodes present in the doubly circular linked list
//  Input           :   PNODE, PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int Count(
                PNODE first,                         // Head pointer of linked list
                PNODE last                          // Stores the address of tail pointer
            )
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertAtPos
//  Description     :   Inserts a new node at a specified position in the doubly circular linked list
//  Input           :   PPNODE, PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(
                    PPNODE first,                   // Address of head pointer
                    PPNODE last,                    // Stores the address of tail pointer
                    int no,                         // Value to insert
                    int pos                         // Position
                )
{
    int iSize = 0;

    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    iSize = Count(*first, *last);

    if((pos < 1) || (pos > (iSize+1)))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        int iCnt = 0;

        temp = *first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;    // newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteAtPos
//  Description     :   Deletes a new node from a specified position in the doubly circular linked list
//  Input           :   PPNODE, PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(
                    PPNODE first,                   // Address of head pointer
                    PPNODE last,                    // Stores the address of tail pointer
                    int pos                         // Position
                )
{
    int iSize = 0;

    iSize = Count(*first, *last);

    PNODE temp = NULL;
    PNODE target = NULL;

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first, last);
    }
    else
    {
        int iCnt = 0;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;      // temp->next = temp->next->next;
        temp->next->prev = temp;
        free(target);
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;

    InsertFirst(&head, &tail, 121);
    InsertFirst(&head, &tail, 111);
    InsertFirst(&head, &tail, 101);

    Display(head, tail);
    
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    InsertLast(&head, &tail, 151);
    InsertLast(&head, &tail, 161);
    InsertLast(&head, &tail, 171);

    Display(head, tail);
    
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteFirst(&head, &tail);

    Display(head, tail);
    
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteLast(&head, &tail);

    Display(head, tail);
    
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    InsertAtPos(&head, &tail, 555, 4);

    Display(head, tail);
    
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    DeleteAtPos(&head, &tail, 4);

    Display(head, tail);
    
    iRet = Count(head, tail);
    printf("Number of nodes : %d\n", iRet);

    return 0;
}