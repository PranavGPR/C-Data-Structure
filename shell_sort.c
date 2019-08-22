#include<stdio.h>
int main()
{
    int arr[20],i,j,no,key,gap;
    printf("Enter the no of elements:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
      printf("Enter the %d element:",i+1);
      scanf("%d",&arr[i]);
    }
    for(gap=no/2;gap > 0;gap/=2)
    {
        for(i=gap;i<no;i++)
        {
            int temp=arr[i];
            for(j=i; j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }

    printf("\nAfter sorting.....\n");
    for(i=0;i<no;i++)
        printf("\n%d",arr[i]);
    return 0;
}

