#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node * link;
	int info;
};
void push(struct node **head,int data)
{
	struct node* next;
	next=(struct node*)malloc(sizeof(struct node));
	next->info=data;
	next->link=*head;
	*head=next;
}
void nfromend(struct node *head,int n)
{
	struct node *hd=head;
	struct node *ref=head;
	int count=0;
	if(head!=NULL)
	{
		while(count<n)
		{
			if(ref==NULL)
			{
				printf("The value of n is greater than the number of nodes");
			}
			ref=ref->link;
			count++;
		}

		while(ref!=NULL)
		{
			ref=ref->link;
			hd=hd->link;
		}
	printf("%d\n",head->info );
    }
    else
    {
    	printf("Linked List does not exist");
    }
}
int main()
{
	struct node *head=NULL;
	push(&head,4);
	push(&head,15);
	push(&head,25);
	push(&head,42);
	nfromend(head,3);
	return 0;
}