#include<stdio.h>
int main()
{
    int arr[20],i,no,search,found=0;
    printf("Enter the no of elements:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
      printf("Enter the %d element:",i+1);
      scanf("%d",&arr[i]);
    }
    printf("\nEnter the element that you want to search :");
    scanf("%d",&search);
    for(i=0;i<no;i++)
    {
        if(arr[i]==search)
        {
            printf("\nThe element is found at  the position : %d and index : %d",i+1,i);
            found=1;
        }
    }
    if(found==0)
       printf("\nThe element is not found\n");
    return 0;
}

