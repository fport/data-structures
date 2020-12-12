#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node* next;
}Node;

void bastir(struct node* r){
    while(r!=NULL){
        printf("%d ",r->x);
        r= r->next;
    }
}

void ekle(struct node *r, int x){
    while(r->next != NULL){
        r= r->next;
    }
    r->next = (struct node*)malloc(sizeof(struct node));
    r-> next -> x = x;
    r-> next -> next = NULL;
}

struct node* ekleSirali(struct node* r, int x){
    if(r==NULL){//linklist bossa
        r = (struct node*)malloc(sizeof(struct node));
        r -> next = NULL;
        r -> x = x ;
        return r;
    }
    if(r->x > x){// ilk elemandan kucuk durumu 
                //root degisiyor
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp -> x = x;
        temp ->next = r;
        return temp;
    }
    struct node* iter = r;
    while(iter->next != NULL && iter->next->x < x){
        iter= iter->next;
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp ->x = x;
    return r;

}

int main(){
    struct node* root;
    root = NULL;

    root = ekleSirali(root,400);
    root = ekleSirali(root,40);
    root = ekleSirali(root,450);
    root = ekleSirali(root,500);

    bastir(root);

    /* struct node* iter = root; */
    /* for(int i=0;i<3;i++){ */
    /*     iter = iter -> next; */
    /* } */
    /* struct node* temp = (struct node*)malloc(sizeof(struct node)); */
    /* temp -> next = iter -> next; */
    /* iter -> next = temp; */
    /* temp -> x = 100; */
    /* bastir(root);   */

}
