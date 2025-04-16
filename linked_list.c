#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node* next;
}node;

node* head, * tail;

//list ÃÊ±âÈ­
void init_list()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->next = tail;
	tail->next = tail;
}

// insert data k after the node t
node* insert_after(int k, node* t)
{
	node* temp;
	temp = (node*)calloc(1, sizeof(node));
	temp->key = k;
	temp->next = t->next;
	t->next = temp;

	return temp;
}

// delete the node next to the t node
int delete_next(node* t)
{
	node* temp;
	if (t->next == tail)
		return 0;
	temp = t->next;
	t->next = t->next->next;
	free(temp);

	return 1;
}

// find a node containing data k
node* find_node(int k)
{
	node* temp;

	temp = head->next;
	while (temp->key != k && temp != tail) {
		temp = temp->next;
	}

	return temp; 
}

// delete the node that contains data k
int delete_node(int k)
{
	node* s, * p;
	p = head;
	s = p->next;
	while (s->key != k && s != tail) {
		p = p->next;
		s = p->next;
	}
	if (s != tail) {
		p->next = s->next;
		free(s);
		return 1;
	}
	else return 0;
}

// Inserts a new node with data t before the node containing data k
node* insert_node(int t, int k)
{
	node* s, * p, * r;
	p = head;
	s = p->next;
	while (s->key != k && s != tail) {
		p = p->next;
		s = p->next;
	}
	if (s != tail) {
		r = (node*)calloc(1, sizeof(node));
		r->key = t;
		p->next = r;
		r->next = s;
	}
	return p->next;
}

// Inserts k into the list while maintaining sorted order
// Assumes the list is already sorted before the function is called
node* ordered_insert(int k)
{
	node* s, * p, * r;
	p = head;
	s = p->next;
	while (s->key <= k && s != tail) {
		p = p->next;
		s = p->next;
	}
	r = (node*)calloc(1, sizeof(node));
	r->key = k;
	p->next = r;
	r->next = s;

	return r;
}

// delete all
node* delete_all()
{
	node* s, * t;
	t = head->next;
	while (t != tail) {
		s = t;
		t = t->next;
		free(s);
	}
	head->next = tail;
	return head;
}

// print list
void print_list(node* t)
{
	while (t != tail) {
		printf("%-8d", t->key);
		t = t->next;
	}
	printf("\n");
}

// Function to find the index of the node containing data k
int find_index(int k)
{
	node* temp;
	int cnt = 1;
	temp = head->next;
	while (temp->key != k && temp != tail) {
		temp = temp->next;
		cnt++;
	}
	if (temp != tail) {
		return cnt;
	}
	else return 0;
}




void main()
{
	node* t;
	
	init_list();
	ordered_insert(9);
	ordered_insert(3);
	ordered_insert(5);
	ordered_insert(1);
	ordered_insert(7);

	print_list(head->next);

	// Insert 6 after 5 and print out the current list
	t = find_node(5);
	insert_after(6, t);
	print_list(head->next);

	// delete node containing data 5
	delete_node(5);
	print_list(head->next);

	// find the node that contains data 6, and print it's index
	printf("%d", find_index(6));


}