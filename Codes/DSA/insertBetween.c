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


void insertBetween(struct node *head,struct node *add,int position){

    struct node *current = head;

    for(int i=0;i<position;i++){

        if (i == position -2)
        {
            add->next=current->next;
            current->next=add;
            break;
        }
        current= current->next;
    }

}


int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *last = (struct node *)malloc(sizeof(struct node));
    struct node *new = (struct node *)malloc(sizeof(struct node));

    head->data=10;
    second->data=20;
    third->data=30;
    last->data=40;
    new->data=70;

    head->next=second;
    second->next=last;
    last->next=NULL;

    travel(head);
    insertBetween(head,new,3);
    printf("After insertion:\n");
    travel(head);

}