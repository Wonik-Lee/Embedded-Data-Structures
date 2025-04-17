#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



//================================[Array based Queue]=======================================

#define MAX 10

int queue[MAX];
int front, rear;


// initialize queue to start
void init_queue_arr()
{
	front = 0;
	rear = 0;
}

// delete queue data
void clear_queue_arr()
{
	front = rear;
}


// Enqueue: put data 'k' at the position pointed by 'rear' and then rear+1
// If the queue is full, return -1 and print overflow message
int put_arr(int k)
{
	if ((rear + 1) % MAX == front) {
		printf("Queue overflow!!!\n");
		return -1;
	}

	queue[rear] = k;
	rear = (++rear) % MAX;

	return k;
}


// Dequeue: get data from the position pointed by 'front' and then front+1
// If the queue is empty, return -1 and print underflow message
int get_arr()
{
	int j;

	if (front == rear) {
		printf("Queue underflow!!!\n");
		return -1;
	}

	j = queue[front];
	front = ++front % MAX;

	return j;
}


//================================[List based Queue]=======================================

typedef struct _dnode
{
	int key;
	struct _dnode* prev;
	struct _dnode* next;
}dnode;

dnode* head, * tail;


// initialize queue
void init_queue()
{
	head = (dnode*)calloc(1, sizeof(dnode));
	tail = (dnode*)calloc(1, sizeof(dnode));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
}


// put data k before the tail. tail is rear
int put(int k)
{
	dnode* t;
	if ((t = (dnode*)malloc(sizeof(dnode))) == NULL)
	{
		printf("Out of memory !\n");
		return -1;
	}
	t->key = k;
	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
	t->next = tail;
	return k;
}


// get data after the head. head is front
int get()
{
	dnode* t;
	int k;
	t = head->next;
	if (t == tail)
	{
		printf("Queue underflow\n");
		return -1;
	}
	k = t->key;
	head->next = t->next;
	t->next->prev = head;
	free(t);
	return k;
}


// delete all
void clear_queue()
{
	dnode* t, * s;
	t = head->next;
	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}
	head->next = tail;
	tail->prev = head;
}


void print_queue()
{
	dnode* t;
	t = head->next;
	while (t != tail) {
		printf("%-6d", t->key);
		t = t->next;
	}
}



void main()
{
	int k;
	init_queue();

	put(3);
	put(6);
	put(9);
	put(1);
	put(6);
	put(3);

	print_queue();   // 369163

	printf("\n");

	put(4);
	put(8);
	put(7);
	put(2);
	put(0);         // 369163 48720

	print_queue();

	printf("\n");

	printf("%d\n",get());

	init_queue();

	get();  // there is no data in queue. queue underflow
}