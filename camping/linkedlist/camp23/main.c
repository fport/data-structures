// static stack 

#include<stdio.h>
#include<stdlib.h>
#define BOY 10

typedef struct stack STACK;

struct stack
{
    int arr [BOY];
    int top;  //indis
};

STACK y1;

void push (int sayi) {  // eleman ekle
    if(y1.top == BOY -1 )
    {
        printf("yigin dolu kardo!\n");
    }
    else 
    {
        y1.top++; 
        y1.arr[y1.top]  = sayi ;    
    }
}

void pop() {  // eleman cıkarma
    if(y1.top == -1 )
    {
        printf("yigin bos kardo, cikarilcak eleman yok!\n");
    }
    else 
    {
        int popEleman = y1.arr[y1.top];
        y1.top--; 
        printf("%d sayisi yigindan cıkarıldı\n ", popEleman);
    }

}

void display () {
    system("clear");

    if(y1.top == -1){
        printf("yigin bos kardo!\n");
    }
    else
    {
        for( int i = y1.top; i > -1; i-- ) {
            printf(" %d \n ",y1.arr[i]);
        }
    }
}


int main ()
{
    y1.top = -1;
    
    int secim, sayi;

    while(1) {
        printf("Yigin (STACK) \n");
        printf("1 ---> eleman ekleme (push) \n");
        printf("2 ---> eleman ekleme (pop) \n");
        printf("3 ---> eleman ekleme (display) \n");
        printf("4 ---> eleman ekleme (exit) \n");
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
            case 4 : printf("Çikiliyor ...\n");
                     return 0;
        }

    }
  return 0;
}

