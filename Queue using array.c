#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=-1;
int rear=-1;
void insert(),del(),display();
int q[size],choice,element,opt;


int main()
{
	do
	{
		
		printf("\n MENU");
		printf("\n 1.Insert a element\n2.Delete a element\n3.Display the queue\n4.Exit");
		printf("\n enter your option");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();break;
			case 2:del();break;
			case 3:display();break;
			case 4:exit(0);
	    }
		printf("\n Do you want to continue(1/0):");
		scanf("%d",&opt);
	}while(opt==1);
	return 0;
}

void insert()
{
	printf("\n Enter the element to be added:");
	scanf("%d",&element);
	if(rear<size-1)
	{
		q[++rear]=element;
		if(front==-1)
			front++;
		printf("\n Element is added to queue sucessfully");
	}
	else
		printf("\n Queue has fully filled");
	
	
}

void display()
{
	int i;
	if(front!=-1)
	{
		printf("\n The elements in the queue are:");
		for(i=0;i<=rear;i++)
			printf("\t %d",q[i]);
		printf("\n Element deleted sucessfully"); 
	}
	else
		printf("\n No elements in queue");
}

void del()
{
	int i;
	if(front!=-1)
	{
		for(i=0;i<=rear;i++)
			q[i]=q[i+1];
		rear--;
	}
	else
		
		printf("\n No elements in queue");
}
	
		
	
		
	


