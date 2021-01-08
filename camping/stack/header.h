/* C libs */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node NODE;
struct node 
{
    void *dataPtr;
    NODE *link;
};

typedef struct stack STACK;
struct stack 
{
    int count;
    NODE* top;
};

/* create Stack */
STACK *createStack (void)
{
    STACK *stack = (STACK*)malloc(sizeof(STACK));
    if(stack){
        stack -> count = 0;
        stack -> top = NULL;
    }
    return stack;
}   


/* push stack */
bool pushStack (STACK *stack, void *dataInPtr)
{
    NODE *newPtr = (NODE*)malloc(sizeof(NODE));
    if(!newPtr)
        return false;
    newPtr -> dataPtr = dataInPtr;
    newPtr -> link =  stack -> top;
    stack -> top = newPtr;
    (stack -> count)++; 
    return true;
}

/* pop stack */
void *popStack(STACK *stack)
{
    void *dataOutPtr;
    NODE *temp;

    if(stack -> count == 0)
        dataOutPtr = NULL;
    else
    {
        temp = stack -> top;
        dataOutPtr = stack -> top -> dataPtr;
        stack -> top = stack -> top -> link;
        free(temp);
        (stack->count)--;
    }
    return dataOutPtr;
}

/* stack top data */
void  *stackTop(STACK *stack)
{
    if(stack -> count == 0)
        return NULL;
    else
    {
        return stack -> top -> dataPtr;
    }
}

/* checking if stack is empty */ 
bool emptyStack(STACK *stack)
{
    return (stack -> count == 0);
}


/* checking if stack is full */
bool fullStack (STACK* stack)
{
    STACK *temp =(STACK*)malloc (sizeof(*(stack->top)));
    if (temp)
    {
        free (temp);
        return false;
    }
    return true;
}


/* stack count */
int stackCount (STACK* stack)
{
    return stack->count;
}

/* destroy Stack */
STACK* destroyStack (STACK* stack)
{
    NODE* temp;
    if (stack)
    {
        while (stack->top != NULL)
        {
            free (stack->top->dataPtr);
            temp = stack->top;
            stack->top = stack->top->link;
            free (temp);
        }
        free (stack);
    }
    return NULL;
}


