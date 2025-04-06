//******slip no.10 qu 1*****
#include<stdio.h>
#define max 20
int a[20][20],n;
struct stack
{
    int data[max];
    int top;
};
struct stack s;
void push(int num)
{
   s.data[++s.top]=num;
}
int pop()
{
    return s.data[s.top--];
}
int isempty()
{
    return s.top==-1;
}
void topology(int a[20][20],int n,int v)
{
    int i,j;
    int visit[20]={0};
    int ind[20]={0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
    {
        ind[i]=ind[i]+a[j][i];
    }
}
while(1)
{
    for(i=0;i<n;i++)
    {
       if(ind [i]==0 && visit[i]==0)
        {
        push(i);
        visit[i]=1;
        printf("V%d",i+1);
        }
    }
    if(isempty())
    break;
     v=pop();
     for(j=0;j<n;j++)
   {
    if(a[v][j]==1)
    {
        ind[j]=ind[j]-1;
    }
  }
 
}
}
void main()
{
    int i,n,j;
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
	printf("Topology sort:");
	topology(a,n,0);
    printf("\n");
}







//******slip no.10 qu 2*****
#include<stdio.h>
#include<stdlib.h>
int a[20][20],n,i,j;
struct node
{
  int data;
  struct node *next;
};
struct node *head[20];
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
                printf("Enter edge between(V%d,V%d)",i+1,j+1);
                scanf("%d",&a[i][j]);
            }
        }
    }
}
void disp()
{
    printf("Adjeceny Matrix:\n");
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
void create()
{
    struct node *new,*temp;
    for(i=0;i<n;i++)
    {
        head[i]=NULL;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                new=(struct node *)malloc(sizeof(struct node));
                new->data=j+1;
                new->next=NULL;
                if(head[i]==NULL)
                {
                    head[i]=temp=new;
                    continue;
                }
                temp->next=new;
                temp=new;
            }
        }
    }
}
void displist()
{
    struct node *temp;
    printf("\nAdjecency list:\n");
    for(i=0;i<n;i++)
    {
        printf("\nV%d--->",i+1);
        for(temp=head[i];temp!=NULL;temp=temp->next);
        {
            printf("\t %d---->",temp->data);
        }
        printf("NULL\n");
    }

}
void main()
{
    accept();
    disp();
    create();
    displist();
}
