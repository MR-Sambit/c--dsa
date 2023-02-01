#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}
    *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return 1;
}

void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = first;
    first = new_node;
}

void insert_at_position(int data, int position) {
    if (position == 1) {
        insert_at_beginning(data);
        return;
    }
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    struct Node *temp = first;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position not found.\n");
            return;
        }
    }
    node->next = temp->next;
    temp->next = node;
}


int Delete(struct Node *p,int index)
{
 struct Node *q=NULL;
 int x=-1,i;

 if(index < 1 || index > count(p))
 return -1;
 if(index==1)
 {
 q=first;
 x=first->data;
 first=first->next;
 free(q);
 return x;
 }
 else
 {
 for(i=0;i<index-1;i++)
 {
 q=p;
 p=p->next;
 }
 q->next=p->next;
 x=p->data;
 free(p);
 return x;

 }}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf(" %d -> ", p->data);
        p = p->next;
    }
}

int main()
{
    int A[100];
    int n, i;
    printf("Enter Array size :");
    scanf("%d", &n);
    printf("enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create(A, n);
    // Display(first);
    // printf("/n");
    // insert_at_position(5,2);
    // Display(first);

    Delete(first,1);
    Display(first);
    // Delete(first)
    return 0;
}
