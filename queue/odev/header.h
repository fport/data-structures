/* C libs*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<string.h>

/* NODE*/
typedef struct node QUEUE_NODE;
struct node
{
    void *dataPtr;
    struct node *next;
};

/* QUEUE */
typedef struct queue QUEUE;
struct queue
{
    QUEUE_NODE *front;
    QUEUE_NODE *rear;
    int count;
}; 

/* create Queue */
QUEUE *createQueue(void)
{
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    if (queue)
    {
        queue->front = NULL;
        queue->rear = NULL;
        queue->count = 0;
    }
    return queue;
}

/* adding data to the queue */
bool enqueue(QUEUE *queue, void *itemPtr)
{
    QUEUE_NODE *newPtr = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));

    if (!newPtr)
        return false;
    newPtr->dataPtr = itemPtr; //b //c
    newPtr->next = NULL;

    if (queue->count == 0)
        queue->front = newPtr;
    else
    {
        queue->rear->next = newPtr;
    }
    (queue->count)++;
    queue->rear = newPtr;
    return true;
}

/* deleting data to the queue */
bool dequeue(QUEUE *queue, void **itemPtr)
{
    QUEUE_NODE *deleteLoc;

    if (!queue->count)
        return false;
    *itemPtr = queue->front->dataPtr;
    deleteLoc = queue->front;
    if (queue->count == 1)
        queue->rear = queue->front = NULL;
    else
        queue->front = queue->front->next;
    (queue->count)--;
    free(deleteLoc);
    return true;
}

bool queueFront(QUEUE *queue, void **itemPtr)
{

    if (!queue->count)
        return false;
    else
    {
        *itemPtr = queue->front->dataPtr;
        return true;
    }
}

bool queueRear(QUEUE *queue, void **itemPtr)
{
    //Statements
    if (!queue->count)
        return true;
    else
    {
        *itemPtr = queue->rear->dataPtr;
        return false;
    }
}

bool emptyQueue(QUEUE *queue)
{

    return (queue->count == 0);
}

bool fullQueue(QUEUE *queue)
{
    QUEUE_NODE *temp; 
    temp =  (QUEUE_NODE *)malloc(sizeof(*(queue->rear)));
    if (temp)
    {
        free(temp);
        return false; // true ??
    }
    return true; //false ???
}

/* queue count */
int queueCount(QUEUE *queue)
{
    return queue->count;
}

/* destroy queue */
bool destroyQueue(QUEUE *queue)
{

    QUEUE_NODE *deletePtr;

    if (queue)
    {
        while (queue->front != NULL)
        {
            free(queue->front->dataPtr);
            deletePtr = queue->front;
            queue->front = queue->front->next;
            free(deletePtr);
        }
        free(queue);
    }
    return NULL;
}
