#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* next;
}node;

node* head;

void josephus(int n, int m);
void insert_nodes(int k);
void delete_after(node* t);
char int2name(int t);


void main()
{
	int n, m;

	printf("Enter N and M :");
	scanf("%d %d", &n, &m);

	
	josephus(n, m);
}


// Function to delete every m-th node from a circular linked list of n nodes and print each deleted node
void josephus(int n, int m) {
	node* t;
	int i;
	insert_nodes(n);
	t = head;
	printf("\nAnswer : ");
	while (t != t->next) {
		for (i = 0; i < m - 1; i++) {
			t = t->next;
		}
		printf("%c ", int2name(t->next->key));
		delete_after(t);
	}
	printf("%c", int2name(t->key));
}


// Create a circular linked list with k nodes
void insert_nodes(int K)
{
	node* t;
	int i;
	t = (node*)calloc(1, sizeof(node));
	t->key = 1;
	head = t;
	for (i = 2; i <= K; i++) {
		t->next = (node*)calloc(1, sizeof(node));
		t = t->next;
		t->key = i;
	}
	t->next = head;
}


// delete the node after the node t
void delete_after(node* t)
{
	node* s;
	s = t->next;
	t->next = t->next->next;
	free(s);
}


// change int to char
char int2name(int t)
{
	return t + 'A'-1;
}
