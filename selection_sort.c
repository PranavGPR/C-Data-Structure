#include<stdio.h>
int main()
{
    int arr[20],i,j,no,min_in;
    printf("Enter the no of elements:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
      printf("Enter the %d element:",i+1);
      scanf("%d",&arr[i]);
    }
    for(i=0;i<no;i++)
    {
        min_in=i;
        for(j=i+1;j<no;j++)
        {
            if(arr[min_in]>arr[j])
            {
                min_in=j;

            }
        }
        int temp=arr[i];
        arr[i]=arr[min_in];
        arr[min_in]=temp;
     }
    printf("\nAfter sorting.....\n");
    for(i=0;i<no;i++)
        printf("\n%d",arr[i]);
    return 0;
}

