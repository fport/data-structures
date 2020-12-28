#include<stdio.h>
#include<stdlib.h>

typedef struct stack STACK;

struct stack
{
    int data;
    STACK *next;
};

STACK *temp = NULL;
STACK *top = NULL;

void push( int veri) 
{
    STACK *eleman = (STACK *)malloc(sizeof(STACK));
    eleman -> data = veri;

    if(top == NULL) {
        top = eleman;
        eleman -> next = NULL;
    }else {
        eleman -> next = top;
        top = eleman;
    }

}

void pop () 
{
    if( top == NULL){
        printf("stack bos, cikartilcak eleman yok kardo!");
    }else {
        printf("%d elemani stackten cikarildi kardo!",top->data);
        temp = top -> next;
        free(top);
        top = temp;
    }
}

void display() 
{
    system("clear");
    if(top == NULL){
        printf("stack bos kardo!");
    }else {
        temp = top;
        while(temp -> next != NULL){
            printf(" %d \n",temp -> data);
            temp = temp -> next;
        }
        printf(" %d \n",temp -> data);
    }
}

void peek() { // son degeri gösterir
    if(top == NULL){
        printf("stack bos kardo!");
    }else{
        printf("yiginin en usteki elemi : %d \n",top->data);
    }
}


int main ()
{
    int secim, sayi;

    while(1) {
        printf("Yigin (STACK) \n");
        printf("1 ---> eleman ekleme (push) \n");
        printf("2 ---> eleman silme (pop) \n");
        printf("3 ---> elemanlari gosterme  (display) \n");
        printf("4 ---> top elemanı gosterir (peek) \n");
        printf("5 ---> cikis (exit) \n");
        printf("Seciminizi yapin\n");

        scanf("%d",&secim);


        switch(secim){
            case 1 : printf("eklenecek sayi\n");
                     scanf("%d", &sayi);
                     push(sayi);
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break; 
            case 4 : peek();
                     break;            
            case 5 : printf("Çikiliyor ...\n");
                     return 0;
        }

    }
  return 0;
}

