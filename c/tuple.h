#include <stdio.h>
#include <stdlib.h>

typedef struct tuple *tuple;

extern tuple new_tuple(int a, int b, int q, int r);
extern void print_tuple(tuple me);
extern int is_correct(tuple t);

extern int get_a(tuple t);
extern int get_b(tuple t);
extern int get_q(tuple t);
extern int get_r(tuple t);
extern int get_c(tuple t);

extern void set_c(tuple t, int c);
