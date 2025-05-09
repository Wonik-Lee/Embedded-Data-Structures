#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode
{
	int key;
	struct _dnode* prev;
	struct _dnode* next;
}dnode;

dnode* head, * tail;

void init_dlist();
dnode* insert_dnode_ptr(int k, dnode* t);
int delete_dnode_ptr(dnode* p);
dnode* find_dnode(int k);
int delete_dnode(int k);
dnode* insert_dnode(int k, int t);
dnode* ordered_insert(int k);
void delete_all();
void print_dlist(dnode* p);


void main()
{
	dnode* t;

	init_dlist();
	ordered_insert(9);
	ordered_insert(3);
	ordered_insert(5);
	ordered_insert(1);
	ordered_insert(7);   // list : 1 3 5 7 9

	print_dlist(head->next);


	t = find_dnode(5);
	printf("\nFinding 5 is %ssuccessful\n", t == tail ? "un" : "");

	insert_dnode_ptr(4, t); // list : 1 3 4 5 7 9

	insert_dnode(2, 9);     // list : 1 3 4 5 7 2 9

	delete_dnode(4);        // list : 1 3 5 7 2 9

	print_dlist(head->next);

}

// initialize doubly linked list
void init_dlist()
{
	head = (dnode*)calloc(1, sizeof(dnode));
	tail = (dnode*)calloc(1, sizeof(dnode));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

// insert data k before the dnode t
dnode* insert_dnode_ptr(int k, dnode* t)
{
	dnode* i;
	if (t == head) return NULL;
	i = (dnode*)calloc(1, sizeof(dnode));
	i->key = k;
	t->prev->next = i;
	i->prev = t->prev;
	t->prev = i;
	i->next = t;
	return i;
}

// delete the dnode p
int delete_dnode_ptr(dnode* p)
{
	if (p == head || p == tail)
		return 0;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	return 1;
}

// find the dnode that contains k
dnode* find_dnode(int k)
{
	dnode* s;
	s = head->next;
	while (s->key != k && s != tail)
		s = s->next;
	return s;
}

// delete the node containg k data
int delete_dnode(int k)
{
	dnode* s;
	s = find_dnode(k);
	if (s != tail)
	{
		s->prev->next = s->next;
		s->next->prev = s->prev;
		free(s);
		return 1;
	}
	return 0;
}

// insert data k before the dnode containing data t
dnode* insert_dnode(int k, int t)
{
	dnode* s;
	dnode* i = NULL;
	s = find_dnode(t);
	if (s != tail)
	{
		i = (dnode*)calloc(1, sizeof(dnode));
		i->key = k;
		s->prev->next = i;
		i->prev = s->prev;
		s->prev = i;
		i->next = s;
	}
	return i;
}

// Inserts k into the list while maintaining sorted order.
// Assumes the list is already sorted before the function is called.
dnode* ordered_insert(int k)
{
	dnode* s;
	dnode* i;
	s = head->next;
	while (s->key <= k && s != tail)
		s = s->next;
	i = (dnode*)calloc(1, sizeof(dnode));
	i->key = k;
	s->prev->next = i;
	i->prev = s->prev;
	s->prev = i;
	i->next = s;
	return i;
}


// delete all
void delete_all()
{
	dnode* p;
	dnode* s;
	p = head->next;
	while (p != tail)
	{
		s = p;
		p = p->next;
		free(s);
	}
	head->next = tail;
	tail->prev = head;
}


// print dlist
void print_dlist(dnode* p)
{
	printf("\n");
	while (p != tail)
	{
		printf("%-8d", p->key);
		p = p->next;
	}
}
