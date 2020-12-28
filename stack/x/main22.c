#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

#define MAX 50

/* createStack method */
STACK *createStack (void){
    STACK *stack = (STACK *)malloc(sizeof(STACK));  
    if(stack){
        stack -> count = 0;
        stack -> top = NULL;
    }
    return stack;
}

/* pushStack method */
bool pushStack (STACK *stack, char *dataInPtr){
    NODE *newPtr = (NODE*)malloc(sizeof(NODE));
    if(!newPtr){
        return false;
    }

    newPtr -> dataPtr = dataInPtr;

    newPtr -> link = stack -> top;
    stack -> top = newPtr;

    (stack->count)++;
    return true;
}

/* popStack method*/
void *popStack (STACK *stack){
    void *dataOutPtr ; 
    NODE  *temp ;

    if(stack -> count == 0){
        dataOutPtr = NULL;
    }else {
        temp = stack -> top;
        dataOutPtr = stack -> top ->dataPtr;
        stack -> top = stack -> top -> link;
        free(temp);
        (stack->count)--;
    }
    return dataOutPtr;
}

/*stackTop method */
void *stackTop (STACK *stack){
    //statements
    if(stack->count == 0){
        return NULL;
    }else{
        return stack -> top ->dataPtr;
    }
}


/* #<{(| isEmptyStack method |)}># */
/* bool emptyStack (STACK *stack){ */
/*     //statements */
/*     return (stack -> count == 0); */
/* } */


/* #<{(| fullStack |)}># */
/* bool fullStack (STACK *stack){ */
/*     NODE *temp; */
/*  */
/*     if((temp = (NODE *)malloc(sizeof(*(stack->top))))){ */
/*         free(temp); */
/*         return false; */
/*     } */
/*     return true; */
/* } */


/* #<{(| stackCount |)}># */
/* int stackCount (STACK *stack){ */
/*     return stack -> count ; */
/* } */

/* #<{(| all delete eleman / destroy stack |)}># */
/* STACK *destroyStack (STACK *stack){ */
/*     NODE *temp; */
/*  */
/*     if(stack){ */
/*         while(stack->top !=NULL){ */
/*             free(stack->top->dataPtr); */
/*  */
/*             temp  = stack->top; */
/*             stack ->top =stack -> top ->link; */
/*             free(temp); */
/*         } */
/*         free(stack); */
/*     } */
/*     return NULL; */
/* } */

// control 
/* char pop(STACK *stack) */
/* { */
/*       if(stack -> count == 0) */
/*       { */
/*             printf("Stack is Empty\n"); */
/*             exit(1); */
/*       } */
/*       NODE *temp; */
/*       temp = stack -> top -> link -> dataPtr; */
/*  */
/*       return temp; */
/* } */

/* match Parentheses */
bool match_paranthesis(STACK *stack, char b)
{                                      
      if(*(int *)(stack -> top -> dataPtr) == '{' && b == '}')
      {
            return true;
      }
      else if(*(int *)(stack -> top -> dataPtr) == '(' && b == ')')
      {
            return true;
      }
      return false;
}

bool check_paranthesis(STACK *stack ,char expression[], size_t n){

      /* STACK *stack = (STACK *) malloc(sizeof(STACK)); */
      int count;
      char temp;
      for(count = 0; count < n; count++)
      {
        if(expression[count] == '(' || expression[count] == '{' )
        {
              pushStack(stack,&expression[count]);
        }
        if(expression[count] == ')' || expression[count] == '}' )
        {
          if(stack -> count == 0)
          {
                printf("The Right Parentheses are more than the Left Parentheses\n");
                return 0;
          }
          else
          {
                stackTop(stack);
                printf("%d",*((int *)stack ->top -> dataPtr));

                if(!match_paranthesis(stack, expression[count]))
                {
                      printf("The Mismatched Parentheses in the Expression are:\t%c and %c\n", *((int *)stack ->top -> dataPtr), expression[count]);
                      return 0;
                }
          }
        }
      }
      if(stack -> count == 0)
      {
            printf("\nThe Expression has Balanced Parentheses\n");
            return 1;
      }
      else
      {
            printf("The Expression has unbalanced parentheses\n");
            return 0;
      }
}



int main()
{
      STACK *stack = (STACK *) malloc(sizeof(STACK));
      char expression[MAX];
      int validity;
      printf("\nEnter an Algebraic Expression:\t");
      scanf("%s", expression);
      validity = check_paranthesis(stack, expression,strlen(expression));
      if(validity == 1)
      {
            printf("The Expression is Valid\n");
      }
      else
      {
            printf("The Expression is Invalid\n");
      }
      return 0;
    
}
