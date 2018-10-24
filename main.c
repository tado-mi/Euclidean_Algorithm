#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(){

	int a = 15042;
	int b = 57;
	
	printf("testing %d and %d\n\n", a, b);

	printf("Euclidean algorithm:\n");
	
	int g = gcd(a, b);
	printf("gcd(%d, %d) = %d\n", a, b, g);
	
	printf("\n");
	
	printf("reverse Euclidean algorithm:\n");
	stack V = rev_euclid(a, b);
	
//	turn V around for printing out in an intuitve order
	stack V_rev = new_stack(NULL);
	while((*V).data != NULL) {
		
		V_rev = push(V_rev, (*V).data);
		V = pop(V);
		
	}
	print_stack(V_rev);
	
	printf("Bézout identity: ");
	tuple test = bezout(a, b);
	print_tuple(test);
	
	printf("\n");
	
//	calling a method that checks the equlaity of LHS and RHS of a tuple
	int x = is_correct(test);
	printf("is Bézout identity correct: %d\n", x);
	
	return 0;

}
