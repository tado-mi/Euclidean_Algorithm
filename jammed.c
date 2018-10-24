#include <stdio.h>
#include <stdlib.h>

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

typedef struct stack *stack;
struct stack{
	
	tuple data;
	stack next;

};

stack new_stack(tuple i){
	
	stack me = (stack) malloc(sizeof(struct stack));
	(*me).data = i;
	(*me).next = NULL;
	
	return me;
	
}

void print_stack(stack head){
	
	stack temp = head;
	while(temp != NULL){
		
		print_tuple((*temp).data);
		temp = (*temp).next;
		
	}
	
	printf("_______\n\n");
	
}

stack pop(stack head){
	
	stack temp = head;
	if (head != NULL) head = (*head).next;	
	return head;
	
}

stack push(stack head, tuple i){
	
	stack temp = head;
	head = new_stack(i);

	if (temp != NULL) (*head).next = temp;

	return head;
	
}

// gcd with stack
stack gcd_st(int a, int b, stack S) {
	
	if (a < b) return gcd_st(b, a, S);
	
	int q = a / b;
	int r = a - q * b;
	
	S = push(S, new_tuple(a, b, q, r));
	if (r == 0) return S;
	
	return gcd_st(b, r, S);
	
}

// normal gcd
int gcd(int a, int b){
	
	stack S = new_stack(NULL);
	S = gcd_st(a, b, S);
	print_stack(S);
	return (*(*S).data).b;
	
}

stack rev_euclid(int a, int b){
	
	stack S = new_stack(NULL);
	S = gcd_st(a, b, S);
	
	if ((*(*S).data).r == 0) S = pop(S);
	stack V = new_stack(NULL);
	
	while ((*S).data != NULL) {
		
//		top of the calls of (normal) euclidean algorithm
//		focus: a = bq + rc
		tuple focus = (*S).data;
		
//		intitially: c = 1
//		so, r = b(-q) + a
		tuple new_focus = new_tuple((*focus).r, (*focus).b, -(*focus).q, (*focus).a);
		
//		previous tuple used to insert the previous values of a, q, r and c
		tuple pre = (*V).data;
		
		if (pre != NULL) {
			
			(*new_focus).q = (*new_focus).q * (*pre).q + (*pre).c;
			(*new_focus).b = (*pre).r;
			(*new_focus).a = (*pre).a;
			(*new_focus).c = (*pre).q * (*new_focus).c;
			
		}
		
		V = push(V, new_focus);
		S = pop(S);
		
//		damage control JIC
		if (S == NULL) break;
		
	}
	
	return V;

}

//	finding the Bézout identity:
//	integers m and n such that am + bn = gcd(a, b)
tuple bezout(int a, int b) {

	stack S = new_stack(NULL);
	
//	gcd_st returns the stack of all recursive calls it had to make
	S = gcd_st(a, b, S);
	
//	top of the stack is a tuple of form x = g y + 0
//  needed to extract g = gcd(a, b)
	S = pop(S);
	
//	new stack for recursive calls
	stack V = rev_euclid(a, b);	
	
//	the last element of the stack is the Bézout identity for a and b
	return (*V).data;
	
}

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
