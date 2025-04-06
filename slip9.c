//*******slip no.9 Question 1 *****
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











//*******slip no.9 Question 2 *****
#include<stdio.h>
#include<stdlib.h>
#define memory (struct node * )malloc (sizeof(struct node))
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
struct node *insert(struct node *root)
{
	int i,n;
	struct node *temp,*new,*parent;
	new=memory;
	printf("Enter node valude::");
	scanf("%d",&new->data);
	new->left=new->right=NULL;
	if(root=NULL)
	{
		root=new;
		return root;
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
return root;
}
void postorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
void main()
{
	int ch;
	struct node *root=NULL;
	do{
		printf("\n ****MENU***\n1.Create\n2.Insert\n3.Postorder\nEnter your choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			break;
			case 2:root=insert(root);
			break;
			case 3:postorder(root);
			break;
		}
	}while(ch<4);

	
}
