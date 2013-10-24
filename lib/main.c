#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>
int main()
{
    List L = (List)malloc( sizeof( struct Node ) );
    L->Next = NULL;

    printf( "IsEmpty:%d\n", IsEmpty(L) );
    Insert(2, L, L);
    Insert(1, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Traversal( L );
    printf("Deleting List\n");
    DeleteList(L);
    printf("List deleted\n");
    return 0;
}
