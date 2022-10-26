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

void swap(struct Node **node, int x, int y)
{
    struct Node *prevX = NULL, *currX = NULL;
    currX = *node;

    // Search for X
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    struct Node *prevY = NULL, *currY = NULL;
    currY = *node;
    // Search for Y
    while(currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not found, nothing to do
    if (currX == NULL || currY == NULL)
        return ;
    
    prevX->next = currY;
    prevY->next = currX;

    struct Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void reverse(struct Node **node)
{
    struct Node *prev = NULL, *curr = NULL, *next = NULL;
    
    curr = *node;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *node = prev;
}

void print(struct Node *node)
{
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    putchar('\n');
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
    print(node);
    swap(&node, 20, 9);
    print(node);
    reverse(&node);
    print(node);
    system("pause");
    return 0;
}