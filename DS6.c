#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void main()
{
	struct node* start=NULL;
	struct node* insert(struct node*, int);
	struct node* delete(struct node*, int);
	struct node* search(struct node*, int);
	void display(struct node*);
	int opt,data;
	do
	{
		printf("\n 1.Insert \n2.Delete \n3.Search \n4.Display \n5.Exit \n Enter your option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :printf("\nEnter data:\n");
				scanf("%d",&data);
				start=insert(start,data);
				break;
			case 2 :printf("\nEnter data to be deleted:\n");
				scanf("%d",&data);
				start=delete(start,data);
				break;
			case 3 :printf("\nEnter item to search:\n");
				scanf("%d",&data);
				if (search(start,data))
					printf("Found");
				else
					printf("Not Found");
				break;
			case 4 :display(start);
				break;
			case 5 :exit(0);
		}
	}
	while(1);
}

void display(struct node* s)
{
	if(s==(struct node*)0)
	{
		printf("List is empty\n");
		
	}
	while(s!=(struct node*)0)
	{
		printf("%d\t",s->data);
		s=s->right;
	}
	
}	

	
struct node* search(struct node* s,int item)
{
	struct node* t=s;
	while(t!=(struct node*)0 && t->data!=item)
		t=t->right;
	return t;
		
}

struct node* insert(struct node* s,int item)
{
	struct node* t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=item;
	t->left=(struct node*)0;
	t->right=s;
	if(s!=(struct node*)0)
		s->left=t;
	return t;
}

struct node* delete(struct node* s,int item)
{
	struct node* t;
	t=search(s,item);
	if(t!=(struct node*)0)
	{
		printf("%d is deleted \n",t->data);
		if(t->left==(struct node*)0 && t->right==(struct node*)0) //first node and one node
			s=(struct node*)0;
		else if(t->left==(struct node*)0)// first node
		{
			s=t->right;
			s->left=(struct node*)0;
		}
		else if(t->right==(struct node*)0)// last node
			t->left->right=(struct node*)0;
		else //middle node
		{
			t->left->right=t->right;
			t->right->left=t->left;
		}
		free(t);
	}
	else
	{
		printf("not found");
	}
	
		return s;
}
		
			
