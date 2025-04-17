#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack[MAX];
int top;


typedef struct node
{
	int key;
	struct node* next;
}node;

node* head, *tail;


//============================[Array based Stack]====================================

void init_stack(void)
{
	top = -1;
}


int push(int t)
{
	if (top >= MAX - 1)
	{
		printf("Stack overflow!!!\n");
		return -1;
	}
	stack[++top] = t;
	return t;
}


int pop()
{
	if (top < 0){
		printf("Stack underflow!!!\n");
		return -1;
	}
	return stack[top--];
}


void print_stack()
{
	int i;
	for (i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
}


//=========================[Linked list based Stack]=================================

void init_stack_list()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->next = tail;
	tail->next = tail;
}


// push at head next
int push_list(int k)
{
	node* t;
	if ((t = (node*)malloc(sizeof(node))) == NULL)
	{
		printf("Out of memory!\n");
		return -1;
	}

	t->key = k;
	t->next = head->next;
	head->next = t;

	return k;
}


// pop at head next
int pop_list()
{
	node* t;
	int k;
	if (head->next == tail)
	{
		printf("Stack underflow!\n");
		return -1;
	}
	t = head->next;
	k = t->key;
	head->next = t->next;
	free(t);

	return k;
}


// clear stack list
void clear_list()
{
	node* t, * s;
	t = head->next;
	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}
	head->next = tail;
}


void print_stack_list()
{
	node* t;
	t = head->next;
	while (t != tail) {
		printf("%-6d", t->key);
		t = t->next;
	}
}




void main()
{
	int k;
	
	//--------array stack-----------
	init_stack();
	push(3);
	push(6);
	push(9);
	push(1);
	push(6);
	push(3);
	push(4);
	push(8);
	push(7);
	push(2);
	push(0);        // 11th data <-- Stack overflow
	print_stack();
	init_stack();   // initialize stack
	pop();          // stack underflow


	//--------------list stack-------------------
	init_stack_list();
	push_list(3);
	push_list(6);
	push_list(9);
	push_list(1);
	push_list(6);
	push_list(3);

	print_stack_list();
}
