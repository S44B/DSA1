//*******slip no.8 Question 1 *****
#include<stdio.h>
int i,n,j,a[20][20];
void dfs(int a[20][20],int n,int i)
{
	static int visit[20]={0};
	visit[i]=1;
	printf("V%d\t",i+1);
	for(j=0;j<n;j++)
	{
		if((a[i][j]==1) && (visit[j]==0))
		{
			visit[j]=1;
			dfs(a,n,j);
		}
	}
}
void main()
{
	printf("Enter no.of vertex::");
	scanf("%d",&n);
	printf("Enter Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
				printf("Enter the vertex between (V%d,V%d)",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("DFS:\t");
	dfs(a,n,0);
}



//slip8 Q2//


#include<stdio.h>
int i ,j,parent[20];
int find(int i)
{
while(parent[i])
i=parent[i];
return i;
}
int uni(int i,int j)
{
if(i!=j)
{
parent[j]=i;
return 1;
}
return 0;
}

void kruskal(int a[20][20],int n)
{
  int min,e=1,i,j,u,v;
  int b,c,mincost=0;
//  int visit[20]={0};
  
  while(e<n)
  {
   for(i=0,min=999;i<n;i++)
   for(j=0;j<n;j++)
      if(a[i][j]<min)
      {
      
      min=a[i][j];
      u=b=i;
      v=c=j;
      
    
    }
    u=find(u);
   v=find(v);
   if(uni(u,v)==1)
   {
      printf("\nEdge %d : %d-%d cost-%d",e++,b+1,c+1,min);
       //visit[v]=1;
       mincost+=min;
      }
       a[b][c]=a[c][b]=999;
   }
   
   printf("\nMinimun Cost%d",mincost);
   
  }


void main()
{
int a[20][20],n,i,j;
printf("Enter limit");
scanf("%d",&n);

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
if(a[i][j]==0)
  a[i][j]=999;
  }
  }
  kruskal(a,n);
}
