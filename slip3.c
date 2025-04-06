//*****slip no 3 . question no 1******

#include<stdio.h>
void main()
{
	int a[20][20],i,n,j;
	printf("Enter no.of vertex::");
	scanf("%d",&n);
	printf("Enter Matrix\n::");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]==0;
			if(i!=j)
			{
				printf("Enter the edge between(V%d,V%d)",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("Adjecency matrix\n");
	for(i=0;i<n;i++)
	{
			printf("\tV%d",i+1);
		}
		for(i=0;i<n;i++)
		{
			printf("\nV%d\t",i+1);
			for(j=0;j<n;j++)
			{
				printf("%d\t",a[i][j]);
			}
		}
	}







//****slip no 3.2********

#include<stdio.h>
void prims(int a[20][20],int n)
{
	int i,j,u,v,e,min,mincost=0,visit[20]={0};
	visit[0]=1;
	for(e=0;e<n-1;e++)
	{
		for(i=0,min=999;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]<min)
				{
					if(visit[i]!=0)
					{
						min=a[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		if(visit[i]==0 || visit[j]==0)
		{
		printf("\nEdges(V%d,V%d):%d",i+1,j+1,min);
		visit[v]=1;
		mincost=mincost+min;
	}
	a[u][v]=a[v][u]=999;
}
printf("MINcost%d::",mincost);
}

void main()
{
    int a[20][20],i,j,n;
    printf("Enter no. of vertex:\n");
    scanf("%d",&n);
    printf("Enter matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            a[i][j]=999;
        }
    }
    printf("Cost matrix:\n");
    for(i=0;i<n;i++)
    {
        printf("\tV%d",i+1);
    }
    for(i=0;i<n;i++)
    {
        printf("\nV%d\t",i+1);
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    prims(a,n);
}
