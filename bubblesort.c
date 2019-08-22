#include<stdio.h>
int main()
{
	int a[20],i,j,n,temp;
	printf("Enter the number of values:");
	scanf("%d",&n);
	printf("\n\nEnter %d elements:\n\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	printf("After Sorting....\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}	 

