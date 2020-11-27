typedef struct node {
    int number;
    struct node *link;
}NODE;

typedef struct {
    int count;
    NODE *pos;
    NODE *head;
    NODE *rear;
}LIST;
