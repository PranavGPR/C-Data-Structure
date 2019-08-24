#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX];
int n=-1;
void create()
{
    int num,i;
    printf("\nEnter the no of elements : ");
    scanf("%d",&num);
    if(num >MAX )
        printf("\nSize exceed !!!!\n");
    else
    {
        for(i=0;i<num;i++)
        {
          printf("\nEnter the %d element :",i+1);
          scanf("%d",&arr[i]);
        }
        n = num-1;
        printf("\nSuccessfully Created!!\n");
    }
}
void insert()
{
      int elem,pos,i;
      printf("\nEnter the element to be inserted: ");
      scanf("%d",&elem);
      printf("\nEnter the position : ");
      scanf("%d",&pos);
      if(pos - 1 > n + 1  || n == MAX -1)
          printf("\nInsertion Not Possible\n");
      else
      {
          for(i=n;i>=pos-1;i--)
              arr[i+1] = arr[i];
           arr[pos-1]=elem;
           n++;
           printf("\nSuccessfully Inserted!!\n");
      }
}
void delete()
{
    int x,i,ind,found=0;
    printf("Enter the element to be deleted: ");
    scanf("%d",&x);
    for(i=0;i<=n;i++)
      if(arr[i]==x)
      {
          ind = i;
          found=1;
      }
    if(found  == 0)
        printf("\nElement Not found\n");
    else
    {
        for(i=ind;i<n;i++)
            arr[i]=arr[i+1];
        n--;
        printf("\nElement Deleted!!\n");
    }
}
void display()
{
    int i;
    if(n == -1)
      printf("\nList is Empty!!\n");
    else
    {
        printf("\nThe Elements are:");
        for(i=0;i<=n;i++)
            printf("%d\t",arr[i]);
        printf("\n");
    }
}
void search()
{
    int i,found=0,search;
    printf("\nEnter the element that you want to search :");
    scanf("%d",&search);
    for(i=0;i<=n;i++)
    {
        if(arr[i]==search)
        {
            printf("\nThe element is found at the position %d and index %d\n",i+1,i);
            found=1;
        }
    }
    if(found==0)
       printf("\nThe element is not found\n");
}
int main()
{
    int option,choice;
    do{
        printf("\n\n1.Create\n2.Insert\n3.Delete\n4.Search\n5.Display\n6.Exit\n");
        printf("\n\nEnter your option:");
        scanf("%d",&option);
        switch(option)
        {
           case 1:create();
                   break;
           case 2:insert();
                  break;
           case 3:delete();
                  break;
           case 4:search();
                  break;
           case 5:display();
                  break;
           case 6:exit(0);
                  break;
           default:printf("Enter the correct option!!");
        }
        printf("Do you want to continue(1/0):");
        scanf("%d",&choice);
    }while(choice==1);
    return 0;
}
