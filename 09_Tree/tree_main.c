#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tree.h"

int main() {
    char post[256];
    int choice;

    init_stack();
    init_queue();
    init_tree();

    while (1) {
        printf("\n\nInput postfix expression -> ");
        gets_s(post, sizeof(post));

        if (*post == 'NULL') break;

        head->right = make_parse_tree(post);

        printf("\nChoose traversal method:\n");
        printf("1. Preorder (recursive)\n");
        printf("2. Preorder (non-recursive)\n");
        printf("3. Inorder (recursive)\n");
        printf("4. Inorder (non-recursive)\n");
        printf("5. Postorder (recursive)\n");
        printf("6. Postorder (non-recursive)\n");
        printf("7. Level-order\n");
        printf("0. Exit\n");
        printf("Choice -> ");
        scanf("%d", &choice);
        getchar();

        printf("\nTraversal result: ");
        switch (choice) {
            case 1: preorder_traverse(head->right); break;
            case 2: nr_preorder_traverse(head->right); break;
            case 3: inorder_traverse(head->right); break;
            case 4: nr_inorder_traverse(head->right); break;
            case 5: postorder_traverse(head->right); break;
            case 6: nr_postorder_traverse(head->right); break;
            case 7: levelorder_traverse(head->right); break;
            case 0: return 0;
            default: printf("Invalid choice.\n"); break;
        }
    }

    return 0;
}