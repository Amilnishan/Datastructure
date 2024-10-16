#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int sp=-1;//empty stack
int main()
	{
		int opt,data;
		void push(int);
		int pop();
		void display();
		do
		{
			printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
			printf("Your Option:\n");
			scanf("%d",&opt);
			switch(opt)
			{
				case 1: printf("Enter Data:\n");
					scanf("%d",&data);
					push(data);
					break;
				case 2: data=pop();
					printf("Poped data : %d\n",data);
					break;
				case 3: display();
					break;
				case 4: exit(0);
			}
		}
		while(1);
	}	
	
	void push(int data)
	{
		if(sp==SIZE-1)
			printf("full stack");
		else
			stack[++sp]=data;
	}
	
	int pop()
	{
		if(sp==-1)
		{
			printf("empty stack");
			exit(1);
		}
		else
			return stack[sp--];
	}
	
	void display()
	{
		int tsp=sp;
		printf("stack contents:\n");
		while(tsp!=-1)
		{
			printf("%d,",stack[tsp]);
			tsp--;
		}
		return;
	}
