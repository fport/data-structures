#include "homework.h"

Student *new_Student(int id, char *name, char *surname, char *subject, char *class)
{
  Student *self = malloc(sizeof(Student));
  *self = (Student){
    .id = id,
    .name = name,
    .surname = surname,
    .subject = subject,
    .class = class,
    .left = NULL,
    .right = NULL
  };
  return self;
}

void free_Student(Student *self)
{
  if (self == NULL)
    return;
  free_Student(self->right);
  free(self);
}

void Student_print(Student *self)
{
  printf(
    "(%d, %s, %s, %s, %s)",
    self->id,
    self->name,
    self->surname,
    self->subject,
    self->class
  );
  if (self->right)
    printf(", ");
}

List *new_List()
{
  List *newList = malloc(sizeof(List));
  *newList = (List){
    .count = 0,
    .head = NULL,
    .tail = NULL
  };
  return newList;
}

void free_List(List *self)
{
  free_Student(self->head);
}

void List_print(List *self)
{
  putchar('[');
  Student *p = self->head;
  while (p) {
    Student_print(p);
    p = p->right;
  }
  putchar(']');
  putchar('\n');
}

void List_push(List *self, Student *s)
{
  self->count++;

  if (self->tail == NULL) {
    self->head = s;
    self->tail = s;
    return;
  }

  s->left = self->tail;
  self->tail->right = s;
  self->tail = s;
}

Student *List_pop(List *self)
{
  if (self->count == 0)
    return NULL;
  self->count--;

  if (self->count == 1) {
    Student *s = self->head;
    self->head = NULL;
    self->tail = NULL;
    return s;
  }

  self->tail = self->tail->left;
  self->tail->right->left = NULL;

  Student *s = self->tail->right;
  self->tail->right = NULL;
  return s;
}

void List_insert(List *self, int idx, Student *s)
{
  if (self->count < idx)
    return;
  self->count++;

  Student *right = self->head;
  while (idx--)
    right = right->right;

  Student *left;
  left = right->left;

  left->right = s;
  right->left = s;
  s->left = left;
  s->right = right;
}

Student *List_index(List *self, int idx)
{
  if (self->count < idx)
    return NULL;

  Student *right = self->head;
  while (idx--)
    right = right->right;

  return right;
}

int main()
{
  /* create list */
  List *list = new_List();

  /* add to list */
  List_push(list, new_Student(1, "Bugra",  "Yildiz",   "Compilers", "BK201"));
  List_push(list, new_Student(2, "Furkan", "Portakal", "Web Dev",   "WD101"));
  List_push(list, new_Student(3, "Selcuk", "Tatar",    "Websec",    "WS301"));

  /* print list */
  List_print(list);

  /* remove from list */
  Student *selcuk = List_pop(list);
  List_insert(list, 1, selcuk);

  /* print list */
  List_print(list);

  /* index access to list */
  Student_print(List_index(list, 0));

  /* free list */
  free_List(list);
}
