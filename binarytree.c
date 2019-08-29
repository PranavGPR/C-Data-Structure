#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void insert(){
    struct node *temp,*ptr;
    int key;
    printf("\nEnter the data to be inserted:");
    scanf("%d",&key);
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = key;
    temp -> left = NULL;
    temp -> right = NULL;
    if(root == NULL)
        root = temp;
    else
    {
        ptr = root;
        while(1)
        {
            if(temp -> data < root ->data)
            {
                ptr = ptr -> left;
                if(ptr == NULL)
                {
                    ptr = temp;
                    return;
                }
            }
            else
            {
                ptr = ptr ->right;
                if(ptr == NULL)
                {
                    ptr = temp;
                    return;
                }
            }
        }
    }
}
void preorder(struct node *root)
{
    if(root != NULL){
        printf("%d\t",root -> data);
        if(root -> left != NULL)
            preorder(root -> left);
        if(root -> right != NULL)
            preorder(root -> right);
    }
}
void inorder(struct node *root){
    if(root != NULL){
        if(root -> left != NULL)
            inorder(root -> left);
        printf("%d\t",root -> data);
        if(root -> right != NULL)
            inorder(root -> right);
    }
}
int main()
{
     int opt, ch = 0;
     do{
         printf("\n\n-------BINARY TREE-------\n\n1.Insert\n\nSearch\n\n\t2.In-order\n\n\t3.Pre-order\n\n\t4.Post-order\n\n5.Exit\n\nEnter your choice:");
         scanf("%d",&opt);
         switch(opt){
             case 1:insert();break;
             case 2:inorder(root);break;
             case 3:preorder(root);break;
             //case 4:postorder(root);break;
             case 5:exit(0);break;
             default:printf("Enter correct option!!!");
         }
         printf("\nDo you want to continue (1/0) : ");
         scanf("%d",&ch);
     }while(ch == 1);
     return 0;
}
