//******slip no.7 qu 1*****
#include <stdio.h>
#define max 10
int a[10][10];
int visit[10]={0};
int i,n,j;
struct queue
{
    int d[max];
    int front,rear;
}q;
struct queue q;
void init()
{
    q.front=q.rear=-1;
}
int isempty()
{
    return q.front==q.rear;
}
int isfull()
{
    return q.rear==max-1;
}
void add(int num)
{
    q.d[++q.rear]=num;
}
int rm()
{
    return q.d[++q.front];
}
void bfs(int a[10][10],int n,int v)
{
    init();
    for(int i=0;i<n;i++)
    {
        visit[i]=0;
    }
    add(v);
    visit[v];
    while(!isempty())
    {
        int v=rm();
        printf("V%d\t",v+1);
        for(int j=0;j<n;j++)
        {
            if(a[v][j]==1 && visit[j]==0)
            {
                add(j);
                visit[j]=1;
            }
        }
    }
}

void accept()
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
                printf("Enter the edge between(V%d,V%d)",i+1,j+1);
                scanf("%d",&a[i][j]);
            }
        }
    }
}
int main()
{
    accept();
    printf("Breate first Search:");
    bfs(a,n,0);
}





//******slip no.7 qu 2*****
#include <stdio.h>
int i,j,parent[20];
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
void kruscal(int a[20][20],int n)
{
    int min,e=1,i,j,u,v;
    int b,c,mincost=0;
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
            printf("\nEdge %d: %d- %d cost-%d",e++,b+1,c+1,min);
            mincost+=min;
        }
        a[b][c]=a[c][b]=999;
    }
    printf("\n Minimum cost: %d",mincost);
}
void main()
{
    int a[20][20],n,i,j;
    printf("Enter limit::");
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
    kruscal(a,n);
}
