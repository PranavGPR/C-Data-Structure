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
void mulpoly();
void muladd();
struct poly *list1=NULL,*list2=NULL,*mul1=NULL,*mul2=NULL;
int main()
{
  create();
  printf("\n\t\tEquation 1\n");
  display(list1);
  printf("\n\n\t\tEquation 2\n");
  display(list2);
  mulpoly();
  printf("\n\n\t\tAnswer \n");
  display(mul1);
  muladd();
  printf("\n\n\t\tAnswer \n");
  display(mul2);
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
		printf(" (%d) x^%d ",ptr->coeff,ptr->power);
		ptr=ptr->next;
		if(ptr!=NULL)
            printf("+");
    }

}
void mulpoly()
{
    struct poly *temp1,*temp2,*temp;
	temp1=list1;
	temp2=list2;
    temp=(struct poly*)malloc(sizeof(struct poly));
    mul1=temp;
    temp->next=NULL;
    while(temp1!=NULL)
	{
	   while(temp2!=NULL)
	   {
	       temp->coeff = temp1->coeff * temp2->coeff;
		   temp->power = temp1->power + temp2->power;
		   temp2=temp2->next;
		   if(temp2 != NULL)
		   {
			   temp->next=(struct poly*)malloc(sizeof(struct poly));
	           temp=temp->next;
	           temp->next=NULL;
		   }
	   }
	   temp1=temp1->next;
	   temp2=list2;
	   if(temp1 != NULL)
	   {
	       temp->next=(struct poly*)malloc(sizeof(struct poly));
	       temp=temp->next;
	       temp->next=NULL;
	   }

	}
}
void muladd()
{
	struct poly *temp1,*temp2,*preptr;
	mul2=mul1;
	temp1 =mul1;
	while(temp1 != NULL)
	{
	    temp2 =temp1->next;
    	preptr = temp1;
		while(temp2 != NULL)
		{
			if(temp1->power == temp2->power)
			{
				temp1->coeff=temp1->coeff + temp2->coeff;
				preptr->next = temp2 ->next;
				temp2 = temp2 ->next;
			}
			else
			{
				preptr = temp2;
				temp2 = temp2 ->next;
			}
		}
		temp1=temp1->next;
	}
}

