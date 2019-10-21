#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
struct node *dequeue();
struct node
{
   int tk;
   int age;
   char name[20];
   struct node *next;
};
int no=0;
struct node *list1=NULL;
struct node *list2=NULL;
struct node *rear;
struct node *wlist;
void booking()
{
    struct node *temp;
    int opt,i,num;
    printf("How many Tickets : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter Name : ");
        scanf("%s",temp->name);
        printf("Enter age : ");
        scanf("%d",&temp->age);
        temp->tk = ++no;
        temp->next = NULL;
        if(no <= MAX)
        {
            if(list1==NULL)
           {
               list1=temp;
               rear=temp;
           }
           else
          {
                rear->next = temp;
                rear = temp;
           }
           printf("\nTICKET BOOKED SUCCESSFULLY !!!!!!!\n");
        }
        else
        {
            printf("\nAll tickets are booked !!\nDO yu want book under Waiting list(1/0) :");
            scanf("%d",&opt);
            if(opt==0)
                return;
            if(opt != 0 && opt != 1)
                return;
             if(list2==NULL)
           {
               list2=temp;
               rear=temp;
           }
           else
          {
                rear->next = temp;
                rear = temp;
           }
           printf("\nTICKET BOOKED SUCCESSFULLY !!!!!!!\n");
        }
    }
}
void cancel()
{
    struct node *ptr,*preptr,*temp;
	int number,found = 0;
    ptr=list1;
    preptr=ptr;
    printf("\nEnter the ticket Number:");
    scanf("%d",&number);
    while(ptr != NULL)
    {
        if(ptr->tk == number)
        {  
           if(list2 == NULL)
           {
              if(ptr->next == NULL)
                list1 = NULL;
              else
               preptr->next = ptr->next;
           }
           else
           {
                temp=dequeue();
                ptr->age = temp->age;
                strcpy(ptr->name,temp->name);
            }
            found=1;
        }
        preptr = ptr;
        ptr=ptr->next;
    }
        printf("\nTICKET CANCELED SUCCESSFULLY\n");
    if(found == 0)
        printf("\nTicket number not found\n");
}
void display(struct node *list)
{
    struct node *ptr;
    ptr=list;
    while(ptr != NULL)
    {
        printf("Name : %-20s\tAge : %2d\tTicket No : %d\n",ptr->name,ptr->age,ptr->tk);
        ptr=ptr->next;
    }

}
struct node* dequeue()
{
    struct node *ptr;
    ptr=list2;
    list2=list2->next;
    return ptr;
}
int main()
{
    int ch;
    while(1){
    printf("\n--------------Railway Reservation System----------------\n");
    printf("\n\n1.Book Tickets\n2.Cancel Booking\n3.Availablity Checking\n4.BOOKED SEATS\n5.Waiting list\n6.Exit\n");
    printf("\n\nEnter your option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:booking();
               break;
       case 2:
              if(list1==NULL){
                printf("\nNO TICKETS RESERVED !!!\n");
                break;
              }
              cancel();
              break;
       case 3:if(MAX > no)
                  printf("\nSeats Available!\n");
              else
                printf("\nSeats are Filled!\n");
              break;
       case 4:
              if(list1==NULL){
                printf("\nNO TICKETS RESERVED !!!\n");
                break;
              }
              printf("\n\t\tTRAIN 12345\n");
              display(list1);break;
       case 5:
              if(list2==NULL)
                printf("\nWaiting List is Empty\n");
              else
              {
                  printf(" Waiting List ....\n");
                  display(list2);
              }
              break;
       case 6:exit(0);break;
       default:printf("OOPS Something went wrong!!!");
    }
    }
    return 0;
}

