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

    if (prev == NULL)
    {
        printf("Out of range!\n");
        return ;
    }

    temp = curr;
    prev->Next = curr->Next;
    free(temp);
}

void insert(struct Node *node, size_t position, char ch)
{
    struct Node *curr = NULL;
    struct Node *prev = NULL;
    struct Node *new_node = NULL;
    size_t i = 0;

    prev = node;
    curr = node->Next;

    for (i = 1; i < position; i++)
    {
        prev = curr;
        curr = curr->Next;
    }

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->Element = ch;
    new_node->Next = curr;
    prev->Next = new_node;
}

void find(struct Node *node, char ch)
{
    size_t i = 0;

    while (node)
    {
        i++;
        node = node->Next;
        if (node->Element == ch)
        {
            printf("Found the element %c in the position %u\n", ch, i);
            return ;
        }
    }

    printf("Not found!");
}

int main( )
{
    char ch;
    List LinkedLists = NULL;
    Position P = NULL;
    size_t delete_pos = 0;

    LinkedLists = MakeEmpty(NULL);
    P = Header(LinkedLists);
    
    printf("Enter characters into the linked list and end with @: ");
    // Take values for stdin and store to the linked list
    while ((ch = getchar()) != '@' && ch != EOF)
    {
        Insert(ch, LinkedLists, P);    
    }
    printf("Elements in the linked list: ");
    PrintList(LinkedLists);
    putchar('\n');

    // Delete the elements from the linked list
    printf("Enter which number you want to delete: ");
    scanf("\n%u", &delete_pos);
    delete(LinkedLists, delete_pos);
    printf("The linked list after deleting the specific elements: ");
    PrintList(LinkedLists);
    putchar('\n');

    // Insert an element into the linked list
    printf("Enter the element that you want to insert to the linekd list: ");
    scanf("\n%c", &ch);
    printf("Enter a position to insert: ");
    scanf("\n%u", &delete_pos);
    printf("The elements after inserting: ");
    insert(LinkedLists, delete_pos, ch);
    PrintList(LinkedLists);
    putchar('\n');

    printf("Enter which element you want to find: ");
    scanf("\n%c", &ch);
    find(LinkedLists, ch);

    system("pause");
    return 0;
}
