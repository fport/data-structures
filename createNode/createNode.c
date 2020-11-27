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

int main() {
    //Local Definitions
    int* newData;
    int* nodeData;
    NODE* node;

    //Statements
    newData = (int*)malloc(sizeof(int));
    *newData=78;

    node = createNode(newData);

    nodeData = (int*)node->dataPtr;
    printf("Data from node : %d\n", *nodeData);
    return 0;
}
