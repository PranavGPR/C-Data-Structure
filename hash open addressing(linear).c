#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TABLE_SIZE 10
int hash[TABLE_SIZE] = {0};
void insert()
{
    int key,index;
    printf("\nEnter the element to be inserted :");
    scanf("%d",&key);
    index=key%TABLE_SIZE;
    if(hash[index] == 0)
        hash[index] = key;
    else
        hash[++index] = key;
    printf("\n\nElement inserted successfully!!!");
}
void display(){
    for(int i=0;i<TABLE_SIZE;i++){
        printf("Hash index %d\n\n",i);
        printf("Value : %d\n\n",hash[i]);
    }
}
void search(){
    int i,search,found;
    printf("\nEnter the element to be searched:");
    scanf("%d",&search);
    for(i=0;i<TABLE_SIZE;i++){
        if(hash[i] == search)
        {
            printf("\n\nSearch element found\n\n");
            found = 1;
        }
        if(found == 0)
            printf("Element not found");
    }
}
int main()
{
    int i,opt,choice;
    do{
        printf("--------HASH TABLE--------\n\n1.Insert\n\n2.Display\n\n3.Search\n\nEnter your choice:");
        scanf("%d",&opt);
        switch(opt)
        {
                case 1:insert();
                       break;
                case 2:display();
                       break;
                case 3:search();
                       break;
                case 4:exit(0);
        }
        printf("\n\nDo you want to continue-:(Press 1 for yes) :");
        scanf("%d",&choice);
    }while(choice == 1);
    return 0;
}
