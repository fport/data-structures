#ifndef HOMEWORK_H
#define HOMEWORK_H

/* C libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  node object */
typedef struct node NODE;
struct node
{
    void *dataPtr;
    NODE *link;
};

/* stack */
typedef struct stack STACK;
struct stack
{
    int count;
    NODE *top;
};

/* methods */
STACK *createStack(void);
void pushStack(STACK *stack, char *dataInPtr);
void *popStack(STACK *stack);
void *stackTop(STACK *stack);
bool emptyStack(STACK *stack);
bool fullStack(STACK *stack);
int stackCount(STACK *stack);
STACK *destroyStack(STACK *stack);

#endif
