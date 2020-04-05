#include "../tuple.h"

struct tuple {

	// a = b * q + r * c
	int a, b, q, r, c;

};

tuple new_tuple(int a, int b, int quotient, int remainder) {

	tuple me = malloc(sizeof(struct tuple));
	(*me).a = a;
	(*me).b = b;
	(*me).q = quotient;
	(*me).r = remainder;
	(*me).c = 1;
	return me;

}

void print_tuple(tuple me){

	if (me == NULL) return;

	printf("%d = ", (*me).a);

	if ((*me).b < 0) printf("(%d)", (*me).b);
	else printf("%d", (*me).b);

	printf(" × ");

	if ((*me).q < 0) printf("(%d)", (*me).q);
	else printf("%d", (*me).q);

	printf(" + ");

	if ((*me).r < 0) printf("(%d)", (*me).r);
	else printf("%d", (*me).r);

	if ((*me).c != 1) {

		printf(" × ");

		if ((*me).c < 0) printf("(%d)", (*me).c);
		else printf("%d", (*me).c);

	}

	printf("\n");


}

int is_correct(tuple me){

	int LHS = (*me).a;
	int RHS = ((*me).b * (*me).q) + ((*me).r * (*me).c);
	return LHS == RHS;

}

// getters
int get_a(tuple me) {
	return (*me).a;
}

int get_b(tuple me) {
	return (*me).b;
}

int get_q(tuple me) {
	return (*me).q;
}

int get_r(tuple me) {
	return (*me).r;
}

int get_c(tuple me) {
	return (*me).c;
}

void set_c(tuple me, int c) {
	(*me).c = c;
}
