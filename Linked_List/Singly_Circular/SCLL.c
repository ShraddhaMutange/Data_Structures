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
//  Description     :   Represents a node of Singly Circular Linked List
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
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
//  Input           :   PPNODE, PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(
                    PPNODE first,                           // Address of head pointer
                    PPNODE last,                            // Address of tail pointer
                    int no                                  // Number to insert       
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))                 // Case 1 : LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

    (*last)->next = *first;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertLast
//  Description     :   Inserts a new node at the end of the linked list
//  Input           :   PPNODE, PPNODE, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(
                    PPNODE first,                           // Address of head pointer
                    PPNODE last,                            // Address of tail pointer
                    int no                                  // Number to insert       
                )
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))                 // Case 1 : LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else                                                    // Case 2 : LL contains at least one node
    {
        temp = *first;

        (*last)->next = newn;
        *last = newn;        
    }

    (*last)->next = *first;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteFirst
//  Description     :   Deletes the first node from the linked list
//  Input           :   PPNODE, PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(
                    PPNODE first,                           // Address of head pointer
                    PPNODE last                            // Address of tail pointer  
                )
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        (*last)->next = *first;

        free(temp);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteLast
//  Description     :   Deletes the last node from the linked list
//  Input           :   PPNODE, PPNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(
                    PPNODE first,                           // Address of head pointer
                    PPNODE last                             // Address of tail pointer  
                )
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != *first)
        {
            temp = temp->next;
        }

        *last = temp;
        free(temp->next);
        
        (*last)->next = *first;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Display
//  Description     :   Displays all elements of the linked list
//  Input           :   PNODE, PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void Display(
                PNODE first,                                // head pointer
                PNODE last                                  // tail pointer  
            )
{
    do
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   Count
//  Description     :   Counts number of nodes present in the linked list
//  Input           :   PNODE, PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int Count(
            PNODE first,                                    // head pointer
            PNODE last                                      // tail pointer  
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
//  Description     :   Inserts a new node at a specified position in the linked list
//  Input           :   PPNODE, PPNODE, Int, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(
                    PPNODE first,                           // Address of head pointer
                    PPNODE last,                            // Address of tail pointer
                    int no,                                 // Number to insert       
                    int pos                                 // position
                )
{
    int iSize = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first, *last);

    if(pos < 1 || pos > iSize+1)
    {
        printf("Invalid Position\n");
        return;
    }

    if((*first == NULL) && (*last == NULL))
    {
        InsertFirst(first, last, no);
    }
    else if(*first == *last)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteAtPos
//  Description     :   Deletes a new node from a specified position in the linked list
//  Input           :   PPNODE, PPNODE, Int, Int
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   19/12/2025
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(
                    PPNODE first,                           // Address of head pointer
                    PPNODE last,                            // Address of tail pointer   
                    int pos                                 // position
                )
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first, *last);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid Position\n");
        return;
    }

    if((*first == NULL) && (*last == NULL))
    {
        DeleteFirst(first, last);
    }
    else if(*first == *last)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;

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