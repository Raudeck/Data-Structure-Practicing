#include "list.h"
#include "fatal.h"

void
PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%c ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}

void delete(struct Node *node, size_t position)
{
    struct Node *curr = NULL;
    struct Node *prev = NULL;
    struct Node *temp = NULL;
    size_t i = 0;
    prev = node;
    curr = node->Next;

    for (i = 1; i < position; i++)
    {
        prev = curr;
        curr = curr->Next;
    }

    temp = curr;
    prev->Next = curr->Next;
    free(temp);
}

int main( )
{
    char ch;
    List LinkedLists = NULL;
    Position P = NULL;

    LinkedLists = MakeEmpty(NULL);
    P = Header(LinkedLists);
    
    // Take values for stdin and store to the linked list
    while ((ch = getchar()) != '#' && ch != EOF)
    {
        Insert(ch, LinkedLists, P);    
    }
    printf("Elements in the linked list: ");
    PrintList(LinkedLists);
    putchar('\n');

    // Delete the elements from the linked list
    delete(LinkedLists, 1);
    printf("The linked list after deleting the specific elements: ");
    PrintList(LinkedLists);
    putchar('\n');
    //ToDo()
    system("pause");
    return 0;
}
