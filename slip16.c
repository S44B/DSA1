|||SLIP 16|||
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
int a[20],i,n;
void accept()
{
printf("Enter the data");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
}
void display()
{
for(i=0;i<n;i++)
printf("%d\t",a[i]);

}
void heapify(int a[],int top,int last)
{
int p=a[top],j,r,temp;
    j=2*top+1;
   
    if(a[j]<a[j+1]&&j<last)
    {
      j=j+1;
    }
    if(p<a[j]&&j<=last)
    { 
     temp=a[top];
     a[top]=a[j];
     a[j]=temp;
     heapify(a,j,last);
    }
}

void buildheap(int a[],int n)
{   
  int i;
 for(i=n/2-1;i>=0;i--)
 heapify(a,i,n-1);
}
void swap(int a[],int n)
{
int temp,top=0,last;
buildheap(a,n);
printf("Initial heap=");
display();
for(last=n-1;last>=1;last--)
{
temp=a[top];
a[top]=a[last];
a[last]=temp;
printf("\n After Iteration %d =",n-last);
display(a,n);
heapify(a,top,last-1);
}
}
void main()
{
printf("Enter the limit");
scanf("%d",&n);
accept();
display();
swap(a,n);

}
