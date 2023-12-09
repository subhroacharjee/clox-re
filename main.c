#include "src/doubly_linked_list.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  DoublyLinkedList *dll = newDoubleLinkedList();
  for (int i = 0; i < 5; i++) {
    prepend(dll, "Hello");
  }

  for (int i = 0; i < 5; i++) {
    append(dll, "World");
  }

  insert(dll, "Fucker", 5);

  print(dll);
  printf("-----------------\n");
  printReverse(dll);
  printf("-----------------\n");
  printf("index of Fucker %d\n", indexOf(dll, "Fucker"));
  printf("-----------------\n");
  printf("index of None %d\n", indexOf(dll, "None"));
  printf("-----------------\n");
  removeNode(dll, "Fucker");
  removeNode(dll, "Hello");
  print(dll);
  printf("-----------------\n");
  removeNode(dll, "World");
  printReverse(dll);
  printf("-----------------\n");

  dispose(dll);
}
