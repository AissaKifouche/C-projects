#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
typedef struct list
{
    node *head;
}list;

int power(int a, int b )
{
    if (b==0)
    {
        return 1;
    }
    else if (b==1)
    {
        return a;
    }
    else return a*power(a,b-1);
}
long long DecToBin(int a)
{
    if (a==1 || a==0)
    {
        return a;
    }
    else
    {
        return DecToBin(a%2)+10*DecToBin(a/2); 
    }    
}
node *Reverse(node *h)
{
    if (h==NULL || h->next==NULL)
    {
        return h;
    }
    node *NewNode=Reverse(h->next);
    h->next->next=h;
    h->next=NULL;
    return NewNode;
}
bool palindrom(char word[], int start, int end)
{
    if (start==end)
    {
        return true;
    }
    else if (word[start]==word[end])
    {
        return palindrom(word,start+1,end-1);
    }
    else return false;
}
int MaxRec(int arr[],int size)
{
    if (size==1)
    {
        return arr[0];
    }
    if (arr[size-1]<MaxRec(arr,size-1))
    {
        return MaxRec(arr,size-1);
    }
    else
    {
        return arr[size-1];
    } 
}
int MaxIterWithGoto(int arr[], int size) {
    int current_size = size;
    int result;
    int max_rest;
    
recursive_entry:
    // Base case
    if (current_size == 1) {
        result = arr[0];
        goto return_result;
    }
    
    // Save current_size for after recursive call
    int saved_size = current_size;
    
    // Simulate recursive call
    current_size = current_size - 1;
    goto recursive_entry;
    
recursive_return:
    // After returning from recursive call
    current_size = saved_size;
    
    // Compare max_rest with the current element
    if (max_rest > arr[current_size - 1]) {
        result = max_rest;
    } else {
        result = arr[current_size - 1];
    }
    
return_result:
    // If we're at the top level, actually return
    if (current_size == size) {
        return result;
    } else {
        // Otherwise, propagate the result back up
        max_rest = result;
        goto recursive_return;
    }
}
main ()
{
    printf("%d",power(2,3));
    printf("\n%d",DecToBin(8));
    return 0;
}