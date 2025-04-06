|||SLIP 20|||
\\Q 1)\\
#include<stdio.h>
int a[20][20],i,n,j;
int visit[20]={0};
int indegree[20]={0};
#define max 20
struct stack
{
   int a[max];
   int top;
};
struct stack s;
void init()
{
   s.top=-1;
}
int isempty()
{
   return s.top==-1;
}
int isfull()
{
   return s.top==max-1;
}
void push(int key)
{
   s.top++;
   s.a[s.top]=key;
}
int pop()
{
   return s.a[s.top--];
}
void topologicalsort(int a[20][20],int n)
{
    init();
   for(i=0;i<n;i++)
     {
        indegree[i]=0;
       for(j=0;j<n;j++)
       {
             indegree[i]+=a[j][i];
       }
     }
     int k=0;
   while(i)
     {
         for(i=0;i<n;i++)
          {
            if(visit[i]==0 && indegree[i]==0)
            {
                push(i);
                visit[i]=1;
                printf("v%d\t",i+1);
            }
          }
           if(isempty())
            {
               break;
            }
            int v=pop();
            for(i=0;i<n;i++) 
             {
               if(a[v][i]==1)
                 indegree[i]--;
             }
          }
}
void adj()
{
    printf("Enter no o frows and cols= ");
       scanf("%d",&n);
    printf("Enter elements of matrix(0/1)=");
     for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
           {
              a[i][j]=0;
              if(i!=j)
              {
                 scanf("%d",&a[i][j]);
             }
           } 
      }   
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
void main()
{
     adj();
     topologicalsort(a,n); 
}










\\Q 2)\\
int countnode(struct node *root)
    {
         static int cnt=0;
         struct node *temp=root;
         if(temp!=NULL)
          {
            cnt++;
              countnode(temp->left);
               countnode(temp->right);
          }
          return cnt; 
    }
    int countleafnode(struct node *root)
    {
         static int cnt=0;
         struct node *temp=root;
         if(temp!=NULL)
          {
             if(temp->left!=NULL && temp->right!=NULL)
              {
                cnt++;
              countleafnode(temp->left);
               countleafnode(temp->right);
              }
          }
          return cnt; 
    }
   int main() 
   {
      struct node *root=NULL;
      root=create(root);
      printf("No of nodes= %d",+countnode(root));
      printf("\nNo of leaf nodes= %d",+countleafnode(root));
   }
