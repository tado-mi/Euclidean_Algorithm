#include "../gcd.h"

// gcd with stack
STACK gcd_st(int a, int b) {

	if (a < b) {
		return gcd_st(b, a);
	}

	STACK S = new_STACK();
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

	STACK S =	gcd_st(a, b);
	return get_b(peek(S));

}
