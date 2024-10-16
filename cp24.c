#include<stdio.h>
void main()
{
	int ar1[20],ar2[20],ar3[40];
	int n1,n2;
	void readarray(int[],int);
	void printarray(int[],int);
	void sortarray(int[],int);
	void mergearray(int[],int,int[],int,int[]);
	printf("Enter the no.of elements of 1st array[1-20]:");
	scanf("%d",&n1);
	printf("\n Enter %d elements:",n1);
	readarray(ar1,n1);
	printf("\n Enter the no.of elements of 2nd array[1-20]:");
	scanf("%d",&n2);
	printf("\n Enter %d elements:",n2);
	readarray(ar2,n2);
	sortarray(ar1,n1);
	sortarray(ar2,n2);
	mergearray(ar1,n1,ar2,n2,ar3);
	printf("\n First array sorted:\n");
	printarray(ar1,n1);
	printf("\n second array sorted:\n");
	printarray(ar2,n2);
	printf("\n Merged array:\n");
	printarray(ar3,n1+n2);
}

	void readarray(int a[],int n)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	}
	
	void printarray(int a[],int n)
	{
		int i;
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
	}
	
	void sortarray(int a[],int n)
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		  for(j=i+1;j<n;j++)
		  	if(a[i]>a[j])
		  	{
		  		temp=a[i];
		  		a[i]=a[j];
		  		a[j]=temp;
		  	}
	}
	
	void mergearray(int a[],int n1,int b[],int n2,int c[])
	{
		int i,j,k;
		i=j=k=0;
		while(i<n1 && j<n2)
			if(a[i]<b[j])
			{
				c[k]=a[i];
				k++;
				i++;
			}
			else
			{
				c[k]=b[j];
				k++;
				j++;
			}
		while(i<n1)
			{
				c[k]=a[i];
				k++;
				i++;
			}
		while(j<n2)
			{
				c[k]=b[j];
				k++;
				j++;
			}	
	}
		
		
				
		
	
	
	
	
	
	
	
	
	
	
		  
