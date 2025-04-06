|||SLIP 14|||
\\Q 1)\\ 
#include<stdio.h>
int a[20][20],i,n,j,k;
void printmatrix()
{
     for(i=0;i<n;i++)
       {
          for(j=0;j<n;j++)
            {
               if(a[i][j]==999)
                 {
                    printf("%4s","INF");
                 }
               else 
                  printf("%4d",a[i][j]);  
            }
            printf("\n");
       }
}
void floydwarshal()
{
    for(k=0;k<n;k++)
      {
         for(i=0;i<n;i++)
          {
            for(j=0;j<n;j++)
             { 
                if(a[i][k]+a[k][j]<a[i][j])
                   a[i][j]=a[i][k]+a[k][j];
             }
          }
          printf("\nd(%d):\n",k+1);
          printmatrix();
      }
}
void main()
{
   printf("Enter no of vertices= ");
     scanf("%d",&n);
   printf("Enter value of vertices= ");
     for(i=0;i<n;i++)
       {
         for(j=0;j<n;j++)
           {
               scanf("%d",&a[i][j]);
           }
       }
       floydwarshal(); 

}







\\Q 2)\\
#include<stdio.h>
#include<stdlib.h>
#define maxsize 20
#define memory (struct node *) malloc (sizeof(struct node))
 struct node 
{
    int data;
    struct node *left,*right;
};
struct queue 
{
    struct node *d[maxsize];
    int front,rear;
};
struct queue q;
void init()
{
    q.front=q.rear=-1;
}
int isEmpty ()
{
    return q.front==q.rear;
}
int isFull ()
{
    return q.rear==maxsize-1;
}
void add(struct node *temp)
{
   q.d[++q.rear]=temp;
   if(q.front==-1)
   {
       q.front=0;
   }
}
struct node *rm()
{
    return q.d[q.front++];
}
struct node*create (struct node *root)
{
    int i,n;
    struct node *new,*temp,*parent;

    printf("Enter no of nodes :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         new=memory;
         printf("Enter %d node value :",i+1);
         scanf("%d",&new->data);
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
void levelorder(struct node *root)
{
    struct node *temp,*M=NULL;
    int level=0;
        int cnt=0;
    init();
    add(root);
    add(M);
    printf("LEVEL %d\t:",level);
    while(!isEmpty())
    {
       temp=rm();
       if(temp==M)
       {
         level++;
         cnt++;
         if(!isEmpty())
         {
            add(M);
            printf("\n LEVEL %d:" ,level);
         }
       }
       else
       {
          printf("%d\t",temp->data);
          if(temp->left!=NULL)
          add(temp->left);
          if(temp->right!=NULL)
          add(temp->right);
       }
    }
                printf("\nTotal level= %d",cnt+1);
}
void main ()
{
   struct node *root=NULL;
   root=create(root);
   levelorder(root);
}
 
