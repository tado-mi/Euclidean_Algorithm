#include "gcd.h"

// gcd with stack
stack gcd_st(int a, int b) {

	if (a < b) {
		return gcd_st(b, a);
	}

	stack S = new_stack();
	int r = 0;

	do {

		int q = a / b;
		r = a - q * b;

		push(S, new_tuple(a, b, q, r));

		// reassign
		a = b;
		b = r;

	} while (r > 0);

	return S;

}

// normal gcd
int gcd(int a, int b){

	stack S =	gcd_st(a, b);
	return get_b(peek(S));

}
