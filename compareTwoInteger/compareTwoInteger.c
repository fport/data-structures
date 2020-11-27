#include <stdio.h>
#include <stdlib.h>

void* larger(void* dataPtr1, void* dataPtr2, int(*ptrToCmpFun)(void*,void*)) {
    if((*ptrToCmpFun)(dataPtr1,dataPtr2) > 0)
        return dataPtr1;
    else
        return dataPtr2;
}//larger

int compare (void* ptr1, void* ptr2){
    if(*(int*)ptr1 >= *(int*)ptr2)
        return 1;
    else
        return -1;
}//compare

int main(){
    //local definitions
    int i=7;
    int j=8;
    int lrg;

    //statements
    lrg = (*(int*)larger(&i,&j,compare));
    
    printf("Larger value is: %d\n",lrg);
    return 0;
}
