// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void travel(struct node *head)
// {

//     while (head != NULL)
//     {
//         printf("%d\n", head->data);
//         head = head->next;
//     }
// }

// struct node *createLinkList(int arr[], int len)
// {

//     struct node *head = (struct node *)malloc(sizeof(struct node));
//     struct node *new = (struct node *)malloc(sizeof(struct node));
//     struct node *temp = (struct node *)malloc(sizeof(struct node));

//     head = NULL;
//     temp = NULL;
//     new = NULL;

//     for (int i = 0; i < len; i++)
//     {
//         temp->data = arr[i];

//         if (head == NULL)
//         {
//             head->data = arr[i];
//             head->next = new;
//         }
//         else
//         {
//             new->data = arr[i];
//             new->next = NULL;
//         }

//         return head;
//     }
// }

// int main()
// {

//     int arr[] = {10, 20, 30, 40};

//     travel(createLinkList(arr, 4));
// }