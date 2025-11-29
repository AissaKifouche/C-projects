#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
    {
        int data;
        struct node *next;
    }node;
bool isEmpty(node *h)
{
    return h==NULL;
}
node *createnode(int val)
{
    node *newnode=malloc(sizeof(node));
    if (newnode==NULL)
    {
        printf("memory allication failed\n");
        exit(1);
    }
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
node *InsertAtBegin(node *head,int val)
{
    node *temp;
    temp=createnode(val);
    temp->next=head;
    head=temp;
    return head;
}
node *InsertAtEnd(node *head,int val)
{
    if (isEmpty(head))
    {
        head=createnode(val);
    }
    else
    {
    node *temp;
    temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    node *p;
    p=createnode(val);
    temp->next=p;
    }
    return head;
}
node *InsertAtPosition(node *head,int val,int pos)
{
    if (pos<1)
    {
        printf("InvalidPosition\n");
        return;
    }
    else if(pos==1)
    {
        return InsertAtBegin(head,val);
    }
    else
    {
        node *temp;
        temp=head;
        for(int i=1;i<(pos-1)&&(temp!=NULL);i++)
        {
            temp=temp->next;
        }
        if (temp!=NULL)
        {
            temp->next=createnode(val);
        }
        else printf("\nPosition out of range\n");
    }
    return head;
}
void *newitem(node *head)
{
    printf("\nWhere do you want to insert the new element: \n1.At the begining, \n2.At the end, \n3.At a given position.");
    int choice;
    scanf("%d",&choice);
    printf("\nEnter the value you want to add: ");
    int val;
    scanf("%d",&val);
    switch (choice)
    {
        case 1:{head=InsertAtBegin(head,val);
        break;}
        case 2:{head=InsertAtEnd(head,val);
        break;}
        case 3:{
        printf("\nEnter the position you want to insert the new item at: ");
        int pos;
        scanf("%d",&pos);
        head=InsertAtPosition(head,val,pos);
        break;
        }
    }
}
void *displaylist(node *head)
{
    node *temp;
    temp=head;
    if (head!=NULL){
    printf("The data member of the elements of the list are :\n");
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    }
    else printf("There is no elements to desplay\n");
}
int nmbritems(node *head)
{
    if (head==NULL)    return 0;
    else
    {
        int i=0;
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            i++;
            temp=temp->next;
        }
        return i;
    }
}
node *RemoveByValue(node *head,int val)
{
    if (head==NULL) printf("There is nothing to remove \n");
    else
    {
        node *temp,*q;
        q=head;
        while (q->next!=NULL)
        {
            if ((q->next)->data==val)
            {
                temp=q->next;
                q->next=temp->next;
                free(temp);
                temp=NULL;
            }
            else q=q->next;
        }
        if (head->data==val)
        {
            q=head;
            head=head->next;
            free(q);
            q=NULL;
        }
    }
    return head;
}
int main()
{

    node *h;
    h=NULL;
    int n;
    do {
    h=newitem(h);
    printf("Do you want to add another element to the list?\n if YES enter 1 or any thing else for NO: ");
    scanf("%d",&n);
    }while (n==1);


    displaylist(h);
    h=RemoveByValue(h,22);
    displaylist(h);


    return 0;
}