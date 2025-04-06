|||SLIP 11|||   
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






\\Q2)\\
#include<stdlib.h>
int a[20][20],i,n,j;
struct node
 {
    int data;
    struct node *next;
 };
 struct node *head[20];
 void create()
  {
    struct node *temp,*newnode;
    for(i=0;i<n;i++)
    {       
            head[i]=NULL;
            for(j=0;j<n;j++)
             {
                if(a[i][j]==1)
                {
                newnode=(struct node *)malloc(sizeof(struct node));
                newnode->data=j+1;
                newnode->next=NULL;
                if(head[i]==NULL)
                 {
                    head[i]=temp=newnode;
                    continue;
                 }
                 temp->next=newnode;
                 temp=newnode;
             }
         }
    }
  }
  void accept()
  {
    printf("Enter no of nodes= ");
     scanf("%d",&n);
    printf("Enter adjancey list= ");
    for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
            if(i!=j)
             scanf("%d",&a[i][j]);
        }
     } 
  }
  void disp()
  {
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
  void displist()
  {
    struct node *temp;
    for(i=0;i<n;i++)
     {
        printf("V%d----->",i+1);
        for(temp=head[i];temp!=NULL;temp=temp->next)
         {
            printf("V%d-",temp->data);
         }
         printf("NULL");
     }
  }
  void main()
  {
    accept();
    disp();
    create();
    displist();
  }
