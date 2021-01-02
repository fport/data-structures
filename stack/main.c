#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

#define MAX 50

/* createStack method */
STACK *createStack(void)
{
    STACK *stack = malloc(sizeof(STACK));
    *stack = (STACK){
        .count = 0,
        .top = NULL,
    };
    return stack;
}

/* pushStack method */
void pushStack(STACK *stack, char *dataInPtr)
{
    NODE *newPtr = malloc(sizeof(NODE));
    *newPtr = (NODE){
        .dataPtr = dataInPtr,
        .link = stack->top,
    };
    stack->top = newPtr;
    stack->count++;
}

/* popStack method*/
void *popStack(STACK *stack)
{
    if (stack->top == NULL)
        return NULL;

    NODE *temp = stack->top;
    stack->top = temp->link;
    temp->link = NULL;
    stack->count--;
    return temp;
}

/*stackTop method */
void *stackTop(STACK *stack)
{
    return stack->top;
}

/* match Parentheses */
bool match_paranthesis(STACK *stack, char b)
{
    NODE *top = stackTop(stack);
    if (top == NULL)
        return false;

    printf("\n match_paranthesis : %c %c \n", *((char *)(top->dataPtr)), b);

    if (*(char *)(top->dataPtr) == '{' && b != '}')
        return false;
    if (*(char *)(top->dataPtr) == '(' && b != ')')
        return false;

    printf("true");
    return true;
}

bool check_paranthesis(STACK *stack, char *expression, size_t n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (expression[i] == '(' || expression[i] == '{')
            pushStack(stack, expression + i);
        else if (expression[i] == ')' || expression[i] == '}')
        {
            if (!match_paranthesis(stack, expression[i]))
                return false;

            NODE *top = stackTop(stack);
            printf("\n xx stack dataPtr -> %c \n", *(char*)top->dataPtr);
            popStack(stack);
            printf("\n after stack dataPtr -> %c \n", *(char*)top->dataPtr);
            printf("The Mismatched Parentheses in the Expression are:\t%c and %c\n", *(char*)top->dataPtr, expression[i]);
        }
    }

    return true;
}

int main()
{
    // get input
    char expression[MAX];
    printf("\nEnter an Algebraic Expression:\t");
    scanf("%s", expression);

    // compute
    STACK *stack = createStack();
    int validity = check_paranthesis(stack, expression, strlen(expression));

    // check result
    if (validity == 1)
        printf("The Expression is Valid\n");
    else
        printf("The Expression is Invalid\n");
}
