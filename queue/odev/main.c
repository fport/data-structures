#include "header.h"

/* is operator */
bool isOperand(char token)
{
    if(token=='*' || token=='/' || token=='+' || token=='-')
        return true;
    return false;
}

double evve (QUEUE *queue) {
    char token;
    printf("Lutfen prefix ifadenizi giriniz: \n");

    while ((token = getchar()) != '\n')
    {
        if(isOperand(token))
        {
            enqueue(queue,token);
        }
        else
        {
            double o1 = (double *)(queue -> rear -> dataPtr);
            double o2 = (double *)(&(queue -> rear -> dataPtr));

            switch (token) {
            case '+':
                enqueue(queue,(o1 + o2));
                break;
            case '-':
                enqueue(queue,(o1 - o2));
                break;
            case '*':
                enqueue(queue,(o1 * o2));
                break;
            case '/':
                enqueue(queue,(o1 / o2));
                break;
            }
        }
        return queue-> rear -> dataPtr;
    }
}

/*
while Q has more than 1 element
   if the pattern operand, number, number occurs
         op=dequeue(Q)
         num1=dequeue(Q)
         num2=dequeue(Q)
         eval=evaluate(op,num1,num2)
         enqueue(Q,eval)
   else
         elem=dequeue(Q)
         enqueue(Q,elem)
*/
int main()
{

    QUEUE *queue;
    queue = createQueue();

    evve(queue);
    
    return 0;
}
