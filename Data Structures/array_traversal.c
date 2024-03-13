#include<stdio.h>

int main(){

    int Array[10]={2,4,6,8,10};

    setbuf(stdout,NULL);
	int n,a[100],i,j,temp;
	printf("Enter the number of elements in the array = ");
	scanf("%d",&n);
	printf("Enter the elements in the array = ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}
	printf("Array after sorting is ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;

    return 0;
}