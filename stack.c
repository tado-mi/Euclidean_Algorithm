#include "stack.h"

typedef struct node *node;
struct node {
  void* data;
  node next;
};

struct stack {
  node top;
};

stack new_stack() {
  stack s = malloc(sizeof(struct stack));
  (*s).top = NULL;
  return s;
}

stack reverse(stack s) {
  stack v = new_stack();
  while (!is_empty(s)) {
    node temp = pop(s);
    push(v, temp);
  }
  return v;
}

void push(stack s, void* data) {
  node new = malloc(sizeof(struct node));
  (*new).data = data;
  (*new).next = (*s).top;

  (*s).top = new;
}

void* pop(stack s) {
  if (is_empty(s)) {
    return NULL;
  }
  node top = (*s).top;
  (*s).top = (*top).next;
  return (*top).data;

}

void* peek(stack s) {
  if (is_empty(s)) {
    return NULL;
  }
  node top = (*s).top;
  return (*top).data;

}

int is_empty(stack s) {
  node top = (*s).top;
  return top == NULL;
}

// usage: print_stack(stack, &print_function_name)
void print_stack(stack s, void (*f)()) {// receive address of print  
  node top = (*s).top;
  while (top != NULL) {
    if (f == NULL) {
      printf("%s\n", (char*)(*top).data);
    } else {
      f((*top).data);
    }
    top = (*top).next;
  }
  printf("________________\n");
}
