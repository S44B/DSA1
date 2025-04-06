|||SLIP 21|||
\\Q 1)\\
#include <stdio.h>
void dfs(int a[20][20], int n, int i, int visit[20]) {
    visit[i] = 1;
    printf("V%d\t", i);

    for (int j = 0; j < n; j++) {
        if (a[i][j] == 1 && visit[j] == 0) {
            dfs(a, n, j, visit);
        }
    }
}

void main() {
    int n, a[20][20], visit[20] = {0};

    printf("Enter number of elements (nodes): ");
    scanf("%d", &n);


    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("DFS traversal starting from vertex V0:\n");
    dfs(a, n, 0, visit);
}









\\Q 2)\\
   #include<stdio.h>
int a[20][20],e,i,j,u,v,n,min,mincost,b,c;
void prims(int a[20][20],int n)
{
   int visit[20]={0};
   visit[0]=1;
   mincost=0;
   for(e=0;e<=n-1;e++)
    {
      for(i=0,min=999;i<n;i++)
       {
         for(j=0;j<n;j++)
          {
            if(a[i][j]<min)
             {
               if(visit[i]!=0 && visit[j] == 0)
                {
                  min=a[i][j];
                  u=i;
                  v=j;
                }
             }
          }
       }
       if(visit[u]==0 || visit[v]==0)
       {
          printf("\nEdege-%d-%dcost-%d",u+1,v+1,min);
          visit[v]=1;
          mincost+=min;
       }
       a[b][c]=a[c][b]=999;
    }
    printf("\nMincost=%d",mincost);
}
int main()
{
   
   printf("Enter no of rows and cols= ");
       scanf("%d",&n);
    printf("Enter elements of matrix=");
     for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
           {
                 scanf("%d",&a[i][j]);
                 if(a[i][j]==0)
                    a[i][j]=999;
           } 
      }
      prims(a,n);   
  printf("\n");
  for(i=0;i<n;i++)
    printf("\tV%d",i+1);
    
  for(i=0;i<n;i++)
   {
      printf("\nV%d\t",i+1);
      for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
   }   
}
