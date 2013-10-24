#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/* Return true if L is empty */
int
IsEmpty( List L )
{
    return L->Next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int
IsLast( Position P, List L )
{
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position
Find( int X, List L )
{
    Position P;
    P = L->Next;
    while( P != NULL && P->Element != X )
    {
        P = P->Next;
    }

    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of a header node * */
void
Delete( int X, List L )
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if( !IsLast( P, L ) )
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free( TmpCell );
    }
}

Position
FindPrevious( int X, List L )
{
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element != X )
        P = P->Next;

    return P;
}

void Insert( int X, List L, Position P )
{
    Position TmpCell;

    TmpCell = (Position)malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        printf("Out of space");

    TmpCell->Element = X;
    TmpCell->Next= P->Next;
    P->Next = TmpCell;
}


void
DeleteList( List L )
{
    Position P;
    Position temp;

    P = L->Next;
    L->Next = NULL;
    while( P != NULL )
    {
        temp = P->Next;
        free( P );
        P= temp;
    }
}

void
Traversal( List L )
{
    Position P = L->Next;
    while ( P != NULL )
    {
        printf("%d " , P->Element);
        P = P->Next;
    }
    printf("\n");
}
