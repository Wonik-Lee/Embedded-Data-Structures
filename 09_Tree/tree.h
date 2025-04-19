#ifndef TREE_H
#define TREE_H

#define MAX 100


typedef struct _node {
    int key;
    struct _node* left;
    struct _node* right;
} node;


extern node* head, * tail;
extern node* stack[MAX];
extern node* queue[MAX];
extern int top, front, rear;


// utilities
int is_operator(int k);
void visit(node* t);


// Stack access
void init_stack();
node* push(node* t);
node* pop();
int is_stack_empty();


// Queue access
void init_queue();
node* put(node* t);
node* get();
int is_queue_empty();


// Tree access
void init_tree();
node* make_parse_tree(char* p);


// preorder
void preorder_traverse(node* t);
void nr_preorder_traverse(node* t);


// inorder
void inorder_traverse(node* t);
void nr_inorder_traverse(node* t);


// postorder
void postorder_traverse(node* t);
void nr_postorder_traverse(node* t);


// levelorder
void levelorder_traverse(node* t);


#endif