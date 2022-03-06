#include <stdio.h>
#include "stdlib.h"

typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};

struct Node * list_create ()
{
    struct Node *head = NULL;
    return head;
}
struct Node * list_push (struct Node * list, Data x)
{
    struct Node * lst = calloc(1, sizeof(struct Node));
    lst->val = x;
    lst->next = list;
    return lst;
}
struct Node * list_pop (struct Node * list, Data * px)
{
    struct Node* prev = NULL;
    prev = list;
    *px = prev->val;
    list = list->next;
    free(prev);
    return list;
}
struct Node * list_clear(struct Node * list)
{
    Data *trash;
    while (list->next != NULL)
        list_pop(list, trash);
    return list->next;
}
Data list_get(struct Node * list)
{
    return list->val;
}

void list_print (struct Node * list)
{
    struct Node * next = list;
    while (next->next != NULL)
    {
        printf("%d ", next->val);
        next = next->next;
    }
}

int list_size(struct Node * list)
{
    struct Node * next = list;
    int i = 1;
    while(next->next != NULL)
    {
        i++;
        next = next->next;
    }
    return i;
}
int main() {
    Data x;
    struct Node *list = list_create();
    list = list_push(list, 5);
    list_print(list);          // 5
    list = list_pop(list, &x);
    printf("x = %d\n", x);     // x = 5
    list = list_clear(list);
}
