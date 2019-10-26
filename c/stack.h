#include <stdio.h>
#include <stdlib.h>

#include "tuple.h"

typedef struct stack *stack;
extern stack new_stack();
extern stack reverse(stack s);
extern void print_stack(stack s, void (*f)());
extern void* pop(stack s);
extern void* peek(stack s);
extern void push(stack s, void* data);
extern int is_empty(stack s);
