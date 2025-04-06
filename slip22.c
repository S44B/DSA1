|||SLIP 22|||
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
 #include<stdio.h>
  void main()
  {
      int a[20][20],i,n,j;
      printf("Enter no of rows and cols= ");
        scanf("%d",&n);
         printf("Enter the value for egdes and vertex{0,1}= \n");
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
     printf("\nVerex \t Ind \t Out \t Tot");
       for(i=0;i<n;i++)
        {
            int sumin=0,sumout=0;
            for(j=0;j<n;j++)
             {
                sumin=sumin+a[j][i];
                sumout=sumout+a[i][j];
             }
             printf("\nV%d\t%d\t%d\t%d",i+1,sumin,sumout,sumin+sumout);
        }
  }