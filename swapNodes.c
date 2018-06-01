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

void swapNodes(struct node **head, int x, int y)
{
   struct node *prev1 = NULL, *cur1 = *head, *prev2 = NULL, *cur2 = *head,*temp;
   
   if (x == y) 
      return;
 
   while ((x-1)!=0)
   {
       prev1 = cur1;
       cur1 = cur1->next;
       x--;
   }
 
   while ((y-1)!=0)
   {
       prev2 = cur2;
       cur2 = cur2->next;
       y--;
   }
 
   if (cur1 == NULL || cur2 == NULL)
       return;
 
   if (prev1 != NULL)
       prev1->next = cur2;
   else 
       *head = cur2;  
 
   if (prev2 != NULL)
       prev2->next = cur1;
   else  
       *head = cur1;
 

   temp = cur2->next;
   cur2->next = cur1->next;
   cur1->next  = temp;
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
 
    int pos1,pos2;

    insert(&head, 1);  
    insert(&head, 2); 
    insert(&head, 3);
    insert(&head, 4);

    printf("Position 1:");
    scanf("%d",&pos1);
    printf("Position 2:");
    scanf("%d",&pos2);
 
    printf("\n Linked list before swapping :");
    printList(head);
 
    swapNodes(&head, pos1, pos2);

    printf("\n Linked list after swapping : ");
    printList(head);
 
    return 0;
} 
