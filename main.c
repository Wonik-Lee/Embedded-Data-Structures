#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int input_map[15][15] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


typedef struct node
{
	int x;
	int y;
	int d; //direction
	struct node* next;
}node;

node* head, * tail;

//방향을 계산하는 배열 생성
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

void init_stack()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->next = tail;
	tail->next = tail;
}

void push(int x, int y, int d) {
	node* t;
	if ((t = (node*)malloc(sizeof(node))) == NULL) {
		printf("Out of memory!\n");
		return;
	}
	t->x = x;
	t->y = y;
	t->d = d;
	t->next = head->next;
	head->next = t;
}

node* pop() {
	node* t;
	t = head->next;
	head->next = t->next;
	return t;
}

int stack_empty() {
	if (head->next == tail) {
		return 1;
	}
	else return 0;
}

void print_array() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			printf("%2d", input_map[i][j]);
		}
		printf("\n");
	}
}


void fill(int x, int y, int color) {
	int i;
	int d=0;
	int done = 0;
	node* t;
	
	while (!done){
		
		while (d < 8) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 ||nx >= 15 || ny < 0 ||ny >= 15) {
				d++;
				continue;
			}

			if (input_map[ny][nx] == 1) {
				push(x, y, d);
				x = nx;
				y = ny;
				input_map[y][x] = color;
				d = 0;
				continue;
			}
			d++;
		}

		if (!stack_empty()) {
			t = pop();
			x = t->x;
			y = t->y;
			d = t->d+1;
			free(t);
			continue;
		}
		else {
			done = 1;
		}

	}
}

int start_or_not(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx>14 || ny < 0 || ny>14) return 0;
		if (input_map[ny][nx] == 1) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	int color=1;

	init_stack();

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (start_or_not(j, i)) {
				color++;
				fill(j, i, color);
			}
		}
	}

	print_array();

	return 0;
}

