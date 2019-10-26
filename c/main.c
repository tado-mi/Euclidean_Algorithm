#include <stdio.h>
#include <stdlib.h>

// data structures
#include "stack.h"
#include "tuple.h"

// actual functions
#include "gcd.h"
#include "bezout.h"

int main(){

	int a = 150;
	int b = 57;

	int g = gcd(a, b);
	printf("gcd(%d, %d) = %d\n\n", a, b, g);

	printf("Bézout identity: ");
	tuple test = identity(a, b);
	print_tuple(test);
	printf("is Bézout identity correct: %d\n\n", is_correct(test));

	// calculating the inverse
	a = a / g;
	b = b / g;
	printf("Computing inverse(%d, %d): ", a, b);
	int inv = inverse(a, b);
	printf("%d\n", inv);

	return 0;

}
