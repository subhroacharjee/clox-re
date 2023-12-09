#include "doubly_linked_list.h"

void panic(char *msg) {
  fprintf(stderr, "%s", msg);
  exit(1);
}

DoublyLinkedList *newDoubleLinkedList() {
  return (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
}

void dispose(DoublyLinkedList *ptr) {
  if (ptr == NULL)
    return;
  Node *node = ptr->pStart;

  while (node != NULL) {
    Node *tmp = node;
    node = node->pNext;
    free(tmp);
  }

  free(ptr);
}

void append(DoublyLinkedList *ptr, String str) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = str;

  ptr->size++;
  if (ptr->pStart == NULL) {
    ptr->pStart = node;
    ptr->pEnd = node;
    return;
  }

  Node *tmp = ptr->pEnd;
  node->pPrevious = tmp;
  tmp->pNext = node;
  ptr->pEnd = node;
}

void prepend(DoublyLinkedList *ptr, String str) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = str;

  ptr->size++;
  if (ptr->pStart == NULL) {
    ptr->pStart = node;
    ptr->pEnd = node;
    return;
  }

  Node *tmp = ptr->pStart;
  node->pNext = tmp;
  tmp->pPrevious = node;
  ptr->pStart = node;
}

void insert(DoublyLinkedList *ptr, String str, int idx) {
  if (idx > ptr->size) {
    String buffer = (String)malloc(100 * sizeof(char));
    sprintf(buffer,
            "index out of bound: size of list is %d and idx requested is %d",
            ptr->size, idx);
    panic(buffer);
  }

  if (idx == 0) {
    prepend(ptr, str);
    return;
  }
  if (idx == ptr->size) {
    append(ptr, str);
    return;
  }

  Node *node = (Node *)malloc(sizeof(Node));
  node->val = str;

  Node *tmp = ptr->pStart;
  for (int i = 0; i < idx; i++) {
    tmp = tmp->pNext;
  }
  Node *prevTmp = tmp->pPrevious;

  node->pPrevious = prevTmp;
  prevTmp->pNext = node;

  node->pNext = tmp;
  tmp->pPrevious = node;

  ptr->size++;
}

void print(DoublyLinkedList *ptr) {
  Node *tmp = ptr->pStart;

  for (int i = 0; i < ptr->size; i++) {
    printf("%s ", tmp->val);
    tmp = tmp->pNext;
  }
  printf("\n");
}

void printReverse(DoublyLinkedList *ptr) {
  Node *tmp = ptr->pEnd;

  for (int i = ptr->size - 1; i >= 0; i--) {
    printf("%s ", tmp->val);
    tmp = tmp->pPrevious;
  }
  printf("\n");
}

int indexOf(DoublyLinkedList *ptr, String val) {
  Node *tmp = ptr->pStart;
  int ans = -1;
  int counter = 0;
  while (tmp != NULL) {
    if (!strcmp(tmp->val, val)) {
      return counter;
    }
    counter++;
    tmp = tmp->pNext;
  }
  return ans;
}

void removeNode(DoublyLinkedList *ptr, String val) {
  int idx = indexOf(ptr, val);
  if (idx == -1)
    return;

  Node *node;
  if (idx == 0) {
    node = ptr->pStart;
    ptr->pStart = node->pNext;
    node->pNext->pPrevious = NULL;
  } else if (idx == ptr->size - 1) {
    node = ptr->pEnd;
    ptr->pEnd = node->pPrevious;
    node->pPrevious->pNext = NULL;
  } else {
    node = ptr->pStart;

    for (int i = 0; i < idx; i++) {
      node = node->pNext;
    }

    node->pPrevious->pNext = node->pNext;
    node->pNext->pPrevious = node->pPrevious;
  }
  free(node);
  ptr->size--;
}
