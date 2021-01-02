/*C Libs*/
#include <stdio.h>
#include <stdlib.h>

// node Object 
typedef struct node NODE;
struct node {
    int data;
    NODE *next;
};

/* global variable*/
NODE *temp = NULL;
NODE *front = NULL;
NODE *rear = NULL;

/* add data in queue*/
void addElement(int data)
{
    NODE * element = (NODE *)malloc(sizeof(NODE));
    element -> data = data;

    if(front == NULL)
    {
        front = element;
        front -> next = front;
        rear = element;
        rear -> next = NULL;
    }
    else if (front -> next == front) // queue has 1 data
    {
        rear -> next = element;
        rear = element;
        rear -> next = NULL;
        front -> next = rear;
    }
    else {
        rear -> next = element;
        rear = element;
        rear -> next = NULL;
    }
}

// delete data from queue
void deleteElement()
{
    if(front == NULL)
        printf("queue is empty!");
    else
    {
        temp = front -> next;
        free(front);
        front = temp;
    }
}


// display queue
void display()
{
    system("clear");
    if(front == NULL)
        printf("queue is empty!");
    else
    {
        temp = front;
        while(temp -> next != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        /*print last element (rear)*/
        printf("%d ",temp -> data);
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
          case 2 : deleteElement();
                   break;
          case 3 : display();
                   break;
          case 4 :  return 0;  
      }
  }
}

