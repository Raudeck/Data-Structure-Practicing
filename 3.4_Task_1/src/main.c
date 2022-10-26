#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void push(struct Node **node, int data)
{
    if (*node == NULL)
    {
        *node = (struct Node *)malloc(sizeof(struct Node));
        (*node)->data = data;
        (*node)->next = NULL;
        tail = *node;
    }
    else
    {
        tail->next = (struct Node *)malloc(sizeof(struct Node));
        tail->next->data = data;
        tail->next->next = NULL;
        tail = tail->next;
    }
}

int main()
{
    struct Node *node = NULL;
    push(&node, 34);
    push(&node, 56);
    push(&node, 20);
    push(&node, 9);
    push(&node, 15);
    push(&node, 5);

    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    putchar('\n');

    system("pause");
    return 0;
}