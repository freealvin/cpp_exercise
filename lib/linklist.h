#ifndef _LINKLIST_H

struct node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;


List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( int x, List L );
void Delete( int X, List L );
Position FindPrevious( int x, List L );
void Insert( int x, List L, Position P );
void DeleteList( List L);
Position Header( List L );
Position First( List L );
Position Advance( Position p );
int Retrieve( Position p );
void Traversal( List L);
#endif

struct Node{
    int Element;
    PtrToNode Next;
};
