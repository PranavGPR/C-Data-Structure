#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
int check = 0;
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
struct node* min(struct node* root)
{
    while(root->left != NULL)
        root = root ->left;
    return root;
}
struct node* del(struct node* root,int num)
{
    struct node *temp;
    if(root == NULL)
        return root;
    else if(num < root->data)
         root->left = del(root->left,num);
    else if(num > root->data)
          root->right = del(root->right,num);
    else
    {
        check = 1;
        if(root->left == NULL && root->right == NULL)
               root = NULL;
        else if(root->left == NULL)
           {
               temp = root;
               root=root->right;
               free(temp);
           }
        else if(root->right == NULL)
        {
            temp = root;
            root = root->left;
            free(root);
        }
        else
        {
           temp = min(root->right);
           root->data = temp->data;
           root->right = del(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
     int opt,num;
     while(1){
         printf("\n\n-------BINARY SEARCH TREE-------\n\n1.Insert\n\nTraversing:\n\n\t2.In-order\n\n\t3.Pre-order\n\n\t4.Post-order\n\n5.Delete\n\n6.Exit\n\nEnter your choice:");
         scanf("%d",&opt);
         switch(opt){
             case 1:insert();break;
             case 2:inorder(root);break;
             case 3:preorder(root);break;
             case 4:postorder(root);break;
             case 5:printf("\nEnter the number to be deleted:");
                    scanf("%d",&num);
                    root=del(root,num);
                    if(check == 0)
                        printf("\nElement not found\n");
                    else
                        printf("\nDeleted successfully\n");
                    check = 0;
                    break;
             case 6:exit(0);break;
             default:printf("Enter correct option!!!");
         }
     }
     return 0;
}

