/* header  file */
#include "header.h"



/* giving priority*/
int priority(char token)
{
    if(token=='*' || token=='/')
        return 2;
    if(token=='+' || token=='-')
        return 1;
    return 0;
}

bool isOperator(char token)
{
    if(token=='*' || token=='/' || token=='+' || token=='-')
        return true;
    return false;
}


int main ()
{
    char token;
    char* dataPtr;
    char postfix[80]={0};
    char temp[2]={0};

    STACK* stack = createStack();

    printf("Lutfen infix ifadenizi giriniz: \n");
    while((token=getchar())!='\n')
    {
        if(token=='(')
        {
            dataPtr=(char*)malloc(sizeof(char));
            *dataPtr=token;
            pushStack(stack,dataPtr);
        }
        else if(token==')')
        {
            dataPtr=(char*)popStack(stack);
            while(*dataPtr!='(')
            {
                temp[0]=*dataPtr;
                strcat(postfix,temp);
                dataPtr=(char*)popStack(stack);
            }
        }



        else if(isOperator(token))
        {
            dataPtr=(char*)stackTop(stack);
            while(!emptyStack(stack) && priority(token) <= priority(*dataPtr))
            {
                dataPtr=(char*)popStack(stack);
                temp[0]=*dataPtr;
                strcat(postfix,temp);
                dataPtr=(char*)stackTop(stack);
            }
            dataPtr=(char*)malloc(sizeof(char));
            *dataPtr=token;
            pushStack(stack,dataPtr);



        }



        else
        {
            temp[0]=token;
            strcat(postfix,temp);
        }
    }
    while(!emptyStack(stack))
    {
        dataPtr=(char*)popStack(stack);
        temp[0]=*dataPtr;
        strcat(postfix,temp);
    }
    printf("Postfix karsigilimiz = ");
    puts(postfix);
    destroyStack(stack);


}

