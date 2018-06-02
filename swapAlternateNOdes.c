#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node *next;
};
 
void insert(struct node **temp, int data)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    struct node *last = *temp;  
   
    ptr->data  = data;
    ptr->next = NULL;
    
    if (*temp == NULL)
    {
       *temp = ptr;
       return;
    }
 
    while (last->next != NULL)
        last = last->next;

    last->next = ptr;
    return;
}

void swapNodes(struct node **head)
{

    struct node *prev = *head;
    struct node *cur = (*head)->next;
    struct node *ptr = *head;
    *head = cur;  

    if (*head == NULL || (*head)->next == NULL)
        return;
 
    while (ptr!=NULL)
    {
        struct node *next = cur->next;
        cur->next = prev; 

        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
 
        prev->next = next->next;
        prev = next;
        cur = prev->next;
	ptr=ptr->next;
    }
}

 
void printList(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
 

int main()
{
    struct node *head = NULL;
 
    insert(&head, 1);  
    insert(&head, 2); 
    insert(&head, 3);
    insert(&head, 4);

 
    printf("\n Linked list before swapping :");
    printList(head);
 
    swapNodes(&head);

    printf("\n Linked list after swapping : ");
    printList(head);
 
    return 0;
} 
