#include <stdio.h>
#include <stdlib.h>
#define LEN 5

int arr[LEN];                           
int front = -1, rear = -1 ;  //  front <-|  |  |  |  |  | -> rear
                                   //   ^

void addElement(int data) {
    if(rear == LEN-1)
       printf("queue is full\n");
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = data;
    }
} 

void delElement(){
    if(front == -1 || front > rear){
        printf("queue is empty\n");
        front = -1;
        rear = -1;
    }else{
        front = front + 1;
    }
}


void display(){
    if(front == -1)
        printf("queue is empty\n");
    else{
        for(int i = 0; i <= rear; i++){
            printf("%d ",arr[i]);
        }
    }
}

int main(){
  int selected, num;
  while(1){
      printf("\n1 -- Add \n");
      printf("2 -- Delete \n");
      printf("3 -- Display \n");
      printf("4 -- Exit \n");
      printf("Select the action you want to do : \n");

      scanf("%d",&selected);
      switch(selected){
          case 1 : printf("Enter a number");
            scanf("%d",&num);
            addElement(num);
            break;
          case 2 : delElement();
                   break;
          case 3 : display();
                   break;
          case 4 :  return 0;  
      }
  }
}


