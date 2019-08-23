#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
               int data;
               struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
    int i,key,choice;
    do
    {
        printf("\n\nEnter a value to insert into hash table:");
        scanf("%d",&key);
        i=key%TABLE_SIZE;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=key;
        newnode->next = NULL;
        if(head[i] == NULL)
            head[i] = newnode;
        else
        {
            c=head[i];
            while(c->next != NULL)
               c=c->next;
            c->next=newnode;
        }
        printf("\n\nDo you want to insert another element?- (Press 1 for yes) -: ");
        scanf("%d",&choice);
    }while(choice == 1);

}
void search()
{
    int key,index;
    printf("\n\nEnter the element to be searched:");
    scanf("%d",&key);
    index=key%TABLE_SIZE;
    if(head[index] == NULL)
        printf("\n\n Search element not found\n");
    else
    {
        for(c=head[index];c!=NULL;c=c->next)
        {
            if(c->data == key)
                {
                    printf("\n\nSearch element %d is found at %d\n",key,index);
                    break;
                }
        }
        if(c==NULL)
            printf("\n Search element not found\n");
    }
}
void display()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\n\nEntries at index %d\n\n",i);
               if(head[i] == NULL)
                    printf("No Hash Entry");
               else
               {
                    for(c=head[i];c!=NULL;c=c->next)
                    printf("%d->",c->data);
               }
          }
}
int main()
{
    int opt,key,i,choice;
    do
    {
        printf("\n------Hash Table------\n\n1. Insert\n\n2. Display \n\n3. Search \n\n4.Exit \n\nEnter your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
        printf("\n\nDo you want to continue the program?-:(Press 1 for yes) :");
        scanf("%d",&choice);
    }while(choice == 1);
    return 0;
}
