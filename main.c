#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node* next;
}node;

node* head, * tail;

//list 초기화
void init_list()
{
	head = (node*)calloc(1, sizeof(node));
	tail = (node*)calloc(1, sizeof(node));
	head->next = tail;
	tail->next = tail;
}

//k를 t 다음에 배치하는 함수
node* insert_after(int k, node* t)
{
	node* temp;
	temp = (node*)calloc(1, sizeof(node));
	temp->key = k;
	temp->next = t->next;
	t->next = temp;

	return temp;
}

//t의 next node를 지우고 싶을 때
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

//찾는 데이터의 주소를 불러오는 함수
node* find_node(int k)
{
	node* temp;

	temp = head->next;
	while (temp->key != k && temp != tail) {
		temp = temp->next;
	}

	return temp;
}

//k데이터를 지우는 함수
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

//t라는 데이터를 k값 전 단계에 insert하는 함수
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

//정렬하면서 insert하는 함수
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

//리스트를 전부 지우는 법
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

//리스트 출력
void print_list(node* t)
{
	while (t != tail) {
		printf("%-8d", t->key);
		t = t->next;
	}
	printf("\n");
}

//몇번째 데이터인지 알려주는 함수
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

	//5 뒤에 6 삽입
	t = find_node(5);
	insert_after(6, t);
	print_list(head->next);

	//5삭제
	delete_node(5);
	print_list(head->next);

	//6이 몇번째 인덱스인지 찾기
	printf("%d", find_index(6));


}