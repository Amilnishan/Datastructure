#include<stdio.h>
#include<stdlib.h>

	int u,v,n,i,j,ne=1,k,ru,rv;
	int parent[9],min,mincost=0,cost[9][9];
	
	int find(int u)
	{
		while(parent[u])
			u=parent[u];
		return u;
	}
	
	void uni(int ru,int rv)
	{
		parent[rv]=ru;
	}
void main()
{
	printf("Enter the no.of vertices:");
	scanf("%d",&n);
	printf("\n Enter the cost adjacency matrix:");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		{
			cost[i][j]=999;
		}
	printf("The edge of minimum cost spanning tree are :\n");
	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cost[i][j]<min)
				{
					min=cost[i][j];
					u=i;
					v=j;
				}
	ru=find(u);
	rv=find(v);
	if(ru!=rv)
	{
		uni(ru,rv);	
		printf("\n%d Edge (%d,%d)=%d\n",ne++,u,v,min);
		mincost=mincost+min;
	}
	cost[u][v]=cost[v][u]=999;
	}
	printf("\n Minimum cost=%d\n",mincost);
}	
	
	
