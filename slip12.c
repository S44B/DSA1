//slip12 Q1
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

|||SLIP 12|||
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
