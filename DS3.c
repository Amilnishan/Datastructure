#include<stdio.h>
#include<stdlib.h>
# define SIZE 10
int que[SIZE];
int front=-1,rear=-1;
void main()
{
	void enque(int);
	int deque();
	int search(int);
	int opt,data;
	do
	{
		printf("\n 1.Insert\n 2.Delete\n 3.Search\n 4.Exit\n Enter your option:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :printf("Enter the Data:\n");
				scanf("%d",&data);
				enque(data);
				break;
			case 2 :data=deque();
				printf("Deleted data:\n%d",data);
				break;
			case 3 :printf("Data to search:");
				scanf("%d",&data);
				search(data);
				if(search(data))
					printf("\n found");
				else
					printf("\n not found");
				break;
			case 4 :exit(0);
		}
	}
	while(1);
}

void enque(int item)
{
	if(rear==SIZE-1)
		printf("\n Queue is full");
	else
		rear++;
		que[rear]=item;
}

int deque()
{
	if(front==rear)
	{
		printf("Queue is empty");
		exit(1);
	}
		return que[++front];
}

int search(int item)
{
	int tfront=front;
	while(tfront!=rear && que[tfront]!=item)
		++tfront;
	if(que[tfront]==item)
		return 1;
		return 0;
		
}	
				
				
				
