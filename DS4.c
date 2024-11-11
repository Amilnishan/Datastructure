#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int que[SIZE];
int rear=0,front=0;//empty queue
void main()
{
	int opt,data;
	void enque(int);
	int deque();
	int search(int);
	do
	{
		printf("\nCircular Que operations: \n 1.Insert \n 2.Delete \n 3.Search\n 4.exit\n Enter your option:\n ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :printf("Enter the data:\n");
				scanf("%d",&data);
				enque(data);
				break;
			case 2 :data=deque();
				if(data!=-1)
				printf("Deleted data is : %d\n",data);
				break;
			case 3 :printf("Enter data to search:\n");
				scanf("%d",&data);
				if(search(data))
					printf("Found");
				else
					printf("Not found");
				break;
			case 4 :exit(0);
				break;
			default:printf("invalid input");
				break;
		}
	}
	while(1);
}

void enque(int data)
{
	int trear=rear;
	trear=(trear+1)%SIZE;
	if(trear==front)
		printf("Que is full");
	else
	{
		rear=trear;
		que[rear]=data;
		return;
	}
}

int deque()
{
	if(front==rear)
	{
		printf("Que is empty");
		return -1;
	}	
	else
	{
		front=(front+1)%SIZE;
		return que[front];
	}
}

int search(int item)
{
	int tfront;
	tfront=(front+1)%SIZE;
	while(tfront!=rear && que[tfront]!=item)	
		tfront=(tfront+1)%SIZE;
	if(que[tfront]==item)
		return 1;
	else
		return 0;
}
	
