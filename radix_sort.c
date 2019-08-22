#include<stdio.h>
int max(int arr[],int n)
{
    int max,i;
    max=arr[0];
    for(i=1;i<n;i++)
        if(arr[i]>max)
          max=arr[i];
    return max;
}
void sort(int arr[],int no,int exp)
{
    int output[no];
    int i,count[10]={0};
    for(i=0;i<no;i++)
        count[ (arr[i]/exp)%10 ]++;
    for(i=1;i<10;i++)
         count[i]=count[i]+count[i-1];
    for(i=no-1;i>=0;i--)
    {
        output[ count[(arr[i]/exp)%10]-1 ]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<no;i++)
        arr[i]=output[i];
}
int main()
{
    int arr[20],i,j,no,key,Max,exp;
    printf("Enter the no of elements:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    {
      printf("Enter the %d element:",i+1);
      scanf("%d",&arr[i]);
    }
    Max=max(arr,no);
    for(exp=1;Max/exp > 0;exp*=10)
        sort(arr,no,exp);
    printf("\nAfter sorting.....\n");
    for(i=0;i<no;i++)
        printf("\n%d",arr[i]);
    return 0;
}

