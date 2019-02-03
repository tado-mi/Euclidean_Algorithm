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
	
	if (head != NULL) head = (*head).next;	
	return head;
	
}

stack push(stack head, tuple i){
	
	stack temp = head;
	head = new_stack(i);

	if (temp != NULL) (*head).next = temp;

	return head;
	
}

