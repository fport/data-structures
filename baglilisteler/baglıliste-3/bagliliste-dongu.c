#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node* next;
}Node;

void bastir(struct node* r){
    while(r!=NULL){
        printf("\n%d",r->x);
        r= r->next;
    }
}

int main(){
    struct node* root;

    root = (struct node*)malloc(sizeof(struct node));
    root -> x = 10;
    root -> next = (struct node*)malloc(sizeof(struct node));
    root -> next -> x = 20;
    root -> next -> next = (struct node*)malloc(sizeof(struct node));
    root -> next -> next -> x = 30;
    root -> next -> next -> next = NULL;

    struct node* iter;
    iter = root; // rootun gösterdiği yeri iter göstersin.
    
    printf("%d \n",iter->x);
    iter = iter->next;
    printf("%d",iter->x);

    int i=0;
    iter = root; 
    while(iter->next != NULL){
        i++;
        printf("\n%d. eleman -> %d\n",i,iter->x);
        iter = iter->next;
    }

    for(int i=0; i<5; i++){
        iter->next = (struct node*)malloc(sizeof(struct node));
        iter = iter->next;
        iter->x = i*5;
        iter->next = NULL;
    }
    
    bastir(root);

}

