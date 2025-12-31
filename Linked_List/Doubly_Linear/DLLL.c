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
//  Description     :   Represents a node of Doubly linear Linked List
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
//  Description     :   Inserts a new node at the beginning of the doubly linear linked list
//  Input           :   PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(
                    PPNODE first,                   // Stores the address of head pointer
                    int no                          // Stores value to insert
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        newn->next->prev = newn;
        *first = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertLast
//  Description     :   Inserts a new node at the end of the doubly linear linked list
//  Input           :   PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(
                    PPNODE first,                   // Stores the address of head pointer
                    int no                          // Stores value to insert
                )
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)  // LL is empty
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
        newn->prev = temp;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteFirst
//  Description     :   Deletes the first node from the doubly linear linked list
//  Input           :   PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(
                    PPNODE first                    // Stores the address of head pointer
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
        temp = *first;
        *first = (*first)->next;
        (*first)->prev = NULL;
        free(temp);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteLast
//  Description     :   Deletes the last node from the linked list
//  Input           :   PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(
                    PPNODE first                    // Stores the address of head pointer
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
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Display
//  Description     :   Displays all elements of the linked list
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void Display(
                PNODE first                         // Head pointer of linked list
            )
{
    while(first != NULL)
    {
        printf("| %d | <=> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Count
//  Description     :   Counts number of nodes present in the linked list
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int Count(
                PNODE first                         // Head pointer of linked list
            )
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
//  Function Name   :   InsertAtPos
//  Description     :   Inserts a new node at a specified position in the doubly linear linked list
//  Input           :   PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(
                    PPNODE first,                   // Address of head pointer
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

    iSize = Count(*first);

    if((pos < 1) || (pos > (iSize+1)))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first, no);
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
//  Description     :   Deletes a new node from a specified position in the linked list
//  Input           :   PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(
                    PPNODE first,                   // Address of head pointer
                    int pos                         // Position
                )
{
    int iSize = 0;

    iSize = Count(*first);

    PNODE temp = NULL;
    PNODE target = NULL;

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
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
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet);


    InsertLast(&head, 121);
    InsertLast(&head, 111);
    InsertLast(&head, 101);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet); 

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet); 

    InsertAtPos(&head, 105, 3);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet); 

    DeleteAtPos(&head, 3);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet);

    return 0;
}