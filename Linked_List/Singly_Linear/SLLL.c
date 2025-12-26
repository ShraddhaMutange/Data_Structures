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
//  Description     :   Represents a node of Singly linear Linked List
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

    if(*first == NULL)  // LL is empty
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   InsertLast
//  Description     :   Inserts a new node at the end of the linked list
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
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Function Name   :   DeleteFirst
//  Description     :   Deletes the first node from the linked list
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
        printf("| %d | -> ", first->data);
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
//  Description     :   Inserts a new node at a specified position in the linked list
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
        temp->next = newn;

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
    int ch = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    PNODE head = NULL;

    do
    {
        printf("Enter your choice\n1. Insert first\n2. Insert Last\n3. Insert at Position\n4. Delete first\n5. Delete Last\n6. Delete at postion\n7. Display LL\n8. Count\n9. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value you want to insert : ");
            scanf("%d", &iValue);
            InsertFirst(&head, iValue);

            Display(head);
            break;

        case 2:
            printf("Enter value you want to insert : ");
            scanf("%d", &iValue);
            InsertLast(&head, iValue);

            Display(head);
            break;

        case 3:
            printf("Enter value you want to insert : ");
            scanf("%d", &iValue);

            printf("Enter position : ");
            scanf("%d", &iPos);

            InsertAtPos(&head, iValue, iPos);

            Display(head);
            break;

        case 4:
            DeleteFirst(&head);
            printf("First node deleted\n");

            Display(head);
            break;

        case 5:
            DeleteLast(&head);
            printf("Last node deleted\n");

            Display(head);
            break;

        case 6:
            printf("Enter position to delete : ");
            scanf("%d", &iPos);

            DeleteAtPos(&head, iPos);

            Display(head);
            break;

        case 7:
            Display(head);
            break;

        case 8:
            iRet = Count(head);
            printf("Number of nodes : %d\n", iRet);
            break;
        
        default:
            break;
        }
    }while(ch != 9);

    return 0;
}