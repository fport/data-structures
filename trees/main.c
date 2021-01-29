#include<stdio.h>
#include<stdlib.h>

typedef struct node NODE;
struct node {
    int data;
    NODE *left;
    NODE *right;
};


NODE *createRootNode(int veri)
{
    NODE *root = (NODE*)malloc(sizeof(NODE));
    root -> data = veri;
    root -> left = NULL;    
    root -> right = NULL;    

    return root;
}

NODE *addElement(NODE *root, int veri)
{
    if( root == NULL)
    {
        root = createRootNode(veri);
    }
    else
    {
        if(veri < root -> data){
            root -> left = addElement(root -> left,veri);
        }
        else 
        {
            root -> right = addElement(root -> right,veri);
        }
    }
    return root;
}

void preOrder(NODE *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(NODE *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(NODE *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{

    NODE *eleman = NULL;
    int sayi,i=0;

    while(i<7)
    {
        printf("Sayi girin : \n");
    scanf("%d",&sayi);
   eleman =  addElement(eleman, sayi);
   i++;
    }

    printf("\npreOrder : ");
    preOrder(eleman);
    
    printf("\ninOrder : ");
    inOrder(eleman);

    printf("\npostOrder : ");
    postOrder(eleman);

}
