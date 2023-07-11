#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void travel(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertLast(struct node *add,struct node *ptr, struct node *head)
{

  while (ptr)
  {
    if (ptr->next == NULL)
    {
        ptr->next=add;
        add->next=NULL;
        break;
    }
    
    ptr= ptr->next;

  }
  
    return head;

}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *middle = (struct node *)malloc(sizeof(struct node));
    struct node *last = (struct node *)malloc(sizeof(struct node));
    struct node *new = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = middle;

    middle->data = 20;
    middle->next = last;

    last->data = 30;
    last->next = NULL;

    new->data = 50;

    travel(head);

    printf("\nAfter insertion:\n");

    travel(insertLast(new,head,head));

}