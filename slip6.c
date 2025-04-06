//*****slip no 6 . question no 1******

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





//******slip no.6 qu 2*****
#include <stdio.h>
int i,j,n;
void dij(int a[10][10])
{
    int d[20]={0},visit[20],min,v,k;
    i=0;
    visit[0]=1;
    d[0]=0;
    for(j=1;j<n;j++)
    {
        d[j]=a[i][j];
    }
    for(j=0;j<n;j++)
    {
        printf("%d\t",d[j]);
    }
    k=1;
    while(k<n-1)
    {
        min=999;
        for(j=1;j<n;j++)
        {
            if(d[j]<min && visit[j]==0)
            {
                min=d[j];
                v=j;
            }
        }
        visit[v]=1;
        for(j=1;j<n;j++)
        {
            if(d[v]+(a[v][j]>d[j]))
            {
                d[j]=d[v]+a[v][j];
            }
        }
        k++;
    }
    printf("\nDijktras shortest path \n)");
    for(j=0;j<n;j++)
    {
        printf("%d\t",d[j]);
    }
}
void main()
{
    int a[10][10];
    printf("Enter limit::");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    dij(a);
}
