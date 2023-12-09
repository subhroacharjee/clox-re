#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *String;

typedef struct Node {
  String val;
  struct Node *pNext;
  struct Node *pPrevious;
} Node;

typedef struct DoublyLinkedList {
  Node *pStart, *pEnd;
  int size;
} DoublyLinkedList;

void panic(char *msg);

DoublyLinkedList *newDoubleLinkedList();

void dispose(DoublyLinkedList *ptr);

void append(DoublyLinkedList *ptr, String str);

void prepend(DoublyLinkedList *ptr, String str);

void insert(DoublyLinkedList *ptr, String str, int idx);

void print(DoublyLinkedList *ptr);

void printReverse(DoublyLinkedList *ptr);

int indexOf(DoublyLinkedList *ptr, String val);

void removeNode(DoublyLinkedList *ptr, String val);

#endif /* DOUBLYLINKEDLIST_H */
