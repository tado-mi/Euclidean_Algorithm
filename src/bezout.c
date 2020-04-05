#include "../bezout.h"

// reversing the STACK of the Euclidean algorithm
STACK rev_euclid(int a, int b) {

	STACK S = gcd_st(a, b);
	if (get_r(peek(S)) == 0) {
		pop(S);
	}

	STACK V = new_STACK();

	while (!is_empty(S)) {

		// top of the calls of (normal) Euclidean algorithm
		// tmp: a = bq + rc
		tuple tmp = pop(S);

		// intitially: c = 1
		// so, r = b(-q) + a
		int a =	get_r(tmp);
		int b = get_b(tmp);
		int q = - get_q(tmp);
		int r = get_a(tmp);

		tuple focus = new_tuple(a, b, q, r);

		// previous tuple used to insert the previous values of a, q, r and c
		tuple pre = peek(V);


		if (pre != NULL) {

			a = get_a(pre);
			b = get_r(pre);
			q = get_q(focus) * get_q(pre) + get_c(pre);

			focus = new_tuple(a, b, q, get_r(focus));

			int c = get_q(pre) * get_c(focus);
			set_c(focus, c);

		}

		push(V, focus);

	}

	return V;

}

// finding the Bézout identity: integers x and y such that ax + by = gcd(a, b)
tuple identity(int a, int b) {

	STACK V = rev_euclid(a, b);
	if (is_empty(V)) {
		printf("\n\terror: Bézout identiy(%d, %d) on reverse Euclidean\n", a, b);
		return NULL;
	}

	// the last element of the STACK is the Bézout identity for a and b
	return peek(V);

}

// find the inverse of int a mod n, if such exists
int inverse(int x, int n) {

	if (x == 1) {
		return 1;
	}

	if (x > n) {
		x = x % n;
	}

	tuple temp = identity(x, n);
	if (temp == NULL || get_a(temp) != 1) {

		printf("\n\terror: inverse(%d, mod %d)\n", x, n);
		return -1;

	}

	int ans = 0;

	if (x == get_b(temp)) ans = get_q(temp);
	else ans = get_r(temp);

	while (ans < 0) ans = ans + n;
	return ans;

}
