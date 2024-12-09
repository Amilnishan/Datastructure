#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void main()
{
	struct node* start=(struct node*)0;
	struct node* insert(struct node*,int);
	struct node* delete(struct node*);
	void display(struct node*);
	int opt,data;
	printf("\nSingly Linked List \n");
	do
	{
		printf("\n 1.Insert\n 2.Delete \n 3.Display\n 4.Exit\n Enter your option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :printf("Enter the data:\n");
				scanf("%d",&data);
				start=insert(start,data);
				break;
			case 2 :start=delete(start);
				break;
			case 3 :display(start);
				break;
			case 4 :exit(0);
			default:printf("Invalid input\n");
				break;
		}
	}
	while(1);
}

struct node* insert(struct node* s,int item)
{
	struct node* t;//declaring t variable
	t=(struct node*)malloc(sizeof(struct node));//allocating memory size
	t->data=item;
	t->next=s;
	return t;
}

struct node* delete(struct node* s)
{
	struct node* t=s;
	if(s!=(struct node*)0)
	{
		printf("%d deleted \n ",s->data);
		s=s->next;
		free(t);
		return s;
	}
	else
	{
		printf("Empty list\n");
		exit(0);
	}	
}

void display(struct node* s)
{
	while(s!=(struct node*)0)
	{
		printf("%d\t",s->data);
		s=s->next;
	}	
}
		
