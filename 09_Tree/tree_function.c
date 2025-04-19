#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node* head, * tail;
node* stack[MAX];
node* queue[MAX];
int top, front, rear;


//=================================[Tree access]====================================    

void init_tree() {
    head = (node*)calloc(1, sizeof(node));
    tail = (node*)calloc(1, sizeof(node));
    head->left = head->right = tail;
    tail->left = tail->right = tail;
}


node* make_parse_tree(char* p) {
    node* t;
    while (*p) {
        while (*p == ' ') p++;
        t = (node*)calloc(1, sizeof(node));
        t->key = *p;
        t->left = t->right = tail;
        if (is_operator(*p)) {
            t->right = pop();
            t->left = pop();
        }
        push(t);
        p++;
    }
    return pop();
}


//=================================[Pre-order Traverse]====================================    
void preorder_traverse(node* t) {
    if (t != tail) {
        visit(t);
        preorder_traverse(t->left);
        preorder_traverse(t->right);
    }
}

void nr_preorder_traverse(node* t) {
    init_stack();
    push(t);
    while (!is_stack_empty()) {
        node* current = pop();
        if (current == tail) continue;
        visit(current);
        push(current->right);
        push(current->left);
    }
}



//=============================[In-order Traverse]===============================    
void inorder_traverse(node* t) {
    if (t != tail) {
        inorder_traverse(t->left);
        visit(t);
        inorder_traverse(t->right);
    }
}

void nr_inorder_traverse(node* t) {
    init_stack();
    node* p = t;
    while (1) {
        while (p != tail) {
            push(p);
            p = p->left;
        }
        if (is_stack_empty()) break;
        p = pop();
        visit(p);
        p = p->right;
    }
}



//=============================[Post-order Traverse]===============================    
void postorder_traverse(node* t) {
    if (t != tail) {
        postorder_traverse(t->left);
        postorder_traverse(t->right);
        visit(t);
    }
}

void nr_postorder_traverse(node* t) {
    init_stack();
    node* current = t;
    node* last_visited = NULL;
    while (!is_stack_empty() || current != tail) {
        if (current != tail) {
            push(current);
            current = current->left;
        }
        else {
            node* peek_node = stack[top];
            if (peek_node->right != tail && last_visited != peek_node->right) {
                current = peek_node->right;
            }
            else {
                visit(peek_node);
                last_visited = pop();
            }
        }
    }
}



//=============================[Level-order Traverse]===============================    
void levelorder_traverse(node* t) {
    put(t);
    while (!is_queue_empty()) {
        t = get();
        visit(t);
        if (t->left != tail) put(t->left);
        if (t->right != tail) put(t->right);
    }
}


//=================================[Stack access]====================================    

void init_stack() {
    top = -1;
}

node* push(node* t) {
    stack[++top] = t;
    return t;
}

node* pop() {
    return stack[top--];
}

int is_stack_empty() {
    return (top == -1);
}


//=================================[Queue access]====================================    

void init_queue() {
    front = rear = 0;
}

node* put(node* t) {
    queue[rear] = t; rear = ++rear % MAX; return t;
}

node* get() {
    node* t = queue[front];
    front = ++front % MAX;
    return t;
}

int is_queue_empty() {
    return (front == rear);
}


//=================================[Utility]====================================    

int is_operator(int k) {
    return (k == '+' || k == '-' || k == '*' || k == '/');
}
void visit(node* t) {
    printf("%c ", t->key);
}
