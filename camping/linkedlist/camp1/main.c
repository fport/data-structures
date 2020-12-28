#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
    int data;
    struct node *ptr;
};

int main ()
{
    NODE *monster1 = (NODE *) malloc (sizeof(NODE));
    NODE *monster2 = (NODE *) malloc (sizeof(NODE));
    NODE *monster3 = (NODE *) malloc (sizeof(NODE));
    
    monster1->data = 78;
    monster1->ptr = monster2;

    monster2->data = 16;
    monster2->ptr = monster3;

    monster3->data = 34;
    monster3->ptr = NULL;

    printf("%d\n",monster1->data);    
    printf("%d\n",monster1->ptr->data);    
    printf("%d",monster3->data);    

    return 0;
}
