//******slip no.2 qu 1*****
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





//*****slip no 2. question no 2*****
#include<stdio.h>
#include<stdlib.h>
#define memory (struct node *)malloc(sizeof(struct node))
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
struct node *create(struct node *root)
{
	struct node *new,*temp,*parent;
	int i,n;
	printf("Enter no.of nodes::");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new=memory;
		printf("Enter %d node values:",i+1);
		scanf("%d", &new->data);
		new->left=new->right=NULL;
		if(root==NULL)
		{
			root=new;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
				parent=temp;
			if(new->data<temp->data)
			temp=temp->left;
			else
			temp=temp->right;
		}

		if(new->data<parent->data)
		parent->left=new;
		else
		parent->right=new;
	}
	return root;
}
int search(struct node *root,int key)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		if(temp->data==key)
		return 1;
		else if(key<temp->data)
		return search(temp->right,key);
	}
	return 0;
}
void inorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
   {
	inorder(temp->left);
	printf("%d\t",temp->data);
	inorder(temp->right);
   }	
}
void main()
{
    struct node *root=NULL;
	int ch,key,result;
	do{
		printf("\n**MENU**\n1.Create\n2.Search\n3.Inorder\n3.Enter YOur Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			break;
			case 2:printf("Enter key to search::");
			scanf("%d",&key);
			result=search(root,key);
			if(result==1)
			printf("Key Found");
			else
			printf("Key Not Found>.......!");
			break;
			case 3:inorder(root);
		}
	}while(ch<5);
}
