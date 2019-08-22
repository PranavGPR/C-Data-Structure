#include<stdio.h>
int main()
{
    int arr[20],i,j,no,key;
    printf("Enter the no of elements:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
      printf("Enter the %d element:",i+1);
      scanf("%d",&arr[i]);
    }
    for(i=1;i<no;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
     }
    printf("\nAfter sorting.....\n");
    for(i=0;i<no;i++)
        printf("\n%d",arr[i]);
    return 0;
}

