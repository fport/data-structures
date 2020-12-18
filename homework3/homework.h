#ifndef HOMEWORK_STUDENT_H
#define HOMEWORK_STUDENT_H

/* C libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* student object */
typedef struct Student Student;
struct Student {
  int id;
  char *name;
  char *surname;
  char *subject;
  char *class;
  Student *left, *right;
};

/* methods */
Student *new_Student(int id, char *name, char *surname, char *subject, char *class);
void free_Student(Student *self);
void Student_print(Student *self);

/* list wrapper object */
typedef struct {
  int count;
  Student *head;
  Student *tail;
} List;

/* methods */
List *new_List();
void free_List(List *self);
void List_print(List *self);

void List_push(List *self, Student *s);
Student *List_pop(List *self);

void List_insert(List *self, int idx, Student *s);
Student *List_index(List *self, int idx);

#endif
