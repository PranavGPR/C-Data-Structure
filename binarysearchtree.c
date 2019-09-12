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
    struct node *temp,*ptr,*preptr;
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
            preptr = ptr;
            if(key > ptr -> data)
            {
                ptr = ptr -> right;
                if(ptr == NULL)
                {
                    preptr->right = temp;
                    return;
                }
            }
            else
            {
                ptr = ptr ->left;
                if(ptr == NULL)
                {
                    preptr->left = temp;
                    return;
                }
            }
        }
    }
}
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        printf("%d\t",root -> data);
        inorder(root -> right);
    }
}
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d\t",root -> data);
    }
}
int main()
{
     int opt;
     while(1){
         printf("\n\n-------BINARY TREE-------\n\n1.Insert\n\nTraversing:\n\n\t2.In-order\n\n\t3.Pre-order\n\n\t4.Post-order\n\n5.Exit\n\nEnter your choice:");
         scanf("%d",&opt);
         switch(opt){
             case 1:insert();break;
             case 2:inorder(root);break;
             case 3:preorder(root);break;
             case 4:postorder(root);break;
             case 5:exit(0);break;
             default:printf("Enter correct option!!!");
         }
     }
     return 0;
}
