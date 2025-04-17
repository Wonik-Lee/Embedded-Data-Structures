#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int stack[MAX];
int top;

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
	if (top < 0)
	{
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


// return the last input data
int get_stack_top()
{
	return (top < 0) ? -1 : stack[top];
}


// return True if k is operation
int is_op(int k)
{
	return (k == '+' || k == '-' || k == '*' || k == '/');
}


// check the priority. higher number has higher priority
int precedence(int op)
{
	if (op == '(') return 0; if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2; else return 3;
}


// return 1 if stack is empty
int is_stack_empty() {
	return top == -1;
}


// This implementation does not handle operator precedence,
// so expressions must use parentheses to ensure correct evaluation order
// src is input string, postfix equation will be stored in dst string
void postfix(char* dst, char* src)
{
	char c;
	init_stack();

	while (*src) {
		if (*src == ')')
		{
			*dst++ = pop();
			*dst++ = ' ';
			src++; // read next char
		} 
		else if (*src == '+' || *src == '-' || *src == '*' || *src == '/')
		{
			push(*src);
			src++;
		}
		else if (*src >= '0' && *src <= '9')
		{
			do {
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else
			src++;
	}
	*dst = 0; // so we can read dst string at the begin
}



// This implementation handles operator precedence
void postfix_2(char* dst, char* src) {
	char c;
	init_stack();
	while (*src) {
		if (*src == '(')
		{
			push(*src);
			src++;
		}
		else if (*src == ')') {
			while (get_stack_top() != '(') {
				*dst++ = pop();
				*dst++ = ' ';
			}
			pop();   // discard "("
			src++;
		}
		else if (is_op(*src)) {
			while (!is_stack_empty() && precedence(get_stack_top()) >= precedence(*src)) {

				*dst++ = pop();
				*dst++ = ' ';
			}
			push(*src);
			src++;
		}
		else if (*src >= '0'&& *src <= '9'){
			do {
				*dst++ = *src++;
			} while (*src >= '0' && *src <= '9');
			*dst++ = ' ';
		}
		else
			src++;
	}
	while (!is_stack_empty()) {
		*dst++ = pop();
		*dst++ = ' ';
	}
	dst--;
	*dst = 0;
}



void main()
{
	char exp[256];
	char src[256] = "(1*(2+3/4)+5)/6+7";
	

	postfix_2(exp, src);
	printf("Postfix representation : %s\n", exp);  // exp : 1234/+*5+6/7+
}