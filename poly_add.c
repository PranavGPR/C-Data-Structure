#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct poly
{
   int coeff;
   int power;
   struct poly *next;
};
void create();
void display(struct poly *list);
void addpoly();
struct poly *list1=NULL,*list2=NULL,*add=NULL;
int main()
{

  create();
  printf("\n\t\tEquation 1\n");
  display(list1);
  printf("\n\n\t\tEquation 2\n");
  display(list2);
  addpoly();
  printf("\n\n\t\tAnswer \n");
  display(add);

}
void create()
{
   int power,coeff,num,i;
   struct poly *temp,*ptr;
   printf("\n\t\tEquation 1");
   printf("\nEnter the number of terms:");
   scanf("%d",&num);
   for(i=1;i<=num;i++)
   {
       temp=(struct poly*)malloc(sizeof(struct poly));
	   printf("\nEnter the power:");
	   scanf("%d",&power);
	   printf("\nEnter the coefficient:");
	   scanf("%d",&coeff);
	   temp->coeff=coeff;
	   temp->power=power;
	   temp->next=NULL;
	   if(list1==NULL)
	   {
	       list1=temp;
	   }
	   else
	   {
	        ptr=list1;
			while(ptr->next!=NULL)
			    ptr=ptr->next;
		    ptr->next=temp;
	   }

    }
   printf("\n\t\t\t Successfully Created 1\n");
   printf("\n\t\tEquation 2");
   printf("\nEnter the number of terms:");
   scanf("%d",&num);
   for(i=1;i<=num;i++)
   {
       temp=(struct poly*)malloc(sizeof(struct poly));
	   printf("\nEnter the power:");
	   scanf("%d",&power);
	   printf("\nEnter the coefficient:");
	   scanf("%d",&coeff);
	   temp->coeff=coeff;
	   temp->power=power;
	   temp->next=NULL;
	   if(list2==NULL)
	   {
	       list2=temp;
	   }
	   else
	   {
	        ptr=list2;
			while(ptr->next!=NULL)
			    ptr=ptr->next;
		    ptr->next=temp;
	   }

    }
   printf("\n\t\t\t Successfully Created 2\n");

}
void display(struct poly *list)
{
    struct poly *ptr;
	ptr=list;
	while(ptr!=NULL)
	{
		printf(" %d x^%d ",ptr->coeff,ptr->power);
		ptr=ptr->next;
		if(ptr!=NULL)
            printf("+");
    }

}
void addpoly()
{
    struct poly *temp1,*temp2,*temp;
	temp1=list1;
	temp2=list2;
    temp=(struct poly*)malloc(sizeof(struct poly));
    add=temp;
    temp->next=NULL;
    while((temp1!=NULL) || (temp2!=NULL))
	{
       if(temp1==NULL)
        {
           temp->coeff=temp2->coeff;
	       temp->power=temp2->power;
	       temp2=temp2->next;
		   goto createnode;
        }
        if(temp2==NULL)
        {
           temp->coeff=temp1->coeff;
	       temp->power=temp1->power;
	       temp1=temp1->next;
		   goto createnode;
        }
      if(temp1->power==temp2->power)
	   {
	      temp->coeff=temp1->coeff + temp2->coeff ;
	      temp->power=temp1->power;
	      temp1=temp1->next;
		  temp2=temp2->next;
	   }
	   else if((temp1->power) > (temp2->power))
	   {
          temp->coeff=temp1->coeff;
	      temp->power=temp1->power;
		  temp1=temp1->next;
	   }
	   else
	   {
	       temp->coeff=temp2->coeff;
	       temp->power=temp2->power;
	       temp2=temp2->next;
	   }
	   createnode:
	   if((temp1 != NULL) || (temp2 != NULL))
       {
           temp->next=(struct poly*)malloc(sizeof(struct poly));
           temp=temp->next;
           temp->next=NULL;
       }

	}
}

