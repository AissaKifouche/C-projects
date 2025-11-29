#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data,priority;
    struct node *next;
}node;
typedef struct PrioQueue
{
    node *front,*rear;
}PrioQueue;
node *CreateNode(int val,int prio)
{
    node *NewNode=malloc(sizeof(node));
    if (NewNode==NULL)
    {
        printf("Memory allocation failed\n");
        exit;
    }
    NewNode->data=val;
    NewNode->next=NULL;
    NewNode->priority=prio;
    return NewNode;
}
void CreatePrioQueue(PrioQueue *q)
{
    q->front=NULL;
    q->rear=NULL;
}
bool IsEmpty(PrioQueue *q)
{
    return q->front==NULL;
}
void EnQueue(PrioQueue *q,int val,int prio)
{
    node *p=CreateNode(val,prio);
    if (q->front==NULL|| prio < q->front->priority )
    {
        p->next=q->front;
        q->front=p;
    }
    else
    {
        node *temp=q->front;
        while ( temp->next!=NULL && temp->priority <= prio )
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
}
int Dequeue(PrioQueue *q)
{
    node *p=q->front;
    q->front=q->front->next;
    int a=p->data;
    return a;
    free(p);
}
int Count(PrioQueue q)
{
    int i=0;
    
    if (q.front!=NULL)
    {
        node *p=q.front;
        i=1;
        while (p!=q.rear)
        {
            p=p->next;
            i++;
        }
    }
    return i;
}
void Display(PrioQueue *q)
{
    if (IsEmpty(q))
    {
        printf("There is no elemnt in the queue\n");
    }
    else
    {
        node *p=q->front;
        printf("The elements of the queue are:\n");
        printf("%d\n",p->data);
        while (p!=q->rear)
        {
            p=p->next;
            printf("%d\n",p->data);
        }
    }
}
int main ()
{
    
}