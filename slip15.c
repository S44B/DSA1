//slip15 Q1
#include<stdio.h>
void main(){
	int i,n,temp,hashValue;
	int a[20];
	printf("Enter no of values: ");
	scanf("%d",&n);
	
	for(i=0; i<20; i++){
		a[i] = -1;
	}
	printf("Enter values: ");
	for(i=0; i<n; i++){
		printf("\nEnter number: ");
		scanf("%d",&temp);
		hashValue = temp%10;
		{
		for(int j=hashValue; j<20; j++){
			
			if(a[j] == -1){
				a[j] = temp;
				
				break;
			}
		}
		}
		
	}
	
	printf("Hash Table values: ");
	printf("\nindex -> value: ");
	for(i=0; i<20; i++){
		if(a[i] != -1)
			printf("\n%d -> %d",i,a[i]);
	}
}





|||SLIP 15|||
 \\Q 2)\\
#include <stdio.h>
//#define n 4
int i,j,n;
void dij(int a[10][10])
{
int d[20]={0},visit[20],min,v,k;

   i=0;
   visit[0]=1;
   d[0]=0;
      for (j = 1; j < n; j++) 
      {
            d[j]=a[i][j];
      }
     for (j = 0; j < n; j++) 
      { 
       printf("%d\t",d[j]);
      } 
      k=1;
      while(k<n-1)
      {
      min=999;
    
      for(j=1;j<n;j++)  
      {
           if(d[j]<min && visit[j]==0)
           {
             min=d[j];
             v=j;
           }
      }
      visit[v]=1;
      for(j=1;j<n;j++)
      {
        if(d[v]+(a[v][j]>d[j]))
        {
          d[j]=d[v]+a[v][j];
        }
      }
      k++;
      }
      printf(" \nDijktras shortest path\n");
  for (j = 0; j < n; j++) 
      {
       printf("%d\t",d[j]);
      } 
  
}
void main() 
{
  int a[10][10] ;
printf("Enter limit");
scanf("%d",&n);

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
  }
  }
  dij(a);
}
