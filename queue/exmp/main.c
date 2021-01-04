#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "header.h"

void fillQueues(QUEUE* q0to9,QUEUE* q10to19, QUEUE* q20to29,QUEUE* qOver29)
{
    int category;
    int item;
    int* dataPtr;
    printf("Sayilar: \n ");
    srand(time(NULL));
    for(int i; i<=25;i++)
    {
        if(!(dataPtr=(int*)malloc(sizeof(int))))
        {
            printf("Overflow in queue");
            exit(1);
        }

        *dataPtr=item=rand()%51;
        category=item/10;
        printf("%3d",item);
        if(!(i%11))
            printf("\n");
        switch(category)
        {
            case 0: enqueue(q0to9,dataPtr);
                    break;
            case 1: enqueue(q10to19,dataPtr);
                    break;
            case 2: enqueue(q20to29,dataPtr);
                    break;
            default: enqueue(qOver29,dataPtr);
                     break;
        }
    }
    printf("\n\n\n");
    return;
}

void printOneQueue(QUEUE* pQueue)
{
    int lineCount;
    int* dataPtr;
    lineCount=0;
    while(!emptyQueue(pQueue))
    {
        dequeue(pQueue,(void*)&dataPtr);
        if(lineCount++>=10)
        {
            lineCount=1;
            printf("\n");
        }
        printf("%3d",*dataPtr);
    }
    printf("\n");
    return;
}

void printQueues(QUEUE* q0to9,QUEUE* q10to19, QUEUE* q20to29,QUEUE* qOver29)

{
    printf("Datalari 0 ile 9 arasinda olanlar :");
    printOneQueue(q0to9);
    printf("Datalari 10le 19arasinda olanlar :");
    printOneQueue(q10to19);
    printf("Datalari 20 ile 29 arasinda olanlar :");
    printOneQueue(q20to29);
    printf("Datalari 29'dan buyuk olanlar :");
    printOneQueue(qOver29);
    return;

}

int main()
{
    QUEUE* q0to9;
    QUEUE* q10to19;
    QUEUE* q20to29;
    QUEUE* qOver29;

    q0to9=createQueue();
    q10to19=createQueue();
    q20to29=createQueue();
    qOver29=createQueue();

    fillQueues(q0to9,q10to19,q20to29,qOver29);
    printQueues(q0to9,q10to19,q20to29,qOver29);

    return 0;
}
