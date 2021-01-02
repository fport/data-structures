#include <stdio.h> 
#include <stdlib.h> 


typedef struct Node
{ 
      int data; 
      struct Node* next; 
}NODE; 

void append(struct Node** start, int data) {
  struct Node* new_node ;
  new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = data;
   new_node->next = (*start);
   (*start) = new_node;
}
int count_recursive(struct  Node* start) {
   if (start == NULL)
      return 0;
   return 1 + count_recursive(start->next);
}

int count_iterative(struct Node* start) {
   int count = 0;
   struct Node* current = start;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}
int main() {
   struct Node* start = NULL;
   append(&start, 1);
   append(&start, 3);
   append(&start, 1);
   append(&start, 2);
   append(&start, 2);
   append(&start, 1);
   append(&start, 1);

   printf("Dugum sayisi : %d ",count_iterative(start));
}
