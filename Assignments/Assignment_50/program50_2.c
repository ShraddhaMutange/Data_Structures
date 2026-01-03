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
//  Function Name   :   DisplayGreaterThanAvg
//  Description     :   Displays elements greater than the average
//  Input           :   PNODE
//  Output          :   Void
//  Author          :   Shraddha Dhananjay Mutange
//  Date            :   1/1/2026
// 
///////////////////////////////////////////////////////////////////////////////////////////////

void DisplayGreaterThanAvg(PNODE head)
{
    float fAvg = 0.0f;
    float fSum = 0.0f;
    int iTotal = 0;

    PNODE temp = NULL;

    temp = head;

    while(temp != NULL)
    {
        fSum = fSum + temp->data;
        temp = temp->next;
        iTotal++;
    }

    fAvg = fSum / iTotal;

    // printf("Average : %f\nTotal : %d\n", fAvg, iTotal);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data > fAvg)
        {
            printf("%d\t", temp->data);
        }

        temp = temp->next;
    }

    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Entry point function for the application
// 
///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    InsertLast(&head, 5);
    InsertLast(&head, 10);
    InsertLast(&head, 15);
    InsertLast(&head, 27);
    InsertLast(&head, 3);

    printf("Linked list : \n");
    Display(head);

    printf("Elements greater than average : \n");
    DisplayGreaterThanAvg(head);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Testcases handled succesfully by the application
// 
//  Input   :   Linked list : 
//              | 5 | -> | 10 | -> | 15 | -> | 27 | -> | 3 | -> NULL
//              Elements greater than average : 
//              15	27
// 
///////////////////////////////////////////////////////////////////////////////////////////////