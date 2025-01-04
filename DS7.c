#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};

void main()
{
	struct node *root = NULL;
	struct node *insert(struct node *,int);
	struct node *search(struct node *,int);
	struct node *delete(struct node *,int);
	void display(struct node *);
	int opt,data;
	do
	{	
		printf("\n 1.Insert \n 2.Delete \n 3.Search \n 4.Display \n 5.Exit \n Enter your Option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
		
		case 1 :printf("Enter data:\n");
			scanf("%d",&data);
			root=insert(root,data);
			break;
		case 2 :printf("Enter data to delete :");
			scanf("%d",&data);
			root=delete(root,data);
			break;
		case 3 :printf("Enter data to search:");
			scanf("%d",&data);
			if(search(root,data))
				printf("Item found");
			else
				printf("Item not found");
			break;
		case 4 :printf("Binary Search Tree \n");
			display(root);
			break;
		case 5 :exit(0);
		}
	}
	while(1);
}

struct node *insert(struct node *root,int data)
{
	struct node *t,*t1=root;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=data;
	t->left=t->right=NULL;
	if(root == NULL)
		root =t;
	else
	{
		while(t1 != NULL && t1->data != data)
		{
			if(data < t1->data)
			{
				if(t1->left == NULL)
				{
					t1->left=t;
					break;
				}
				t1=t1->left;
			}
			else
			{
				if(t1->right == NULL)
				{
					t1->right=t;
					break;
				}
				t1=t1->right;
			}
		}
		if(t1 != NULL && t1->data == data)
		{
			printf("Duplicate Element not allowed \n");
			free(t);
		}
	}
	return root;
}

struct node *search(struct node *root,int data)
{
	while(root != NULL && root -> data != data)
	{
		if(data < root->data)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}

struct node *delete(struct node *root,int data)
{
	struct node *t1 = root,*t2 = NULL;
	while(t1 != NULL && t1->data != data)
	{
		t2=t1;
		if(data < t1->data)
			t1 = t1->left;
		else
			t1 = t1->right;
	}
	if(t1 == NULL)
	{
		printf("Node not found\n");
		return root;
	}
	if(t1->left == NULL && t1->right == NULL)
	{
		if(t2 == NULL)
			root = NULL;
		else if(t2->left == t1)
			t2->left = NULL;
		else
			t2->right = NULL;
		free(t1);
	}
	else if(t1->left == NULL || t1->right == NULL)
	{
		struct node *child = (t1->left != NULL)?t1->left:t1->right;
		if(t2 == NULL)
			root = child;
		else if(t2->left == t1)
			t2->left = child;
		else
			t2->right = child;
		free(t1);
	}
	else
	{
		struct node *sucpar = t1;
		struct node *t1 = t1->right;
		while(t2->left != NULL)
		{
			sucpar = t2;
			t2 = t2->left;
		}
		t1->data = t2->data;
		if(sucpar->left == t2)
			sucpar->left = t2->right;
		else
			sucpar->right = t2->right;
		free(t1);
	}
	printf("data deleted \n");
	return root;
}

void display(struct node *root)
{
	if(root != NULL)
	{
		display(root->left);
		printf("%d\t",root->data);
		display(root->right);
	}
}

	
