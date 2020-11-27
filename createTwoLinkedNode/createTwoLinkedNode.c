#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* dataPtr;
    struct node* link;
}NODE;

NODE* createNode (void* itemPtr) {
    NODE* nodePtr;
    nodePtr = (NODE*)malloc(sizeof(NODE));
    nodePtr->dataPtr = itemPtr;
    nodePtr->link = NULL;
    return nodePtr;
}

int main(){
    //Local Definitions
    int* newData;
    int* nodeData;
    NODE* node;
    //statements

    newData = (int*)malloc(sizeof(int));
    *newData=16;
    node = createNode(newData);

    newData = (int*)malloc(sizeof(int));
    *newData=78;
    node->link =createNode(newData);

    nodeData = (int*)node->dataPtr;
    printf("Data from node 1: %d\n", *nodeData);
    
    nodeData = (int*)node->link->dataPtr;
    printf("Data from node 2: %d\n", *nodeData);
    return 0 ;
}
