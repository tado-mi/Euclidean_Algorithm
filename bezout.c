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
		
//		damage control just in case
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
//	needed to extract g = gcd(a, b)
	S = pop(S);
	
//	new stack for recursive calls
	stack V = rev_euclid(a, b);	
	
//	the last element of the stack is the Bézout identity for a and b
	return (*V).data;
	
}
