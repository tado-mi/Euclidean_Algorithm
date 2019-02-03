typedef struct tuple *tuple;
struct tuple{
	
	int a;
	int b;
	int q;
	int r;
	int c;
	
	// a = b * q + r * c
	
};

tuple new_tuple(int num_1, int num_2, int quotient, int remainder) {
	
	tuple me = malloc(sizeof(struct tuple));
	(*me).a = num_1;
	(*me).b = num_2;
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
	
	if ((*me).c == 1) {
		
		printf("\n");
		return;
		
	}
	
	printf(" × ");
	
	if ((*me).c < 0) printf("(%d)", (*me).c);
	else printf("%d", (*me).c);
	
	printf("\n");
	
	
}

int is_correct(tuple t){
	
	int LHS = (*t).a;
	int RHS = ((*t).b * (*t).q) + ((*t).r * (*t).c);
	return LHS == RHS;

}
