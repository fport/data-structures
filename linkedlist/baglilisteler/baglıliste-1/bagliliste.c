#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node* next;
}Node;

int main(){
    struct node* root;

    root = (struct node*)malloc(sizeof(struct node));
    root -> x = 10;
    root -> next = (struct node*)malloc(sizeof(struct node));
    root -> next -> x = 20;
    root -> next -> next = (struct node*)malloc(sizeof(struct node));
    root -> next -> next -> x = 30;

    struct node* iter;
    iter = root; // rootun gösterdiği yeri iter göstersin.
    
    printf("%d \n",iter->x);
    iter = iter->next;
    printf("%d",iter->x);


}

