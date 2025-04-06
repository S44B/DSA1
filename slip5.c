//slip5.Q1
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




//*******slip no. 5 Question no 2 */****
#include<stdio.h>
int a[20],i,n;
void accept()
{
    printf("Enter Elements::");
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
    if(a[j]<a[j+1] && j<last)
    {
        j=j+1;
    }
    if(p<a[j] && j<last)
    {
        temp=a[j];
        a[j]=a[top];
        a[top]=temp;
        heapify(a,top,last);
    }

}
void buildheap(int a[],int n)
{
    int i;
    for(i=n/n-2;i>0;i--)
    heapify(a,i,n-1);
}
void swap()
{
    int top=0,temp,last;
    printf("\nIntitial Heap::");
    display();
    for(last=n-1;last>=0;last--)
    {
        temp=a[top];
        a[top]=a[last];
        a[last]=temp;
        printf("\nAfter Interation:",n-last);
        display(a,n);
        heapify(a,top,last-1);
    }
}
void main()
{
    printf("Enter limit::");
    scanf("%d",&n);
    accept();
    display();
    swap(a,n);
}
