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
