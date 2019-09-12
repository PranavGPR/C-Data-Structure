#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *result=NULL,*root = NULL;
int found = 0;
void insert()
{
    struct node *temp,*ptr,*preptr;
    int key;
    char ch;
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
            fflush(stdin);
            preptr = ptr;
            printf("\n\nSelect your position (L or R) : ");
            scanf("%c",&ch);
            if(ch == 'R' || ch == 'r')
            {
                ptr = ptr -> right;
                if(ptr == NULL)
                {
                    preptr->right = temp;
                    return;
                }
                printf("\n\t\tInside right subtree.....");
            }
            else if(ch == 'L' || ch == 'l')
            {
                ptr = ptr ->left;
                if(ptr == NULL)
                {
                    preptr->left = temp;
                    return;
                }
                printf("\n\t\tInside left subtree.....");
            }
            else
                printf("\n\t\tChoose correct option!!");
        }
    }
}
void display(struct node *root)
{
    if(root != NULL)
    {
        display(root -> left);
        printf("%d\t",root -> data);
        display(root -> right);
    }
}
struct node* search(struct node *root, int num)
{
    if(root != NULL)
    {
        if(root -> data == num)
        {
            printf("\n\tElement is found!!!");
            found = 1;
            result=root;
            return root;
        }
        search(root -> left, num);
        search(root -> right, num);
    }
    if(root == NULL)
        return NULL;
}
void prepointer(struct node *ptr,int num)
{
    struct node *preptr;
     if(ptr != NULL)
    {
        if(ptr->right!=NULL)
        if(ptr ->right->data == num)
        {
            result = ptr;
            return;
        }
        if(ptr->left!=NULL)
        if(ptr ->left->data == num)
        {
            result = ptr;
            return;
        }
        preptr = ptr;
        prepointer(ptr -> left, num);
        prepointer(ptr -> right, num);
    }
}
struct node *last(struct node *ptr)
{
    while(ptr -> right != NULL)
        ptr = ptr -> right;
    return ptr;
}
struct node* del_last(struct node *root, int num)
{
    struct node *preptr;
    if(root->left != NULL)
         if(root->left->data == num)
          {
              preptr = root;
              goto next;
          }

    if(root->right != NULL)
       if(root->right->data == num)
        {
            preptr = root;
            goto next;
        }
        prepointer(root,num);
        preptr = result;
        next:
        if(preptr ->left!=NULL)
          if(preptr -> left -> data == num)
             preptr -> left = NULL;
        if(preptr ->right!=NULL)
          if(preptr -> right -> data == num)
            preptr -> right = NULL;
        return root;
}
struct node* delete(struct node *root, int num)
{
    struct node *ptr, *preptr, *least;
    ptr = root;
    if(root == NULL)
        return;
    else if (root -> data == num)
    {
        if(ptr -> left == NULL && ptr -> right == NULL)
        {
            printf("Successfully deleted!!!!");
            return NULL;
        }
        else
        {
            if(root->right != NULL)
            {
                least = last(root);
                while(least->left != NULL)
                    least = least -> left;
                root = del_last(root, least -> data);
                root -> data = least -> data;
             }
             else
             {
                  ptr = last(root->left);
                  while(ptr->left != NULL)
                    ptr = ptr -> left;
                  del_last(root, ptr->data);
                  root -> data = ptr -> data;
             }
        }
        printf("Successfully deleted!!!!");
        return root;
    }
    else
    {
        ptr = search(root,num);
        if(result == NULL)
        {
            printf("\nElement not found !!!!\n");
            return;
        }
        if(result -> left == NULL && result -> right == NULL)
            del_last(root, num);
        else
        {
            printf("\ninside else\n");
            least = last(root);
            del_last(root, least -> data);
            result -> data = least -> data;
        }
        result = NULL;
        return root;
        printf("Successfully deleted!!!!");
    }
}
int main()
{
     int opt, ch = 0,num;
     while(1){
         printf("\n\n-------------BINARY TREE-------------\n\n1.Insert\n\n2.Display\n\n3.Search\n\n4.Delete\n\n5.Exit\n\nEnter your choice:");
         scanf("%d",&opt);
         switch(opt)
         {
             case 1:insert();break;
             case 2:if(root==NULL)
                    {
                         printf("\nTree is Empty\n");
                         break;
                    }
                   display(root);break;
             case 3:printf("\nEnter the number to be searched:");
                    scanf("%d",&num);
                    search(root,num);
                    if(found == 0)
                        printf("\n\tElement not found!!!");
                    found = 0;
                    break;
             case 4:printf("\nEnter the number to be deleted:");
                    scanf("%d",&num);
                    root=delete(root,num);
                    break;
             case 5:exit(0);break;
             default:printf("Enter correct option!!!");
         }
     }
     return 0;
}

