#include<stdio.h>
int main()
{
    int arr[20],i,no,search,found=0,frst,last,mid;
    printf("Enter the no of elements:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
      printf("Enter the %d element:",i+1);
      scanf("%d",&arr[i]);
    }
    printf("\nEnter the element that you want to search :");
    scanf("%d",&search);
    frst=0;
    last=no-1;
    while(frst<=last)
    {
        mid=(frst+last)/2;
        if(arr[mid]==search)
        {
            printf("\nThe element is found at  the position : %d and index : %d",mid+1,mid);
            found=1;
            break;
        }
        else if(search>arr[mid])
            frst=mid+1;
        else
            last=mid-1;

    }
    if(found==0)
       printf("\nThe element is not found\n");
    return 0;
}

